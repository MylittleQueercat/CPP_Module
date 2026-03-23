# 🔷 C++ Modules 00–09

![Score](https://img.shields.io/badge/Score-100%2F100-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-pink)
![42](https://img.shields.io/badge/42-Project-black)

## Module 00 — Namespaces, Classes, Member Functions, stdio streams

- **Namespace**: group identifiers to avoid name collisions (`namespace Foo { ... }`, `Foo::bar`)
- **Class**: `class` vs `struct` (default access: `private` vs `public`), member variables and methods
- **Constructor / Destructor**: `ClassName()`, `~ClassName()`, called automatically on creation/destruction
- **Accessor (getter/setter)**: encapsulation pattern — keep members `private`, expose via public methods
- **`this` pointer**: pointer to the current object instance inside a member function
- **Initialization list**: `ClassName(int x) : _x(x) {}` — preferred way to initialize members
- **`const` member function**: `void foo() const` — guarantees the method does not modify the object
- **`std::cout` / `std::cin`**: C++ I/O streams replacing `printf`/`scanf`

---

## Module 01 — Memory Allocation, References, Pointers to Members, File Streams

- **Stack vs heap allocation**: `new` / `delete` for single objects, `new[]` / `delete[]` for arrays
- **Reference**: `int &ref = x` — an alias, cannot be null, cannot be reseated
- **Pointer vs reference**: pointers can be null and reassigned; references cannot
- **Pointer to member function**: `void (Foo::*fp)() = &Foo::bar; (obj.*fp)();`
- **`std::ifstream` / `std::ofstream`**: file reading and writing streams
- **RAII preview**: objects managing resources (file, memory) in constructor/destructor

---

## Module 02 — Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Form

- **Orthodox Canonical Form (OCF)**: every class must implement 4 things:
  - Default constructor
  - Copy constructor: `Foo(const Foo &other)`
  - Copy assignment operator: `Foo &operator=(const Foo &other)`
  - Destructor
- **Operator overloading**: redefine operators for custom types (`+`, `-`, `*`, `==`, `<<`, etc.)
- **Fixed-point numbers**: represent real numbers as integers with a fixed fractional bit count — the subject's concrete use case for OCF and operator overloading
- **`static` member**: shared across all instances of a class (`static int _count`)

---

## Module 03 — Inheritance

- **Inheritance**: `class B : public A` — B inherits all public/protected members of A
- **Access specifiers in inheritance**: `public`, `protected`, `private` inheritance change how members are exposed
- **Constructor chaining**: derived class constructors must explicitly call the base constructor in the init list
- **`protected`**: accessible within the class and its subclasses, but not from outside
- **Diamond problem (preview)**: when a class inherits from two classes that share a common base — leads to ambiguity without virtual inheritance

---

## Module 04 — Subtype Polymorphism, Abstract Classes, Interfaces

- **`virtual` function**: enables runtime polymorphism — the correct derived method is called through a base pointer
- **`override`**: keyword to explicitly mark a derived method as overriding a virtual one (catches typos)
- **Pure virtual function**: `virtual void foo() = 0` — makes the class **abstract**, cannot be instantiated
- **Abstract class / Interface**: a class with only pure virtual functions acts as an interface
- **Virtual destructor**: always declare the destructor `virtual` in a polymorphic base class to avoid partial destruction
- **`dynamic_cast`**: safe downcast in a polymorphic hierarchy (returns `nullptr` on failure for pointers)
- **Deep copy**: when a class holds a pointer, the copy constructor and assignment operator must copy the pointed-to data, not just the pointer

---

## Module 05 — Exceptions

- **`try` / `throw` / `catch`**: basic exception handling flow
- **Custom exception classes**: inherit from `std::exception`, override `what()` returning a `const char *`
- **`std::exception`**: base class for all standard exceptions
- **Exception safety**: ensure no resource leak when an exception is thrown (RAII helps here)
- **Re-throwing**: `throw;` inside a catch block re-throws the current exception
- **Nested exception classes**: defining exception types inside the class that throws them (common 42 pattern)

---

## Module 06 — C++ Casts

- **`static_cast`**: compile-time cast, safe for related types (int ↔ float, upcasts, explicit conversions)
- **`dynamic_cast`**: runtime cast for polymorphic types; returns `nullptr` (pointer) or throws (reference) on failure
- **`reinterpret_cast`**: raw bit reinterpretation — dangerous, used for low-level pointer/integer conversions
- **`const_cast`**: add or remove `const` qualifier — only valid use is removing `const` from a pointer that was not originally const
- **Why avoid C-style casts**: `(int)x` does no type checking; C++ casts are explicit about their intent and safer

---

## Module 07 — Templates

- **Function template**: `template <typename T> T max(T a, T b)` — compiler generates a version for each type used
- **Class template**: `template <typename T> class Array { ... }` — generic containers
- **Template instantiation**: implicit (compiler deduces type) or explicit (`max<int>(a, b)`)
- **Template specialization**: provide a specific implementation for a particular type
- **`typename` vs `class`**: interchangeable in template parameter lists
- **Limitations**: template code must be in the header (or included), not a separate `.cpp`

---

## Module 08 — Templated Containers, Iterators, Algorithms

- **STL containers**: `std::vector`, `std::list`, `std::map`, `std::stack`, `std::deque`
- **Iterators**: objects that abstract traversal — `begin()`, `end()`, `++it`, `*it`
- **Iterator categories**: input, output, forward, bidirectional, random access
- **`std::find` / `std::find_if`**: search algorithms from `<algorithm>`
- **Range-based patterns**: writing functions that accept any container via iterators
- **`typename T::iterator`**: how to declare an iterator type inside a template function

---

## Module 09 — STL

- **`std::map`**: ordered associative container (key-value, sorted by key, O(log n) access)
- **`std::vector`**: dynamic array (O(1) random access, O(n) insert/remove at middle)
- **`std::stack`**: LIFO adapter (backed by `deque` by default)
- **`std::list`**: doubly-linked list (O(1) insert/remove anywhere, no random access)
- **Ford-Johnson algorithm (merge-insert sort)**: the subject's sorting algorithm — minimizes the number of comparisons; uses pairs and `std::deque` / `std::list` to sort with the fewest possible comparisons
- **Container choice matters**: the module requires implementing the same algorithm with two different containers and benchmarking them — understanding each container's complexity is essential
- **`std::pair`**: `std::make_pair(a, b)`, `pair.first`, `pair.second`
