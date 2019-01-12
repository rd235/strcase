# strcase
Multiway branch (switch) for short strings in C (in one header file)

```C
#include <stdio.h>
#include <strcase.h>

int main(int argc, char * argv[]) {
  printf("%llx %llx \n", strcase("ciao"), STRCASE(c,i,a,o));
  printf("%llx %llx \n", strcase("verylong"), STRCASE(v,e,r,y,l,o,n,g));
  printf("%llx %llx \n", strcase("far_toolong"), STRCASE(f,a,r,_,t,o,o,l,o,n,g));
  printf("%llx %llx \n", strcase("far_tool"), STRCASE(f,a,r,_,t,o,o,l));
  for (argv++; *argv; argv++) {
    switch(strcase(*argv)) {
      case STRCASE(o,n,e): printf("1\n"); break;
      case STRCASE(t,w,o): printf("2\n"); break;
      case STRCASE(t,h,r,e,e): printf("3\n"); break;
      case STRCASE(f,o,r,t,y,f,o,u,r): printf("44\n"); break;
      case STRCASE(f,o,r,t,y,t,w,o): printf("42\n"); break;
    }
  }
}
```

`strcase` provides one inline function **strcase**, **strcase\_tolower** and a macro **STRCASE**, both convert
a *string* in a `uint64_t` integer value. Only the *first 8 characters* are significative.

`strcase_tolower` works like `strcase` but it converts uppercase letters as if they were lowercase.

`strcase` or `strcase_tolower` can be used in the expression of a switch statement to convert a string
to an integer type, `STRCASE` generates at compile time the integer constants that can be used for the `case`
stanzas of the switch.

Actually **STRCASE**:

* requires the string to be specified as comma separated characters,
* supports "strings" using only literals, digits and underscore. Other symbols can appear using their name, as in:
`STRCASE(slash,e,t,c)`

Regardless of its limitations this macro library is quite useful to write switch statements
in C language using strings (almost) as if it were integers (as in the example above).
Although **STRCASE** needs commas between characters the string is still readable, and it
is simple to add cases or change the tags. This is a simple example:
```C
int yes_or_not(const char *s) {
  switch (strcase_tolower(s)) {
    case STRCASE(y,e,s):
    case STRCASE(y):
        return 1;
    case STRCASE(n,o):
    case STRCASE(n):
        return 0:
    default:
        return -1;
  }
}
```

Given that I am going to use this in several projects of mine, I decided to publish it as a
tiny independent project.

renzo, June 4 2018

## how to install strcase

Just put strcase.h where you need it and that's all, folks.

In case you are lazy and you like standard install methods and tools, I have added a trivial CMake support. 
The standard cmake install sequence applies:
```
$ cmake .
$ sudo make install
```
