# Ensemble Windows Registry

A simple [Win32 Registry](https://docs.microsoft.com/en-us/windows/win32/sysinfo/structure-of-the-registry) encapsulation.

## Usage

Include the `Registry` class.

```c++
#include <ensemble/registry.cpp>
using Ensemble::Registry;
```

We create an instance of `Registry` with a key representing our software.

```c++
Registry* registry = new Registry("Software\\Sample");
```

We can add an integer into the registry.

```c++
registry->RegSetInt(TRUE, "sample-integer", 101);
```

We can retrieve the integer.

```c++
int i = registry->RegGetInt(TRUE, "sample-integer");
```
