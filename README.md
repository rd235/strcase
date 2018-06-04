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

Strcase provides one inline function **strcase** and a macro **STRCASE**, both convert
a *string* in a uint64\_t integer value. Only the first 8 characters are significative.

Actually **STRCASE**:
* requires the string to be specified as comma separated characters,
* supports "strings" using only literals, digits and underscore.

Regardless from its limitations this macro library is quite useful to write switch statements
in C language using strings (almost) as if it were integers (as in the example above).
Although **STRCASE** needs commas between characters the string is still readable, and it
is simple to add cases or change the tags.

Given that I am going to use this in several projects of mine, I decided to publish it as a
tiny independent project.

Developer, Dear colleagues, I hope you'll enjoy it!

renzo, June 4 2018

## how to install strcase

Just put strcase.h where you need it and that's all, folks.

In case you are lazy and you like standard install methods and tools, I have added a trivial CMake support. 
The standard cmake install sequence applies:
```
$ cmake .
$ sudo make install
```
