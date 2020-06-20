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
    auto k = "SOME_KEY";
    auto r = new Registry(k);
    bool b;

    // Sample integer:
    long i = 101;
    b = r->RegSetInt(true, "sample-integer", i);
    printf("Sample integer (%ld) added? %s", i, b ? "Y" : "N");
    i = r->RegGetInt(true, "sample-integer");
    printf("Sample integer retrieved: %ld", i);
}
