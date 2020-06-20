/**
 * License: GPL 3.0. See LICENSE in root directory.
 * \date 2020/06/20
 */

#include <cstdio>

#include "../inc/registry.hpp"

using Ensemble::Registry;

int main()
{
    // Initialise:
    auto r = new Registry("Software\\Some\\Stuff");
    bool b;

    // Sample integer:
    long i = 101;
    b = r->RegSetInt(false, "sample-integer", i);
    printf("Sample integer (%ld) added? %s", i, b ? "Y" : "N");
    i = r->RegGetInt(false, "sample-integer");
    printf("Sample integer retrieved: %ld", i);

    delete r;

    return 0;
}
