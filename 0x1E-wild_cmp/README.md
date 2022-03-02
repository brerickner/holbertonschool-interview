#  0x1E. Wild Compare

## 	:clipboard: **Requirements**
* **You are not allowed to use loops of any kind**
* Allowed editors: ```vi, vim, emacs```
* All your files will be compiled on __Ubuntu 14.04 LTS__
* Your programs and functions will be compiled with ```gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic```
* All your files should end with a *new line*

* A ```README.md``` file, at the *root* of the folder of the project is mandatory
* Your code should use the **Betty style**. It will be checked using _betty-style.pl_ and _betty-doc.pl_
* You are **not allowed** to use **global** or **static** variables
* No more than **5** functions per file
* You are **not allowed** to use the _standard library_.
* In the following examples, the ```main.c``` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own ```main.c``` files at compilation. Our ```main.c``` files might be different from the one shown in the examples
* The _prototypes_ of all your functions should be included in your header file called ```holberton.h```
* Don’t forget to push your _header_ file

##  :shipit: Mission
```Write a function that compares two strings and returns 1 if the strings can be considered identical, otherwise return 0.```  

**Prototype:**  
```C
int wildcmp(char *s1, char *s2);
```
* ```s2``` can contain the special character **'*'**.
* The special char **'*'** can replace any _string_ **(including an _empty string_)**

##  :test_tube: Testing!
Create a new file name ```main.c``` and make it, along with the other files, executable using the command ``` chmod +x``` and paste the contents from below into the ```main.c``` file:
```C
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = wildcmp("main.c", "*.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*a*i*n*.*c*");
    printf("%d\n", r);
    r = wildcmp("main.c", "main.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "ma********************************c");
    printf("%d\n", r);
    r = wildcmp("main.c", "*");
    printf("%d\n", r);
    r = wildcmp("main.c", "***");
    printf("%d\n", r);
    r = wildcmp("main.c", "m.*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "**.*c");
    printf("%d\n", r);
    r = wildcmp("main-main.c", "ma*in.c");
    printf("%d\n", r);
    r = wildcmp("main", "main*d");
    printf("%d\n", r);
    r = wildcmp("abc", "*b");
    printf("%d\n", r);
    return (0);
}
```

##  Compiling

```bash
$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
```

##  Executing Program
```bash
$ ./0-wildcmp 
```

##  Expected Output
```bash
1
1
1
1
1
1
1
0
1
1
0
0
```
