/**
 * License: GPL 3.0. See LICENSE in root directory.
 * \date 2020/06/20
 */

#pragma once

#include <windef.h>

namespace Ensemble {

/**
 *
 */
class Registry
{
protected:

    HKEY* ghMachineKey = nullptr;

    HKEY* ghUserKey = nullptr;

    HKEY* ghMachineKeyRead = nullptr;

    LPDWORD gdwDisp = nullptr;

    char Data[255]{};

public:

    explicit
    Registry(LPCTSTR Key);

    ~Registry();

public:

    bool RegDelete(bool UseUserKey, LPCTSTR lptszName);

    bool RegSet(bool UseUserKey, LPCTSTR lptszName, LPBYTE lpData, DWORD dwSize);

    bool RegSetInt(bool UseUserKey, LPCTSTR lptszName, int Value = -1);

    bool RegSetAscii(bool UseUserKey, LPCTSTR lptszName, LPBYTE lpData, DWORD dwSize);

    long RegGet(bool UseUserKey, LPCTSTR lptszName, LPBYTE lpData, LPDWORD lpdwDataSize);

    int RegGetInt(bool UseUserKey, LPCTSTR lptszName, int defaultValue = -1);

    const char* RegGetAscii(bool UseUserKey, LPCTSTR lptszName);
};

} // namespace Ensemble
