---
title: Move operations
layout: main
category: cpp
---

The goal of this exercise is to get some confidence with the so-called *special
member functions* of a class and in particular with move semantics.

## Exercise 1

Open the test program [`string.cpp`]({{site.exercises_repo}}/hands-on/cpp/string.cpp) and complete the existing code to:

* Complete the set of the special member functions so that `String` is copyable
  and movable

* Add `operator[]` (const and non-const) to access a character at a given
  position

* Add a `c_str()` member function to access the underlying C-style string

* Use a smart pointer instead of a raw pointer. Note that
  `std::unique/shared_ptr` and corresponding `make_unique/shared` support arrays

The commands to build and run the code are:

```shell
[student@esc ~]$ cd sesame23/hands-on/cpp
[student@esc cpp]$ g++ -Wall -Wextra -o string string.cpp
[student@esc cpp]$ ./string
```

## Exercise 2

Open the program `test_tracking.cpp` and extend the code to use the class
`Tracking` in other situations, to verify when the class special member
functions are used.
