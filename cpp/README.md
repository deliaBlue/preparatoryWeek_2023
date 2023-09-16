# Introducing `C` and `C ++`

This file was built under the assumption that you already knew `C`. This
is why it contains comparisons to `C` and also works with it. Knowing now
that you do not, you can focus only on the `C++` explanation but keep in
mind that you will use `C` in a couple of subjects and that understanding it
is going to provide you a huge knowledge of what is going on in a deeper level.

> DISCLAIMER: Here we will cover the basics of `C` and `C++`.  If you see 
something missing, don't hesitate on writing down an issue with small 
description and we will make it up to you. If you have any doubt, or need 
help, feel free to contact us!

## Things to see here

1. [Introduction](#introduction)
2. [Basic Syntax](#basic-syntax)
3. [Data Types](#data-types)
   - [Primitive Data Types](#primitive-data-types)
   - [Derived Data Types](#derived-data-types)
      - [Arrays](#arrays)
      - [Vectors](#vectors)
      - [Sets](#sets)
      - [Strings](#strings)
   - [Derived Data Types Functions in C++](#derived-data-type-functions-in-c++)
4. [Basic Structures](#basic-structures)
    - [Conditionals](#conditionals)
        - [If statement](#if-statement)
        - [Else statement](#else-statement)
        - [Else if statement](#else-if-statement)
    - [Loops](#loops)
        - [For Loops](#for-loops)
        - [While Loops](#while-loops)
        - [do...while Loops](#do-while-loops)
5. [Functions](#functions)
    - [The `void` Function](#the-void-function)
    - [The Function Scope](#the-function-scope)
        - [Case 1: Before the `main()` Function](#case-1-before-the-main-function)
        - [Case 2: Inside Both Functions](#case-2-inside-both-functions)
        - [Case 3: After the `main()` Function](#case-3-after-the-main-function)
6. [Extra Resources](#extra-resources)

## Introduction

Wondering whether `C` is easier than `C++` is one of the most frequently 
questions along with _"Is `C` or `C++` worth the learning time?"_

The answer clearly is

<p align="center">Absolutely YES.</p>


Prior to starting which of the two languages is easier (if there's really a 
definitive answer to that), we must start by the basics and take a look at some
of the main differences between `C` and `C++`. Mind that they  are on the top 3
most used languages (even if `C` is getting more unpopular, `C++` is ascending in the 
ranking).

Programmers, as you might have heard, are very hilarious and love to make good
quality humor. That's why, when Bjarne Stroustrup had to name the programming 
language he just created, which took as it's base `C`, decide to name it `C++`.
In `C`, when you add to an integer a double plus sign (`++`) you are
incrementing in value by one, and provided that `C++` was design to include and
increment of `C` capabilities, our friend Bjarne could not resist the 
temptation. A similar idea was behind the naming of `C#` when Microsoft made it.
The main difference between both languages is which type of programming language
they are. `C` is a procedural programming language (stress on functions), while 
`C++` is a Object-oriented programming language (stress on object creation). To
have a deeper view of these concepts , the main characteristics and differences
between both languages, you can check [this article][Differences1] or 
[this one][Differences2].


## Basic Syntax

`C` and `C++` share a lot of the syntax. For this reason, the most basic syntax
will be listed together and afterwards, a couple of `C` and `C++` directions
will be listed separately.

> NOTE: Some of the concepts will be explained further on the document. Do not
worry if there's a concept you do not understand at first.

- All statements besides the header must end with a semicolon (`;`).
- **Characters** are written in single-quotes, **strings** in double-quotes.
- All variables must be **declared** prior to usage.
- If there are several `#include`, state them in alphabetical order.
- The `main()` function is mandatory and returns `0`.
- The body of any function, conditional or loop goes within curly brackets
(`{ }`).
- The code must use indentations.


### `C` Specific Syntax

- To use input/output related functions, you must include at the top of the
script `#include <stdio.h>`.
- To print to the standard output use the function
`printf("formatToPrint\n", thingToPrint);`.


### `C++` Specific Syntax

- To use input/output related functions, you must include at the top of the
script `#include <iostream>`.
- To print to the standard output use `cout << thingToPrint << endl;`.
- After all the `#include` statements, add `using namespace std;`, otherwise,
you must add `std::` to all functions and some declarations.

## Data Types


Unlike in `Python`, when you want to create a variable in `C` and `C++`, you
first have to **declare** it. To **declare** a variable means to state the
variable name and its **data type**. Data types in `C` and `C++` can be
described as the _characteristics of the data stored into a variable_. Another
way to see it is that data types are means to identify the type of data and
associated operations for handling it. In order to **declare** a variable, we
will use the following syntax:

<p align="center"><i>dataType var_name;</i></p>

Once a variable is **declared** it needs to be **initialized**, or in other
words, an initial value must be provided. You can either **initialize** the
variable when you declare it using

<p align="center"><i>dataType var_name = value;</i></p>

or you can **initialize** it afterwards

<p align="center"><i>dataType var_name;</i></p>
<p align="center"><i>var_name = value;</i></p>

One thing you must take into account, is that not all `Python` _"data types"_
are embedded directly into the `C` and `C++` language itself [^datatypes]; 
this implies that to use some data types, you will need to **include** specific
**libraries**.

### Primitive Data Types

Primitive data types are build-in and can be directly used by the user to
**declare** variables. They are the most basic data types, and are used to
represent simple values.  

The following table summarizes the 5 primitive data types in `C` followed by a
small code showing how to **declare** a variable, and which format specifier
needs to be printed to the standard output.  


<table>
<tr>
<th>Integers</th><th>Floats</th><th>Doubles</th><th>Characters</th><th>Void</th>
</tr>
<tr><td>

We will use the integer data type to store whole numbers without decimal
values. Octal and hexadecimal values can also be stored in this data type.

</td>
<td>

We will use the float data type to store floating-point values with single
precision. In other words, to store numbers with at least 6 decimal digits.

</td>
<td>

We will use the double data type to store floating-point values with double
precision. In other words, to store numbers with at least 15 decimal digits. 

</td>
<td>

We will use the character data type to store a single ASCII character. They are
always inside single quotes.

</td>
<td>

We will use the void data type to specify that no value is present. It has no
values nor operations. The void data type, is used in multiple ways, as
function return type, function arguments as void, and pointers to void.

</td></tr>
<tr><td>

```c
#include <stdio.h>

int main() {
  int x = 3;
  int y = -3;

  printf("x + y = %d\n", x + y);
  return 0;
}
```

</td>
<td>

```c
#include <stdio.h>

int main() {
  float x = 11.5;
  float y = 3.7;

  printf("x / y = %f\n", x / y);
  return 0;
}
```

</td>
<td>

```c
#include <stdio.h>

int main() {
  double x = 11.5;
  double y = 3.7;

  printf("x / y = %lf\n", x / y);
  return 0;
}
```

</td>
<td>

```c
#include <stdio.h>

int main() {

  char x = '?';
  int y = 30;

  printf("He said: %c\n", x);
  printf("She replied: %c\n", x - y);
  
return 0;
}
```

</td>
<td>

```c
#include <stdio.h>

void main() {

  char x = '?';
  int y = 30;

  printf("He said: %c\n", x);
  printf("She replied: %c\n", x - y);
}
```

</td></tr>
</table>

As for `C++`, besides these 5 primitive types, it includes two extra ones:



<table>
<tr>
<th>Booleans</th><th>Wide Characters</th></tr>
<tr><td>

We will use the boolean data type to store logical values. That is, a boolean
variable can either have `true` or `false` as its value.

</td>
<td>

We will use the character data type to store a single UNICODE character.

</td></tr>
<tr><td>

```cpp
#include <iostream>
using namespace std;

int main() {
  bool vim = true;
  
  if (vim){
    cout << "You use vim?\nYou rule!" << endl;
  }
  
  else{
    cout << "What are you waiting for?" << endl;
  }

  return 0;
}
```

</td>
<td>

Code complexity is too high.
Nothing to see here.

</td></tr>
</table>

> NOTE: When `C` was created, no boolean data type was thought to be needed as
the integer `0` could be used as the boolean `false` and `1` as the boolean
`true`. Some time ago, they decided to include this data type and nowadays,
you can use it as you do in `C++` if you add the header `#include <stdbool.h>`
at the top of your `C` script.

<blockquote>
<details>
  <summary>Data Types Modifiers</summary>
  <br>

Some primitive data types can be modified regarding its size and the values it
can hold. In each data type name, you have a linked table with the space of
memory and range of value for each modifier.

[**Integer**][tab_int]  

**Integers** can be modified with one or more of the keywords `signed`,
`unsigned`, `short` and `long`. Note that by default, **integers** are
`signed` and therefore, we do not add it to the name.

The format specifier in `C` for the different modifiers are:

- `short int` -> `%hd`
- `unsigned short int` -> `%hu`
- `unsiged int` -> `%u`
- `long int` -> `%ld`
- `unsigned long int` -> `%lu`
- `long long int` -> `%lld`
- `unsigned long long int` -> `%llu`


[**Characters**][tab_char]  

**Characters** can also be defined with their number in the ASCII table. This
alternative notation allow us to modify them with the keywords `signed` and
`unsigned`. Both **character** types have the same format specifier (`%c`) in
`C`.


[**Doubles**][tab_double]  

**Doubles** can only be modified using the keyword `long`. In `C`,
`long double` have as format specifier `%Lf`.


</details>
</blockquote>

### Derived Data Types

As the name suggest, derived data types are the ones that derived from the
primitive data types. Both `C` and `C++` have four main different derived data
types: **arrays**, **functions**, **pointers** and **references**.
From these, only **arrays** will be covered in this section.
[**Functions**](#functions) have their own section bellow and **pointers**
and **references** are explained on their own file.

In addition to **arrays**, we will also cover **strings** and a couple of
`C++` containers.

#### Arrays

An **array** is a <u>fixed-size</u> sequential collection of elements of the
<u>same type</u>. **Arrays** are a static data type, _i.e._, they are
allocated in memory at the compile time.

As with any other variable, **arrays** must be **declared** before being able to
use it. To do so, you must specify the data type of the elements the **array**
will hold, the name of the **array** and its size.


<p align="center"><i>dataType array_name [arraySize];</i></p>

Recall that after **declaring** a variable, you must **initialize** it. You can
do so in three different ways:

1. **Initialize during declaration**.  
When you **declare** an **array**, you can give to each of the different
elements a value. To do so, you will write these values within curly brackets
(`{ }`) separated by a comma. Mind that the amount of values cannot be
greater than the number of elements declared but it can be lower. If you do so,
the first _i_<sup>th</sup> positions of the **array** will be filled with those
values and the rest will _"garbage data"_ awaiting to receive meaningful data.

<p align="center"><i>dataType array_name [arraySize] = {value1, value2, ..., valueN};</i></p>

2. **Initialize during declaration without specifying the size.**  
If you **declare** and **initialize** the **array** at the same time as seen
before, you can omit the **array** size as it will be deduced by the number of
elements you state. Mind that if you do it this way, and given the **array**'s
nature, you won't be able to add any element.

<p align="center"><i>dataType array_name [] = {value1, value2, ..., valueN};</i></p>

3. **Initialize after declaration.**  
When you simply **declare** an **array**, you can assign the initial values
to each element individually by using a `for` loop, a `while` loop or a
`do...while` loop.


<blockquote>
<details>
  <summary>View code examples</summary>
  <br>
<table>
<tr>
<th></th><th>C</th><th>C++</th></tr>
<tr><td>

<b>Initialize during declaration</b>

</td>
<td>

```c
#include <stdio.h>

int main() {
  
  int A[3] = {77, 53, 16};

  return 0;
}
```

</td>
<td>

```cpp
#include <iostream>

using namespace std;

int main() {
  
  int A[3] = {77, 53, 16};

  return 0;
}
```

</td></tr>
<tr><th>

<b>Initialize during declaration<br>without size</b>

</th>
<td>

```c
#include <stdio.h>

int main() {
  
  int A[] = {77, 53, 16};

  return 0;
}
```

</td>
<td>

```cpp
#include <iostream>

using namespace std;

int main() {
  
  int A[] = {77, 53, 16};

  return 0;
}
```

</td></tr>
<tr><th>

<b>Initialize after declaration<br>with a for loop</b>

</th>
<td>

```c
#include <stdio.h>

int main() {

  int A[3];

  for (int i = 0; i < 3; i++){
    A[i] = i + 2;
  }

  return 0;
}
```

</td>
<td>

```cpp
#include <iostream>

using namespace std;

int main() {

  int A[3];

  for (int i = 0; i < 3; i++){
    A[i] = i + 2;
  }

  return 0;
}
```

</td></tr>
</table>
</details>
</blockquote>

#### Vectors

In `C++`, **dynamic arrays** - meaning that their <u>size can be modified</u> - 
are called **vectors**. In **vectors**, new data is always added
<u>at the end</u>. In order to be able to use **vectors**, you must add in the
script header `#include <vector>`.

Unlike **arrays**, **vectors** are **declared** without specifying its size as
it might change, but you still have to **declare** what kind of data will be
stored. 

<p align="center"><i>vector< dataType > vector_name;</i></p>

Once more, you must **initialize** the **vector**. Some ways to do it are:

1. **Initialize during declaration.**  
When you **declare** a **vector**, you can specify its initial elements. To do
so, you will write these values within curly brackets (`{ }`) separated by a
comma.

<p align="center"><i>vector< dataType > vector_name = { value1, value2, ..., valueN};</i></p>

2. **Initialize during declaration specifying the size.**  
If you **declare** a **vector** with a specific size, you should add the
**vector** size between parenthesis (`( )`) after the **vector** name. In
addition, if you want for all those initial elements to have the same value,
you should add this value after the **vector** size separated by a comma.

<p align="center"><i>vector< dataType > vector_name(vectorSize);</i></p>
<p align="center"><i>vector< dataType > vector_name(vectorSize, initialValue);</i></p>

3. **Initialize after declaration.**  
When you simple **declare** the vector, you can assign its initial elements by
using a `for` loop, a `while` loop, or as a collection of elements within
curly brackets (`{ }`) separated by commas. Mind that if you use a loop, you
cannot use indexing to give the **vector** its initial values as we did with
**arrays** as the size of a **declared vector** (without specifying its size)
is by default 0. Thus, you will have to add the elements to it using
`.push_back()`.


<p align="center"><i>vector< dataType > vector_name;<br> vector_name = { value1, value2, ..., valueN};</i></p>


<blockquote>
<details>
  <summary>View code examples</summary>
  <br>
<table>
<tr>
<th></th><th>Option 1</th><th>Option 2</th></tr>
<tr><td>

<b>Initialize during declaration</b>

</td>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  
  vector<char> V = {'A', 'o', 'C'};

  return 0;
}
```

</td>
<td>

No second option.  
Nothing to see here.

</td></tr>
<tr><th>

<b>Initialize during declaration<br>with size</b>

</th>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  
  vector<char> V(3); //Empty vector with three positions

  return 0;
}
```

</td>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  
  vector<char> V(3, 'k'); //Vector with three initial 'k's

  return 0;
}
```

</td></tr>
<tr><th>

<b>Initialize after declaration</b>

</th>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  
  vector<char> V;
  V = {'A', 'o', 'C'};

  return 0;
}
```

</td>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<char> V;

  for (int i = 0; i < 3; i++){
    V.push_back('k');
  }

  return 0;
}
```

</td></tr>
</table>
</details>
</blockquote>

#### Sets

In `C++`, **dynamic arrays** that hold unique values are called **set**.
In a **set**, each element has to be unique as its value identifies it, and by
default, they are sorted in ascending order. In order to be able to use
**sets**, you must add in the script header `#include <set>`.

Like with **vectors**, when you **declare** a **set**, you just have to
**declare** what kind of data will be stored.

<p align="center"><i>set< dataType > set_name;</i></p>

This time, only two ways to **initialize** a **set** will be seen:

1. **Initialize during declaration.**  
When you **declare** a **set**, its initial values can be specified within
curly brackets (`{ }`) separated by a comma.

<p align="center"><i>set< dataType > set_name = {value1, value2, ..., valueN};</i></p>

2. **Initialize after declaration.**
If you do not know what values will the **set** contain, you can just
**declare** it and give it is values afterwards with a loop, by inserting
elements as the code goes by with `.insert()`, or assign to it a acollection
of elements within curly brackets (`{ }`).


<p align="center"><i>set< dataType > set_name;<br>set_name = {value1, value2, ..., valueN};</i></p>

> NOTE: You can not access **set** elements by index. If you want to access
the elements of a **set** you must use an iterator; by now you won't have to
deal with this situation but maybe you will during the first trimester.If try
you add to a **set** an element that it is already there, it won't be kept,
you will just waste an operation.


<blockquote>
<details>
  <summary>View code examples</summary>
  <br>
<table>
<tr>
<th>Declare and initialize</th><th>Initialize after declaring</th></tr>
<tr><td>

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
  
  set<double> S = {0.1, 3.1, 2.0};

  return 0;
}
```

</td>
<td>

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {

  set<double> S;
  S = {0.1, 3.1, 2.0};

  return 0;
}
```

</td></tr>
</table>
</details>
</blockquote>

#### Strings

**Strings** are a sequence of **characters**. In `C` and `C++`, **strings** are
**declared**, **initialized** and manipulated differently.

##### Strings in `C`

In `C`, **strings** are stored as static **array** of **characters** terminated
with a **null character** (`\0`). The format specifier for **strings** is
`%s`.

As with **arrays**, when **declaring** a **string** you must specify its size.
Take into account that the size you **declare**, has to be <u>the size of the
<b>string</b>, plus the null character</u> (_i.e._ for a **string** of size
_N_, we will **declare** a size of _N + 1_).

<p align="center"><i>char string_name[stringSize + 1];</i></p>


In this section, to **initialize** a **string**, all the options will be
<u> while <b>declaring</b></u>, but keep in mind that there are ways to do it
afterwards.

1. **Initialize as an array of characters.**  
As stated before, a **string** is an **array** of **characters**, and as such,
it can be **initialize** by assigning to each of the positions a **character**.
When doing it this way, you can either specify the size or let the compiler
determine it automatically.

<p align="center"><i>char string_name[stringSize + 1] = {value1, value2, ..., valueN, '\0'};</i></p>
<p align="center"><i>char string_name[] = {value1, value2, ..., valueN, '\0'};</i></p>

2. **Initialize as a string literal.**  
Another way, and an easier one, is to **initialize** the **string** as a
**String literal**. This is, write the **string** between double quotes without
the **null character**. Again, you can either specify the **String** size or
not. Keep in mind though, that even if there is no need of adding the
**null character** in the **initialization**, it must be taken into account
when **declaring** the **string** size.


<p align="center"><i>char string_name[stringSize + 1] = "This is a string";</i></p>
<p align="center"><i>char string_name[] = "This is also a string";</i></p>

<blockquote>
<details>
  <summary>View code examples</summary>
  <br>
<table>
<tr>
<th></th><th>With size</th><th>Without size</th></tr>
<tr><td>

<b>Initialize as an array of characters</b>

</td>
<td>

```c
#include <stdio.h>

int main() {
  
  char s[4] = {'A', 'o', 'C', '\0'};

  return 0;
}
```

</td>
<td>

```c
#include <stdio.h>

int main() {

  char s[] = {'A', 'o', 'C', '\0'};

  return 0;
}
```

</td></tr>
<tr><th>

<b>Initialize as a string literal</b>

</th>
<td>

```c
#include <stdio.h>

int main() {
  
  char s[4] = "AoC";

  return 0;
}
```

</td>
<td>

```c
#include <stdio.h>

int main() {
  
  char s[] = "AoC";

  return 0;
}
```

</td></tr>
</table>
</details>
</blockquote>

---

<p align="center"><b>A note on strings and memory allocation</b></p>

As mentioned before, when you declare an <b>array</b> in <code>C</code>, they
are allocated in memory at compile time; in other words, the compiler will give
a <u>fixed space</u> in memory to be used exclusively by that <b>array</b>.
<b>Strings</b> are <b>character arrays</b>, and by extension, when you
<b>declare</b> them, you are assigning a <u>fixed space</u> in memory which
should account for the <b>null character</b>. Now, you could forget about
adding the <code>+1</code> when assigning the memory for the <b>string</b>,
something like:
<br>

```c
#include <stdio.h>

int main() {
  
  char s[3] = "AoC";
  printf("%s\n", s);
  
  return 0;
}
```

<br>

If you compile and run this, no error will appear and the whole <b>string</b>
will be printed. Moreover, if you add the line 
<code>printf("%ld\n", sizeof(s));</code> the output include the number 3. The
most reasonable question now is...

<p align="center">Why do I have to add or take into account the null character?</p>

To answer this question the first thing that you have to know is which is the
actual use of the <b>null character</b>. The **null character** `\0`, tells `C`
where the **string** ends, where the **string**-related functions (such as
`printf()`) must stop. If there is no **null character**, those functions will
go on beyond the **string** until a 0-value byte is found. In the previous
example, no other space in memory is used and therefore, it stops at the end
of the defined **string**. Now, run the following code:
<br>

```c
#include <stdio.h>

int main() {

  char s[3] = "AoC";
  char ss[3] = "oA";

  printf("%s\n", s);
  printf("%s\n", ss);

  return 0;
}
```
<br>

As you can see, when you as the code to print the variable `s`, the function
`printf()` keeps on printing until the **null character** of `ss` is found.
Note that `ss` is **declared** to have a size of 3 ('o', 'A', '\0').  

Let's see one last example, but this time we will not only forget about the
**null character** but in addition, we will **declare** `s` with a smaller size
than the actually required to hold the **string**. And, again, `ss` will
take into account the **null character** when stating its size.
<br>

```c
#include <stdio.h>

int main() {

  char s[5] = "I do not care about memory allocation";
  char ss[30] = "care about memory allocation!";

  printf("%s\n", s);
  printf("%s\n", ss);

  return 0;
}
```

<br>

What's the output now?

Two things are happening here. The first one is that `s` only has assigned 5
slots in memory. Thus, any other variable declared afterwards (`ss` in this
case), will over-write the `s` extra space in memory with its own elements. If
no other variable is **declared**, only the five first **characters** will
be kept in memory and therefore, printed.  
The second one, is that, once more, the first `printf()` will keep on doing
until it finds a 0-value byte (in this case, the `ss` **null character**.


For a more in depth explanation, read [this] section on dynamic memory allocation

---

##### Strings in `C++`

In `C++` you can create **strings** as in `C`, but the most common way is to
use the `C++` **dynamic string**. In order to use these **strings**, you must
add to your script header `#include <string>`.

Unlike with `C` **strings**, you do not have to state the **string** size nor
the **null character**. To **declare** a **string** you just need to state the
**string** name.

<p align="center"><i>string string_name;</i></p>

Again, remember to **initialize** the **string**.

1. **Initialize during declaration.**  
When you **declare** a **string**, you can assign it its initial content by
writing it between <u>double quotes</u>.

<p align="center"><i>string string_name = "Yet another string example";</i></p>

2. **Initialize after declaration.**  
On the other hand, you can always **initialize** a **string** after its
**declaration**.

<p align="center"><i>string string_name;<br>string_name = "Finally, the last string example";</i></p>

<blockquote>
<details>
  <summary>View code examples</summary>
  <br>
<table>
<tr>
<th>Declare and initialize</th><th>Initialize after declaring</th></tr>
<tr><td>

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  
  string s = "Aoc";

  return 0;
}
```

</td>
<td>

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {

  string s;
  s = "AoC";

  return 0;
}
```

</td></tr>
</table>
</details>
</blockquote>

### Derived Data Type Functions in `C++`

Along this section, we've seen **arrays**, **sets**, **strings** and
**vectors**. In `C++` you will mostly use **sets**, **strings** and 
**vectors**. That is why, what follows is a small set of basic functions with
some examples to operate with them.

<blockquote>
<details>
  <summary>Set Functions Here!</summary>
  <br>
<table>
<tr>
<th>Function</th><th>Definition</th><th>Code</th></tr>
<tr><th>

<b>S.begin() / S.end()</b>

</th>
<td>

This two functions return an iterator to the first and last element in the set
`S` respectively.

</td>
<td>

```cpp
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
  
  set<int> S = {5, 8, 13, 21};
  set<int>::iterator iter;

  for (iter = S.begin(); iter != S.end(); iter++){
     cout << *iter << endl;
  }

  return 0;
}

//Output: 
// 5
// 8
// 13
// 21
```

</td></tr>
<tr><th>

<tr><th>

<b>S.clear()</b>

</th>
<td>

Deletes all element in the Set `S`

</td>
<td>

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
  
  set<int> S = {5, 8, 13, 21};
  S.clear();

  cout << S.empty() << endl;
  return 0;
}

//Output: 1
```

</td></tr>
<tr><th>

<b>S.empty()</b>

</th>
<td>

Returns true (`1`) if the set `S` is empty and false (`0`) otherwise

</td>
<td>

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {

  set<int> S = {5, 8, 13, 21};
  cout << S.empty() << endl;
  return 0;
}

//Output: 0
```

</td></tr>
<tr><th>

<b>S.find(a)</b>

</th>
<td>

Returns an iterator to the element `a` in `S` if found.
If `a` is not found, it returns `S.end()`.

</td>
<td>

```cpp
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main() {
  
  set<int> S = {5, 8, 13, 21};
  set<int>::iterator iter = S.find(13);
  
  cout << *iter * 2 << endl;
  return 0;
}

//Output: 26
```

</td></tr>
<tr><th>

<b>S.insert(a)</b>

</th>
<td>

Insert a single element `a` to<br> the set `S`(if it's not already there)

</td>
<td>

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
  
  set<int> S = {5, 8, 13, 21};
  S.insert(5);
  S.insert(34);

  cout << S.size() << endl;
  return 0;
}

//Output: 5
```

</td></tr>
<tr><th>

<b>S.size()</b>

</th>
<td>

Returns the size of the set `S`

</td>
<td>

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
  
  set<int> S = {5, 8, 13, 21};
  cout << S.size() << endl;
  return 0;
}

//Output: 4
```

</td></tr>
<tr><th>

<b>S.swap(SS)</b>

</th>
<td>

Swaps the entire set `S` with<br> the whole set `SS`.
Sets can have <br>different sizes but must store<br> the same data type

</td>
<td>

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
  
  set<int> S, SS;

  S = {5, 8, 13, 21};
  SS = {0, 1, 1, 2, 2};

  S.swap(SS);

  cout << SS.size() << endl;
  return 0;
}

//Output: 4
```

</td></tr>
</table>
</details>
</blockquote>

<blockquote>
<details>
  <summary>String Functions Here!</summary>
  <br>
<table>
<tr>
<th>Function</th><th>Definition</th><th>Code</th></tr>
<tr><th>

<b>s[i]</b>

</th>
<td>

Access a particular character of the string `s`

</td>
<td>

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  
  string s = "Divide&Conquer";
  cout << s[6] << endl;
  return 0;
}

//Output: &
```

</td></tr>
<tr><th>

<b>s.append(ss)</b>

</th>
<td>

Concatenate two strings(appends `ss` to `s`)

</td>
<td>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  
  string s, ss, sss;
  
  s = "Divide";
  ss = "&";
  sss = "Conquer";

  cout << s.append(ss).append(sss);
  return 0;

}

//Ouput: Divide&Conquer
```

</td></tr>
<tr><th>

<b>s.clear()</b>

</th>
<td>

Deletes all characters of the string

</td>
<td>

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  
  string s = "Divide&Conquer";
  cout << s << endl;

  s.clear();
  cout << s.length() << endl;
  return 0;
}

//Output: 
//  Divide&Conquer
//  0
```

</td></tr>
<tr><th>

<b>s.find(ss)</b>

</th>
<td>

Returns the index in `s` corresponding to the starting position of `ss`.
If `ss` is not found, it returns `string::npos`.

</td>
<td>

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  
  string s = "Divide&Conquer";
  cout << s.find("&") << endl;
  return 0;
}

//Output: 6
```

</td></tr>
<tr><th>

<b>s.length()</b>

</th>
<td>

Returns the size of the string `s`

</td>
<td>

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  
  string s = "Divide&Conquer";
  cout << s.length() << endl;
  return 0;
}

//Output: 14
```

</td></tr>
<tr><th>

<b>s.push_back(char)</b>

</th>
<td>

Inserts a single character at the end of the string `s`

</td>
<td>

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  
  string s = "Divide&Conquer";
  s.push_back('!');

  cout << s << endl;
  return 0;
}

//Output: Divide&Conquer!
```

</td></tr>
<tr><th>

<b>s.substr(i, len)</b>

</th>
<td>

Returns a substring of `s` starting at position `i` with length `len`.
If `len` is not specified, `s.substr(i)` will return a substring starting at
`i` until the end of `s`.

</td>
<td>

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
  
  string s = "Divide&Conquer";
  cout << s[6] << endl;
  return 0;
}

//Output: &
```

</td></tr>
</table>
</details>
</blockquote>


<blockquote>
<details>
  <summary>Vector Functions Here!</summary>
  <br>
<table>
<tr>
<th>Function</th><th>Definition</th><th>Code</th></tr>
<tr><th>

<b>V[i]</b>

</th>
<td>

Access a particular element of the string `V`

</td>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> V = {3, 1, 4, 1};
  cout << V[1] << endl;
  return 0;
}

//Output: 1
```

</td></tr>
<tr><th>

<b>V.begin() / V.end()</b>

</th>
<td>

This two functions return an iterator to the first and last element in the
vector `V` respectively.

</td>
<td>

```cpp
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  
  vector<int> V = {3, 1, 4, 1};
  vector<int>::iterator iter;

  for (iter = V.begin(); iter != V.end(); iter++){
     cout << *iter << endl;
  }

  return 0;
}

//Output: 
// 3
// 1
// 4
// 1
```

</td></tr>
<tr><th>

<b>V.clear()</b>

</th>
<td>

Deletes all element in the vector

</td>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  
  vector<int> V = {3, 1, 4, 1};
  V.clear();

  cout << V.size() << endl;
  return 0;
}

//Output: 0
```

</td></tr>
<tr><th>

<b>V.push_back(a)</b>

</th>
<td>

Insert a single element `a` at the end of the vector `V`.

</td>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  
  vector<int> V = {3, 1, 4, 1};
  V.push_back(5);

  cout << V.size() << endl;
  return 0;
}

//Output: 5
```

</td></tr>
<tr><th>

<b>V.size()</b>

</th>
<td>

Returns the size of the vector `V`

</td>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  
  vector<int> V = {3, 1, 4, 1};
  cout << V.size() << endl;
  return 0;
}

//Output: 4
```

</td></tr>
<tr><th>

<b>V.swap(VV)</b>

</th>
<td>

Swaps the entire vector `V` with the whole vector `VV`.
Vectors can have different sizes but must store the same data type.

</td>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  
  vector<int> V, VV;

  V = {3, 1, 4, 1};
  VV = {1, 3, 1, 2};

  V.swap(VV);

  cout << V[1] << endl;
  return 0;
}

//Output: 3
```

</td></tr>
</table>
</details>
</blockquote>

## Basic Structures

Within any program, you can define sections of code that either repeat in a
**loop** or **conditionally** execute. In general, they both have an initial
statement (even **looping** or a **conditionally** one) and a body to
perform. Moreover, these structures can be nested, either if it is not always
recommended for **loops** due to performance issues.

These structures are very similar across all the programming languages. In this
section we will see how they are implemented in `C` and in `C++`.

### Conditionals

**Conditionals** are used to make decisions based on a given **condition**. If
the condition evaluates to `true`, a set of statements (the body) is executed,
otherwise another set of statements is executed.

In `C` and `C++` we will work with three different **conditional** statements: 
`if`, `else if` and `else` .

#### `If` statement

The `if` statement is the most basic **conditional** as it can be state by 
itself. After the `if`, a **condition** is stated between parenthesis ( `( )` ),
and the code to be executed if that **condition** is `true` is written between 
curly brackets (`{ }`).

<p><i><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (condition){<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;body;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br><br>
</p></i>

<blockquote>
<details>
   <summary>See code examples</summary>

<table>
<thead>
  <tr>
   <th>C</th><th>C++</th>
  </tr>
</thead>
<tbody>
  <tr><td>

```c
#include <stdio.h>

int main (){

  int x = 11;
    
  if (x == 11){  
      printf("Pizza delivery!\n");
  }

  return 0;
}
```
</td><td>

```cpp
#include <iostream>

using namespace std;

int main(){

    int x = 11;

    if( x  == 11){
        cout << "Pizza delivery!" << endl;
    }

    return 0;
}
```
</td></tr>
</tbody>
</table>
</details>
</blockquote>


#### `Else` statement

The `else` statement has not explicit  **condition** as it will execute if and 
only if the other **conditions** are `false`. In other words, its **condition**
is "execute the following set of instructions if the rest of conditions are not
met". After the `else`, the code to be executed is directly stated between 
curly brackets (`{ }`).

<p ><i><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if(condition){<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;body;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;else{<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;body 2;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
</p></i><br>


<blockquote>
<details>
   <summary>See code examples</summary>

<table>
<thead>
  <tr>
   <th>C</th><th>C++</th>
  </tr>
</thead>
<tbody>
  <tr><td>
    
```c
#include <stdio.h>

int main() {

    int x = 11;

    if ( x == 11){
         printf("Pizza delivery! \n");
    }
    else{
         printf("Wrong number, try again next home.\n");
    }

     return 0;
}
```

</td><td>

```cpp
#include <iostream>

using namespace std;

int main(){

    int x = 11;

    if ( x  == 11){
        cout << "Pizza delivery!" << endl;
    }
    else {
        cout << "Wrong number, try again next home." << endl;
    }

    return 0;
}
```
</td></tr>
</tbody>
</table>
</details></blockquote>

#### `Else if` statement

The `else if` statement is used when there are more than two possible 
**conditions** that can take place. It is place after the `if` statement and 
before the `else` one. The program will only evaluate the `else if` statement 
if the previous one is `false`. There can be as many `else if` statements as 
needed.

As with the `if` **conditional**, after the `else if`, a **condition** is 
stated between parenthesis ( `( )` ), and the code to be executed if that 
**condition** is `true` is written between curly brackets (`{ }`).

<p><i><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (condition){<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;body 1;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;else if (condition 2){<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;body 2;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;else{<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;body 3;<br> 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
</p></i><br>


<blockquote>
<details>
   <summary>See code examples</summary>

<table>
<thead>
  <tr>
   <th>C</th><th>C++</th>
  </tr>
</thead>
<tbody>
  <tr><td>

```c
#include <stdio.h>

int main() {

     int x = 11;

     if ( x == 11){
         printf("Pizza delivery!\n");
     }
     else if (x == 300){
         printf("Wrong house, but I'm keeping the pizza.\n");
     }
     else{
         printf("Wrong number, try in the next home.\n");
     }

     return 0;
}
```

</td><td>
   
```cpp
#include <iostream>

using namespace std;

int main(){

   int x = 11;

   if ( x == 11){
       cout << "Pizza delivery!" << endl;
   }
   else if( x == 300){
       cout << "Wrong house, but I'm keeping the pizza." << endl;
   }     
   else {
       cout << "Wrong number, try in the next home." << endl;
   }

   return 0;
}
```

</td></tr>
</tbody>
</table>
</details></blockquote>


### Loops

**Loops**  are used to execute a block of code several times according to a
certain **condition** given in the **loop** statement. 

In this section, three different **loops** will be explained: `for` and `while`
**loops** (known as _entry controlled **loops**_ due to the **condition** being
test before computing the **loop** body), and the `do...while` **loop**(known
as _exit controlled **loop**_ due to the **condition** being tested after doing
a first iteration).


#### For Loops

`for` **loops** are used to execute a set of statements for specific number of
times or iterations.

The `for` **loop** syntax is the following:

<p><i><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for(initialization expression; condition; update expression){<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;body;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
</p></i><br>

The `initialization expression` allows you to **declare** and **initialize** the
variable that is going to be used as a counter for the number of iterations the
**loop** will make. The `condition` is checked in at the beginning of each
iteration and, as with the **conditionals**, if it evaluates to `true`, the
**loop** body will be executed. Finally, the `update expression` is used to
update the variable **initialized** in the `initialization expression`.

In `C++` there is a `for` **loop** variation called `for...each`. This variation
is used to iterate over the elements of an **array**, **vector**, **string** 
among others without having to use **indexing**. Each statement in the body will
be executed per element within the data structure. Its syntax is the following:

<p><i><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for (auto x: dataStructure ){<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;body;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
</p></i><br>

<blockquote>
<details>
<summary>See code examples</summary>

<table>
<tr>
<th>C</th><th>C++</th></tr> 
<tr><td>
                                                                                
```c
#include <stdio.h>

int main(){

    int A[10] = {1,2,3,4,5,6,7,8,9,0};

    for(int x = 0 ; x < 10; x++){
        printf("The selected number inside the array is: %d\n", A[x]);
    }

    return 0;
}
```

</td><td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> V = {1,2,3,4,5,6,7,8,9,0};

    for (auto x : V){
        cout << "The selected number inside the vector is: " << x << endl;
    }

    return 0;
}
```

</td></tr>
</table>
</details></blockquote>


#### While Loops

`while` **loops** are used when you want a set of statements to be executed 
continuously until a certain **condition** is no longer met. Unlike with the 
`for` **loops**, you don't know the number of iterations that will take place
until the program exists the **loop**. The `while` **loop** syntax is the 
following:

<p><i><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;while(condition){<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;body;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;update condition;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
</p></i><br>

In this kind of **loops** is very important to update the variable involved in
the **condition** after the body is executed. Otherwise, you will create an
**infinite loop** and the program will run forever.


<blockquote>
<details>
<summary>See code examples</summary>

<table>
<tr>
<th>C</th><th>C++</th></tr> 
<tr><td>

```c
#include<stdio.h>                                                               
                                                                                         
int main(){
                                                                         
    int x = 1, y = 0;                                                                  

    while(x < 100){
        y = x + x;

        printf("The cummulative sum it's %d, where our previous sum was %d.\n", y, x);
                                                    
        x = y;                                                                     
    }                                                                           
                                                                                
    return 0;                                                                       
}                   
```

</td><td>

```cpp
#include <iostream>

using namespace std;

int main(){

   int x = 200, y = 0;
    
   while (x >= 1) {
      x =  x - y;

      cout << "From our total value "<< x <<" we have substracted "<< y <<" ." << endl;

      y++;
   }

   return 0;
}
```

</td></tr>
</table>
</details></blockquote>



#### do...while Loops

Similarly to the `while` **loop**, the `do...while` **loop** will execute its
body as long as a certain **condition** is met. Unlike with the `while` 
**loops**, the **condition** will be checked AFTER each iteration of the body.
This implies that at least, one iteration will always be made. The syntax of a 
`do...while` **loop** is the following:

<p><i><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;do{<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;body;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;update condition;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;while (condition);<br>
</p></i><br>

Again, it is very important to update the variable involved in the **condition**
after the body execution to avoid an **infinite loop**.

<blockquote>
<details>
<summary>See code examples</summary>
   
<table>
<tr>
<th>C</th><th>C++</th></tr> 
<tr><td> 

```c
#include <stdio.h>

int main(){

    int x, sum = 0;

    do{
        printf("Introduce an Integer (0 it's exit):\n");

        scanf("%d", &x);
        sum += x;

        printf("You introduced %d\n", x);
    }
    while(x != 0);

    printf("The sum of all the integers you have introduced is  %d", sum);
    
    return 0;
}
```

</td><td>

```cpp
#include <iostream>

using namespace std;

int main(){

   int x = 0, sum = 0;

   do{
        cout << "Introduce an Integer (0 it's exit):" << endl;

        cin >> x;
        sum += x;

        cout << "You introduced " << x << endl;
        
    }
    while (x != 0);

    cout << "The sum of all the integers youhave  introduced is " << sum << endl;

    return 0;
}
```

</td></tr>
</table>
</details></blockquote>

## Functions

**Functions** are defined as a set of statements that perform some specific
task only when called. Given that **functions** are thought to be called
with different inputs, they are good for code modularity and reusability.

> NOTE: This topic, will be covered again in the memory allocation lessons. If
there is any new concept not explained here, it is due to being seen there.

As in `Python`, the **function**'s arguments are written between parenthesis
( `()` ) but the body is written between curly-brackets ( `{ }` ). The
syntax is as follows:

<p><i><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;returnDataType functionName(argDataType arg){<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;body;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return dataType;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
</p></i><br>


- `returnDataType`: Every function in `C` or `C++` must start by **declaring**
which kind of return will return. As mentioned in the [Data types](#data-types)
section, **functions** are a derived data type and as such, it must be
**declared** as any other variable. If your **function** returns an **array**,
a **vector**, a **set** or any other container, you must specify which kind of
data is stored in these structures.

- `functionName`: **Function** names must be meaningful. That is, the name
must make clear what the **function** does. As a convention, **functions** in
`C` and `C++` are named in  _camelCase_. That is, words are written together
and the first letter of each word (but not of the first one) is in upper-case.

- `argDataType arg`: Most **functions** receive some arguments to perform
its task. Once more, you must **declare** the expected data type for each of
the **function** arguments.

- `body;`: The body of a **function** must follow all the rules mentioned
along this file. For instance, any variable must be **declared** and all
statements must end with a semi-colon (`;`). It can include
**conditionals** or **loops** but the code cannot be redundant.

- `return dataType`: The return statement is the way to exit the **function**
and provide to the caller the result of it. Mind that you cannot return a
variable with a different data type than the one **declared** at the beginning
of the **function**.

> NOTE: Every `C` and `C++` script has at least one **function**, the `main()`.
This **function** usually ends with a `return 0;` as it is **declared** as
`int main()`, it returns an integer.

### The `void` Function

There is an exception to the **function** structure, we have seen, the `void`
**function**. This **function** is **declared** with the `void` data type and
does not need to have a `return` statement as it does not return anything
to its caller. This kind of **functions** are normally used to print something
to the standard output or to modify a container that is 
**passed by reference**. In this second case, the `void`
**function** will receive a container, modify it and return the control to its
caller. Normally, the only time you will see a `return` in a `void`
**function** is when you have a condition that, if fulfilled, will terminate
the **function**.

### The Function Scope

The term **scope** refers to what values and **functions** can be accessed.
Therefore, by extension, the **function scope** is what that **function**
"sees" and can access. Under this premise, there are three different scenarios
to be encountered:

1. Everything **declared** before a **function**, will be seen by that
**function**.
2. Everything **declared** inside a **function**, will be seen only by that
**function**.
3. Everything **declared** after a **function**, will not be seen by that
**function**.

The following code, has the three cases:

```cpp
#include <iostream>

using namespace std;

void swapNumbers(int a, int b){

    int aux = a;
    a = b;
    b = aux;
}

int main(){

   int x, y;

   while (cin >> x >> y){
        cout << "Before swap: " << x << ' ' << y << endl;
        swapNumbers(x, y);
        cout << "After swap: " << x << ' ' << y << endl;
   }
  
   return 0;
}
```

Lets see each of the cases and comment the **scope** of each **function** from
different points of view.

#### Case 1: Before the `main()` Function

Before the `main()` **function**, `swapNumbers()` is **declared** and
**initialized**. This implies that the `swapNumbers()` can be called by
`main()` as it is within its **scope**.

Another way to accomplish the same result, is to only **declare** the
`swapNumbers()` **function** before the `main()` one and **initialize** it
after:

```cpp
#include <iostream>

using namespace std;

void swapNumbers(int a, int b);

int main(){

   int x, y;

   while (cin >> x >> y){
        cout << "Before swap: " << x << ' ' << y << endl;
        swapNumbers(x, y);
        cout << "After swap: " << x << ' ' << y << endl;
   }
  
   return 0;
}

void swapNumbers(int a, int b){

    int aux = a;
    a = b;
    b = aux;
}
```

In this approach, as the `main()` already knows that `swapNumbers()` is a
**function** that does not return anything and requires two integers to
proceed, no error would rise. 


#### Case 2: Inside Both Functions

Each **function** has its own **scope**. In other words, whatever is
**declared** inside a **function** is only for the **function** to see.
It might seem obvious, but it is important to mind that no **function** can
see any variable **declared** within another **function** unless explicitly
stating it.

Lets examine our code with that idea in mind:

```cpp
#include <iostream>

using namespace std;

void swapNumbers(int a, int b){

    int aux = a;
    a = b;
    b = aux;
}

int main(){

   int x, y;

   while (cin >> x >> y){
        cout << "Before swap: " << x << ' ' << y << endl;
        swapNumbers(x, y);
        cout << "After swap: " << x << ' ' << y << endl;
   }
  
   return 0;
}
```

The integers `x` and `y`, are **declared** in `main()` but as we provide them
to `swapNumbers()` passing them as its arguments, they can be seen and used
by it.

Contrarily, `aux` is declared within `swapNumbers()` thus, `main()` cannot see
it nor use it; is out of its **scope**.

```cpp
#include <iostream>

using namespace std;

void swapNumbers(int a, int b){

    int aux = a;
    a = b;
    b = aux;
}

int main(){

   int x, y;

   while (cin >> x >> y){
        cout << "Before swap: " << x << ' ' << y << endl;
        swapNumbers(x, y);
        cout << "After swap: " << aux << ' ' << x << endl;
   }
  
   return 0;
}
```

```console
prog.cpp: In function ‘int main()’:
prog.cpp:19:35: error: ‘aux’ was not declared in this scope
   19 |         cout << "After swap: " << aux << ' ' << x << endl;
      |                                                        ^~~
```

If we wanted `main()` to use `aux` in any way, it must have been provided to
`main()` as the return of `swapNumbers()`.


#### Case 3: After the `main()` Function

Finally, suppose that `swapNumbers()` is **declared** and **initialized** after
`main()` as in the code bellow:

```cpp
#include <iostream>

using namespace std;

int main(){

   int x, y;

   while (cin >> x >> y){
        cout << "Before swap: " << x << ' ' << y << endl;
        swapNumbers(x, y);
        cout << "After swap: " << x << ' ' << y << endl;
   }
  
   return 0;
}

void swapNumbers(int a, int b){

    int aux = a;
    a = b;
    b = aux;
}
```

This code will rise the following error as `swapNumbers()` only "exists" before
`main()`.

```console

prog.cpp: In function ‘int main()’:
prog.cpp:11:9: error: ‘swapNumbers’ was not declared in this scope
   11 |         swapNumbers(x, y);
      |         ^~~~~~~~
```


## Extra Resources


[C/C++ Reference][c_cpp_ref]

Documentation for the different data types and structures in `C` and `C++`,
along with their corresponding functions.

[C Online Compiler][comp_c]

This is an online compiler for `C`. It will compile your code and execute it.
If a bug is found on the way, it will show the message you would see in your
terminal.

[C++ Online Compiler][comp_cpp]

This is an online compiler for `C`. It will compile your code and execute it.
If  bug is found on the way, it will show the message you would see in your
terminal.

[^datatypes]: The data types embedded in the `C` and `C++` languages,
are the ones that have a fixed size in memory. For instance, an `int` will
always need 32 bits (4 bytes), but a `string` can increase or decrease its
size along the same script. For a better and larger explanation, see this 
[stackoverflow comment][stckovrfl].

[c_cpp_ref]: <https://doc.bccnsoft.com/docs/cppreference_en/index.html>
[comp_c]: <https://www.w3schools.com/c/tryc.php?filename=demo_compiler>
[comp_cpp]: <https://www.w3schools.com/cpp/trycpp.asp?filename=demo_compiler>
[Differences1]: <https://www.interviewbit.com/blog/difference-between-c-and-cpp/>
[Differences2]: <https://www.freecodecamp.org/news/c-vs-cpp-whats-the-difference/>
[stckovrfl]: <https://stackoverflow.com/a/56452883>
[tab_char]: <https://img.brainkart.com/imagebk37/H5Kqmzr.jpg>
[tab_double]: <https://img.brainkart.com/imagebk37/MQ63eau.jpg>
[tab_int]: <https://img.brainkart.com/imagebk37/LGPW1Ux.jpg>
