Wednesday, May 31: Sorting
--------------------------

1. Write a function `void printArray(int *arr, int size)` that outputs all of the integers in the passed array.
2. Write a function `int * sort(int *arr, int size)` that returns a `new`-allocated copy of `arr` in sorted order (`{3, 1, 2} -> {1, 2, 3}`).
3. As the size `N` increases, how would you characterize the amount of time your `sort` function takes? That is, does it look like it's proportional to `N`, `N^2`, `N^3`, or something else? Determine this without measuring.

Tuesday, June 6: "Fun" with C Strings
-------------------------------------

See [strings.md](strings.md) for an overview of C/C++ strings.

Do the following **without** using C++ `std::string`s:

1. Write a function `int strLength(const char *s)` that counts the number of
   characters in a string. (hint: remember that a C string ends at the 0)
2. Write a function `void strTruncate(char *s, int n)` that truncates the passed
   string to the given length. (hint: this is a single line of code)
3. Write a function `void strCapitalize(char *s)` that capitalizes the passed
   string's ASCII lowercase characters to their uppercase equivalents. (hint:
   `man ascii`)
4. Write a function `void strCopy(char *s1, const char *s2)` that makes `s1`
   contain the same characters as `s2`. Put a comment above this function
   explaining what is horribly, horribly wrong about it.
5. Write a function `void strAppend(char *s1, const char *s2)` that appends
   the contents of `s2` to `s1`. Put a comment above this function explaining
   what is horribly, horribly wrong about it.
6. Write a program `int main(int argc, char **argv)` that does the following:
   - Checks that `argc >= 2`, and exits without doing anything fun if it isn't
   - Copies `argv[1]` (the first argument passed to your program!) into a local
     `char name[10]`
   - Truncates `name` to at most six characters
   - Stores a greeting of the form "hello, name!" into a `char greeting[40]`
   - Outputs in one of two ways:
     - If the name is exactly three characters long, shouts the greeting in all
       uppercase letters using `printf("%s\n", greeting)`
     - Otherwise, just greets normally: `printf("%s\n", greeting)`
