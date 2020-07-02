/* License: MIT. See LICENSE in root directory. */

/**
 * \date 2020/07/03
 */

#include <cstdio>

#include <ensemble/registry.hpp>
using Ensemble::Registry;

int main()
{
    // Initialise:
    Registry* r = new Registry("Software\\Sample");
    BOOL b;

    // Sample string:
    CHAR c[200];
    strcpy(c, "some test");
    DWORD l = strlen((LPCTSTR)c);
    b = r->RegSetAscii(false, "sample-ascii", LPBYTE(c), l + 1);

    // Sample integer:
    DWORD i = 101;
    b = r->RegSetInt(FALSE, "sample-integer", i);
    printf("Sample integer (%ld) added? %s", i, b ? "Y" : "N");
    i = r->RegGetInt(FALSE, "sample-integer");
    printf("Sample integer retrieved: %ld", i);
}
