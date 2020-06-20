/**
 * License: GPL 3.0. See LICENSE in root directory.
 * \date 2020/06/20
 */

#include <afxres.h>

#include "../inc/registry.hpp"

namespace Ensemble {

Registry::Registry(LPCTSTR Key)
{
    RegCreateKeyEx(
        HKEY_CURRENT_USER,
        Key,
        0,
        nullptr,
        REG_OPTION_NON_VOLATILE,
        KEY_ALL_ACCESS,
        nullptr,
        ghUserKey,
        gdwDisp);

    RegCreateKeyEx(
        HKEY_LOCAL_MACHINE,
        Key,
        0,
        nullptr,
        REG_OPTION_NON_VOLATILE,
        KEY_ALL_ACCESS,
        nullptr,
        ghMachineKey,
        gdwDisp);

    RegCreateKeyEx(
        HKEY_LOCAL_MACHINE,
        Key,
        0,
        nullptr,
        REG_OPTION_NON_VOLATILE,
        KEY_QUERY_VALUE,
        nullptr,
        ghMachineKeyRead,
        gdwDisp);
}

Registry::~Registry()
{
    if (ghUserKey != nullptr)
    {
        RegCloseKey(*ghUserKey);
        ghUserKey = nullptr;
    }
    if (ghMachineKey != nullptr)
    {
        RegCloseKey(*ghMachineKey);
        ghMachineKey = nullptr;
    }
    if (ghMachineKeyRead != nullptr)
    {
        RegCloseKey(*ghMachineKeyRead);
        ghMachineKeyRead = nullptr;
    }
}

bool Registry::RegDelete(bool UseUserKey, LPCTSTR lptszName)
{
    auto result = RegDeleteValue(
        UseUserKey ? *ghUserKey : *ghMachineKey,
        lptszName);

    return ERROR_SUCCESS == result;
}

bool Registry::RegSet(bool UseUserKey, LPCTSTR lptszName, LPBYTE lpData, DWORD dwSize)
{
    auto result = RegSetValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKey,
        lptszName,
        0,
        REG_DWORD,
        lpData,
        dwSize);

    return ERROR_SUCCESS == result;
}

bool Registry::RegSetInt(bool UseUserKey, LPCTSTR lptszName, int Value)
{
    auto result = RegSetValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKey,
        lptszName,
        0,
        REG_DWORD,
        (LPBYTE)&Value,
        sizeof(Value));

    return ERROR_SUCCESS == result;
}

bool Registry::RegSetAscii(bool UseUserKey, LPCTSTR lptszName, LPBYTE lpData, DWORD dwSize)
{
    auto result = RegSetValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKey,
        lptszName,
        0,
        REG_SZ,
        lpData,
        dwSize);

    return ERROR_SUCCESS == result;
}

const char* Registry::RegGetAscii(bool UseUserKey, LPCTSTR lptszName)
{
    DWORD dwType = REG_SZ;
    DWORD dwSize = sizeof(Data);

    auto result = RegQueryValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKeyRead,
        lptszName,
        nullptr,
        &dwType,
        (LPBYTE)Data,
        &dwSize);

    return ERROR_SUCCESS == result ? Data : nullptr;
}

long Registry::RegGet(bool UseUserKey, LPCTSTR lptszName, LPBYTE lpData, LPDWORD lpdwDataSize)
{
    auto result = RegQueryValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKeyRead,
        lptszName,
        nullptr,
        lpdwDataSize,
        lpData,
        lpdwDataSize);

    return ERROR_SUCCESS == result;
}

int Registry::RegGetInt(bool UseUserKey, LPCTSTR lptszName, int defaultValue)
{
    int value = 0;
    DWORD cbData = sizeof(value);
    DWORD dwType = REG_DWORD;
    
    auto result = RegQueryValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKeyRead,
        lptszName,
        nullptr,
        &dwType,
        (LPBYTE)value,
        &cbData);

    return ERROR_SUCCESS == result ? value : defaultValue;
}

} // namespace Ensemble
