/* License: MIT. See LICENSE in root directory. */

/**
 * \date 2020/06/27
 */

#include <afxres.h>

#include <ensemble/registry.hpp>

namespace Ensemble {

Registry::Registry(LPCTSTR Key)
{
    RegCreateKeyEx(
        HKEY_CURRENT_USER,
        Key,
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_ALL_ACCESS,
        NULL,
        ghUserKey,
        &gdwDisp);

    RegCreateKeyEx(
        HKEY_LOCAL_MACHINE,
        Key,
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_ALL_ACCESS,
        NULL,
        ghMachineKey,
        &gdwDisp);

    RegCreateKeyEx(
        HKEY_LOCAL_MACHINE,
        Key,
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_QUERY_VALUE,
        NULL,
        ghMachineKeyRead,
        &gdwDisp);
}

Registry::~Registry()
{
    if (ghUserKey != NULL)
    {
        RegCloseKey(*ghUserKey);
        ghUserKey = NULL;
    }
    if (ghMachineKey != NULL)
    {
        RegCloseKey(*ghMachineKey);
        ghMachineKey = NULL;
    }
    if (ghMachineKeyRead != NULL)
    {
        RegCloseKey(*ghMachineKeyRead);
        ghMachineKeyRead = NULL;
    }
}

BOOL Registry::RegDelete(BOOL UseUserKey, LPCTSTR lptszName)
{
    DWORD result = RegDeleteValue(
        UseUserKey ? *ghUserKey : *ghMachineKey,
        lptszName);

    return ERROR_SUCCESS == result;
}

BOOL Registry::RegSet(BOOL UseUserKey, LPCTSTR lptszName, LPBYTE lpData, DWORD dwSize)
{
    DWORD result = RegSetValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKey,
        lptszName,
        0,
        REG_DWORD,
        lpData,
        dwSize);

    return ERROR_SUCCESS == result;
}

BOOL Registry::RegSetInt(BOOL UseUserKey, LPCTSTR lptszName, INT Value)
{
    DWORD result = RegSetValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKey,
        lptszName,
        0,
        REG_DWORD,
        (LPBYTE)Value,
        sizeof(Value));

    return ERROR_SUCCESS == result;
}

BOOL Registry::RegSetAscii(BOOL UseUserKey, LPCTSTR lptszName, LPBYTE lpData, DWORD dwSize)
{
    DWORD result = RegSetValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKey,
        lptszName,
        0,
        REG_SZ,
        lpData,
        dwSize);

    return ERROR_SUCCESS == result;
}

LPCTSTR Registry::RegGetAscii(BOOL UseUserKey, LPCTSTR lptszName)
{
    DWORD dwType = REG_SZ;
    DWORD dwSize = sizeof(Data);

    DWORD result = RegQueryValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKeyRead,
        lptszName,
        NULL,
        &dwType,
        (LPBYTE)Data,
        &dwSize);

    return ERROR_SUCCESS == result ? Data : NULL;
}

LONG Registry::RegGet(BOOL UseUserKey, LPCTSTR lptszName, LPBYTE lpData, LPDWORD lpdwDataSize)
{
    DWORD result = RegQueryValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKeyRead,
        lptszName,
        NULL,
        lpdwDataSize,
        lpData,
        lpdwDataSize);

    return ERROR_SUCCESS == result;
}

INT Registry::RegGetInt(BOOL UseUserKey, LPCTSTR lptszName, INT defaultValue)
{
    INT value = 0;
    DWORD cbData = sizeof(value);
    DWORD dwType = REG_DWORD;
    
    DWORD result = RegQueryValueEx(
        UseUserKey ? *ghUserKey : *ghMachineKeyRead,
        lptszName,
        NULL,
        &dwType,
        (LPBYTE)value,
        &cbData);

    return ERROR_SUCCESS == result ? value : defaultValue;
}

} // namespace Ensemble
