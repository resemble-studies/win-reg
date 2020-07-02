/* License: MIT. See LICENSE in root directory. */

/**
 * \date 2020/07/03
 */

#pragma once

#include <windef.h>

namespace Ensemble
{

class Registry
{
protected:

    PHKEY ghMachineKey;

    PHKEY ghUserKey;

    PHKEY ghMachineKeyRead;

    DWORD gdwDisp;

    CHAR Data[255];

public:

    explicit
    Registry(LPCTSTR Key);

    ~Registry();

public:

    BOOL RegDelete(BOOL UseUserKey, LPCTSTR lptszName);

    BOOL RegSet(BOOL UseUserKey, LPCTSTR lptszName, LPBYTE lpData, DWORD dwSize);

    BOOL RegSetInt(BOOL UseUserKey, LPCTSTR lptszName, INT Value = -1);

    BOOL RegSetAscii(BOOL UseUserKey, LPCTSTR lptszName, LPBYTE lpData, DWORD dwSize);

    LONG RegGet(BOOL UseUserKey, LPCTSTR lptszName, LPBYTE lpData, LPDWORD lpdwDataSize);

    INT RegGetInt(BOOL UseUserKey, LPCTSTR lptszName, INT defaultValue = -1);

    LPCTSTR RegGetAscii(BOOL UseUserKey, LPCTSTR lptszName);
};

} // namespace Ensemble
