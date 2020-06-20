# Ensemble Windows Registry

This is a simple wrapper for the Win32 Registry.

## How to use it?

First, we create an instance of `Registry` with a key of our program:

```c++
auto r = new Registry("SOME_KEY");
```

Next, we shall add an integer into the registry:

```c++
r->RegSetInt(true, "sample-integer", 101);
```

Then, we shall retrieve the integer:

```c++
r->RegGetInt(true, "sample-integer")
```