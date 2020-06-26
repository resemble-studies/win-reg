/**
 * License: MIT. See LICENSE in root directory.
 * \date 2020/06/20
 */

#include <cstdio>

#include <ensemble/registry.hpp>

using Ensemble::Registry;

int main()
{
    // Initialise:
    Registry* r = new Registry("Software\\Sample");
    bool b;

    // Sample string:
    char c[200];
    strcpy(c, "some test");
    DWORD l = strlen((const char*)c);
    b = r->RegSetAscii(false, "sample-ascii", LPBYTE(c), l + 1);

    // Sample integer:
    DWORD i = 101;
    b = r->RegSetInt(false, "sample-integer", i);
    printf("Sample integer (%ld) added? %s", i, b ? "Y" : "N");
    i = r->RegGetInt(false, "sample-integer");
    printf("Sample integer retrieved: %ld", i);
}
