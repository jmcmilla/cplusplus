## C Strings

In C, a string is an array of `char` values terminated with a 0 (often referred
to as a "null byte", "NUL", or `'\0'`). Each `char` value generally represents
a single character in the ASCII encoding (see `man ascii`).

```cpp
// All of the following create an array of 7 bytes representing the string
// "foobar" in ASCII.
char s[] = { 102, 111, 111, 98, 97, 114, 0 };
char s[] = { 'f', 'o', 'o', 'b', 'a', 'r', 0 };
char s[] = "foobar";
```

As they are just arrays, these kinds of strings have all the limitations of
arrays. Most importantly, adding more characters to a string is difficult to do
safely and correctly, despite this often being a desirable operation.

### C String Manipulation

The C `<string.h>` library includes a number of awful string manipulation
functions. For the most part, these functions are completely unsafe due to
buffer overflow issues (`strcat`), take awkward parameters (`strncat`), or do
not behave as expected (`strncpy`) in terms of consistently populating the end
null byte. Be aware that these exist and may be useful in specific cases or be
present in others' code, but know that C++ strings offer much clearer and safer
string manipulation functionality.

The most useful C string manipulation function is `<stdio.h>`'s `snprintf`:
```cpp
int snprintf(char *s, size_t size, const char *format, ...);
```

This function works like `printf`, but for fixed-size C strings. It truncates
rather than overflowing the buffer, and always places a 0 at the end of the
string.

```cpp
int x = 10;
double f = 20.0;
char s[64] = "";
// Format some variables into a buffer
snprintf(s, sizeof(s), "some numbers: %d, %g", x, f);

// Safely concatenate two strings
snprintf(s, sizeof(s), "%s%s", str1, str2);
```

### C String Constants

C string constants are declared with very similar syntax, but have somewhat
different semantics.

```cpp
char s[] = "foobar";       // Local array containing f, o, o, b, a, r, 0
const char *s2 = "foobar"; // Pointer to string constant Somewhere In Memory
const char *s3 = s;        // Pointer to the local array
printf("%d\n", 10);        // The printf format string is a string constant!
```

String constants are of type `const char *`, and are automatically placed in a
read-only section of your program's memory.

## C++ Strings

C++ adds the `string` class, available in `#include <string>`. These are more
flexible than C strings; most importantly, they automatically resize to fit
whatever text is assigned or appended to them.

C++ strings are designed to be as interoperable with C strings as possible. C
strings can be assigned or appended to them, and the `.c_str()` method returns
a `const char *` that can be used to pass the `string`'s contents along to a
function that expects a C string. (Be careful, though: this `const char *` is
only valid until you do something to modify the `string`.)

```cpp
std::string greeting = "Hello";
std::string pause = ", ";
const char *name = "Dave";

greeting += pause;
greeting += name;

printf("%s\n", greeting.c_str());
```

### C++ String Manipulation

The most interesting methods:

```cpp
a += b;    // Append a C or C++ string, or a single char
a.size();  // Determine the number of chars in the string
a.clear(); // Empty the string
a[i];      // Get the char at index i
a.c_str(); // Get a const char * for use with functions that want a C string
```

### Why Bother With C Strings?

Unfortunately, there are an enormous number of libraries that are written in C,
and very few in C++. When using such libraries, the lingua franca is C strings.
In general, you can use `std::string` where possible within your application,
and convert to and from C strings when necessary:

```cpp
#include <libwhatever.h>

std::string name = getName();

// Send to and receive from libwhatever using C strings
whatever_send(name.c_str());
char responseBuffer[512] = "";
whatever_recv(responseBuffer, sizeof(responseBuffer));

// Convert the response to a C++ string so we can manipulate it more easily
std::string response(responseBuffer);
response += " (from libwhatever)";
doTheThing(response);
```

Within the SRS codebase, `char` arrays are often used to map fixed-width
database fields to class member variables:

```sql
CREATE TABLE foo (
  bar INTEGER,
  baz VARCHAR(10)
);
```

```cpp
class rxFoo {
public:
  int Bar;
  char Baz[11];
};
```

They are also used to store sensitive data that must be securely cleared, as
the underlying buffer used by an `std::string` can be reallocated and reused in
undefined, unpredictable ways that can leave copies of such sensitive data in
memory.

## Bonus Discussion: Other String Types

Both of these string types operate on single-byte characters, allowing only 255
different values (excluding 0). This range is entirely inadequate to accomodate
modern needs such as international character sets and emojis.

C's `wchar_t *` and C++'s `wstring` add an additional byte per character, thus
missing the point entirely. Even 65,535 values is not enough to represent all
the interesting characters: Unicode, the industry standard character set, now
contains 128,237 of them! In other words, these types are larger, more
complex, and incompatible with most libraries, but don't solve any real
problem.

GUI libraries such as Qt and wxWidgets, as well as internationalization
libraries such as ICU, provide full-featured string types that can handle the
entire range of Unicode characters. These are very helpful within their own
ecosystems, but come at the expense of having a third (or more!) string type
in a single program. More string types means even more conversions between the
various types to integrate various parts of the program and libraries.

If your program's string manipulation is fairly straightforward, the now-common
[UTF-8](https://en.wikipedia.org/wiki/UTF-8) encoding cleverly masks a lot of
problems by defining each Unicode code point as a series of individual bytes.
ASCII text is unaltered in this encoding. This allows storage and minimal
manipulation (such as appending ASCII text) in C or C++ string format to pass
international characters through unmangled, even if the program doesn't exactly
recognize them.
