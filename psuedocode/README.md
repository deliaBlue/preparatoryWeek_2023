# Pseudocode

During the courses you probably have had to look for codes implementations
to understand how an algorithm works. Through your research for publicly 
available implementations, you probably have encountered a "half redacted half
code" version solution. This is `pseudocode` and in this document you will 
learn its importance along with the syntax you will be using this year.
 
## TABLE OF CONTENTS
 1. [Introduction](#introduction)
 2. [Grammar](#grammar)
	- [Notation](#notation)
	- [Basic Constructs](#basic-constructs)
 3. [Data Structures](#data-structures)
 4. [Data Structures translation table](#data-structures-translation-table)
 5. [Practice Activities](#practice-activities)

## INTRODUCTION

Probably you have been beaten over the head about the importance of commenting
your code. How, after you forget how it works, you need to have a way of 
understanding what you were thinking at the time and that other people should
be able to do it as well. However, you may still think that `Python` is very 
intuitive, so this is a reminder that other languages exist out there. For
example, would you be able to understand the following chunks of code?


```
++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<++++++++++
+++++.>.+++.------.--------.>+.>.
```

```
HAI 1.2
CAN HAS STDIO?

I HAS A VAR ITZ "Hello, World!"
VISIBLE VAR

KTHXBYE
```
```
Shout "Hello, World!"
```

Indeed all these codes are implementing the "Hello World!" program. The codes
are in order in the languages [Brainfuck][Brainfuck], [LOLCODE][LOLCODE],
[rockstar][rockstar]. These are extreme cases but the point, again, is that
code may be hard to understand if you aren't familiar with the language. When
it partakes to comments, they need to follow the syntax of the specific coding
language being used. Furthermore, they should be used to provide context and
clarifications of specific lines otherwise, the program becomes clouded. 

This year you will be introduced to `pseudocode`, which is the format you
probably have encountered algorithms to be expressed in in other lectures
and papers. `Pseudocode` is a mixture of code and English. Some of the 
advantages of using `pseudocode` are: 

 - It is not bound to a specific programming language's syntax.
 - Its understandable across programmers of different backgrounds. 
 - Complex problems are broken down into smaller, manageable steps.

The "Hello world!" problem using `pseudocode` would look something like
the following. 

```
output Hello World!
```

As an example of how a more complex code looks like, the following is a 
recursive function that reads and outputs strings from the input stream.

```
procedure KEEP( )
    read a string s from the input stream
    if s is not empty then
        output s   // output what you currently read
        KEEP( )
```


## GRAMMAR

Finding the right level in the balance between readability and precision can
be tricky. This is why, even though by definition `pseudocode` does not obey
the syntax rules of any particular language, in the upcoming course you will
be given a set of conventions, a format and structure which you will be
expected to follow. This also facilitates the correcting process for the
professor (note that exams will be done on paper). Please keep in mind the 
following, we all learned by the end of our second year.
 
<p align="center"><b><i>"While understanding psuedocode is usually not difficult, writing it can be a challange"</i></b></p>

### NOTATION

Pseudocode conventions follow modern programming guidelines. The following are
examples of the notation to follow.
 
> NOTE: Further notation examples will be shown in the following sections.

 - Use the construct **“let … be …”** to initialize variables.
 - Enumeration starts at **1** not **0**.
 - `Strings` and `characters` are not introduced in using quotes.  
 - Assignment of value a to variable x is denoted by "x = a".
 - Comparison are done using the  mathematical symbols **=, ≠, <, >, ≤, ≥**. 
 - Arithmetic operators: **+, −, ×, /, mod**
 - Logical true and false:  **true** and **false**
 - Logical negation: **not**
 - Logical conjunction: **and**
 - Logical disjunction: **or**
 - Non-existence: **nil**
 - Comments are introduced with "//"

> NOTE: `=` is used for both assignment and comparison. To know which of the
two is the case context is key. For example, inside conditionals they are 
comparisons _e.g. "if s[1,3] = ATG then"_. However, if they appear all alone,
they are assignments _e.g. "C[A] = T"_.  

### BASIC CONSTRUCTS 

Control structures use the following reserved words: **all, break, do, if, 
else, then, for, while, repeat, return, to, until.**  Each of these constructs
can be embedded inside any other construct. Blocks of statements are
distinguished using indentation. 

**Condionals** 
<p align="center">
  <img width="500" src="https://github.com/deliaBlue/preparatoryWeek_2023/assets/103122258/c7a75dcf-5dcf-4230-880b-584b785045e1">
</p>

**Entry Controled loops**

<p align="center">
  <img width="500" src="https://github.com/deliaBlue/preparatoryWeek_2023/assets/103122258/248cde2c-2e33-402d-9b10-7603dc8a798f">
</p>

**Exit controled loops**
<p align="center">
  <img width="500" src=https://github.com/deliaBlue/preparatoryWeek_2023/assets/103122258/9220bc33-06a2-4d88-8785-1c33b41c0339">
</p>

## DATA STRUCTURES

In this section you will have an introduction to the different data   
structures available when writing `pseudocode` and the abstract         
operations they take. You will also have examples to help you understand
how they work. 

#### 1.  Array

An array is a collection of a **fixed** number of elements arranged in a 
single dimension. The element in the position _i_ th of the array _A_ accessed
by indexing with `A[i]`. 

<blockquote>
<details style="padding-left: 80px;">
    <summary>View example</summary>
    <table>
        <tr>
            <td>
                let A be an empty array<br>
                for i = 1 to n do<br>
                &nbsp;&nbsp;&nbsp;&nbsp;A[i] = i<br>
                output A<br>
                // A is now an array 1 to n 
            </td>
        </tr>
    </table>
</details>
</blockquote>

#### 2.  List

A list is a sequence of elements arranged in a single dimension. It has **no**
predetermined size and only the **first** and **last** elements can be 
accessed. 

<blockquote>
<details>
    <summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
        <tr>
            <th style="width: 15%; text-align: center;">Function</th>
            <th style="width: 45%;">Definition</th>
            <th>Example</th>
        </tr>
        <tr>
            <td>front</td>
            <td style="font-size: 15px;">returns the first element in the list</td>
            <td style="font-size: 14px;"> 
              let L be a list 1 to 3<br>
              &nbsp;&nbsp;&nbsp;&nbsp;output front L    //output is 1 
            </td>
        </tr>
        <tr>
            <td>back</td>
            <td style="font-size: 15px;">returns the last element in the list</td>
            <td style="font-size: 14px;">
              let L be a list 1 to 3<br>
              output back L    //output is 3
            </td>
        </tr>
        <tr>
             <td>prev</td>
             <td style="font-size: 15px;">returns the element before a given element</td>
             <td style="font-size: 14px;">
               let L be a list 1 to 3<br>
               output L.prev(3)  //output is 2
             </td>
        </tr>
        <tr>
             <td>next</td>
             <td style="font-size: 15px;">returns the element after a given element</td>
             <td style="font-size: 14px;">
               let L be a list 1 to 3<br>
               output L.next(2)  //output is 3
             </td>
        </tr>
        <tr>
             <td>append</td>
             <td style="font-size: 15px;">inserts an element at the back of the list</td>
             <td style="font-size: 14px;">
               let L be a list 1 to 3<br>
               append 4 to L //L is now [1,2,3,4]
             </td>
        </tr>
        <tr>
             <td>concatenate</td>
             <td style="font-size: 15px;">operation deletes the elements of another list and
inserts them at the end of the first</td>
             <td style="font-size: 14px;">
               let L be a list 1 to 3 and L' be a list 4 to 6<br>
               concatenate L' to L<br> 
               //L is now [1,2,3,4,5,6] and L' is empty
             </td>
        </tr>

   </table>
</details>
</blockquote>


#### 3.  Stack

A stack is a last-in, first-out (`LIFO`) data structure. Elements are inserted
and removed from the same end of the sequence: the **top**.

<blockquote>
<details>
<summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
    <tr>
        <th style="width: 15%; text-align: center;">Function</th>
        <th style="width: 43%;">Definition</th>
        <th>Example</th>
    </tr>
    <tr>
        <td>push</td>
        <td style="font-size: 15px;">inserts a given element at the top of the stack</td>
        <td style="font-size: 14px;">
          Let S be an empty stack<br>
          push 3 onto S<br>
          push 2 onto S<br>
          push 1 onto S<br>
          // 1 is the top element in S<br>
        </td>
    </tr>
    <tr>
        <td>top</td>
        <td style="font-size: 15px;">returns the top element of a non-empty stack</td>
        <td style="font-size: 14px;">
          Let S be an empty stack<br>
          push 3 onto S<br>
          push 2 onto S<br>
          push 1 onto S<br>
          Let x be the element at the top of S<br>
          output x // output is 1
        </td>
    </tr>
    <tr>
        <td>pop</td>
        <td>deletes and returns the top element in the stack</td>
        <td style="font-size: 14px;">
         Let S be an empty stack<br>
         push 3 onto S<br>
         push 2 onto S<br>
         push 1 onto S<br>
         while S is not empty do<br>
            &nbsp;&nbsp;&nbsp;&nbsp;pop from S the top element x<br>
            &nbsp;&nbsp;&nbsp;&nbsp;output x //output is 1 then 2 then 3<br>
            <br>
            // by the end of the while loop S is empty
        </td>
    </tr>
</table>
</details>
</blockquote>

#### 4.  Queue

A queue is a first-in, first-out (`FIFO`) data structure. Elements are 
inserted at the **rear** and removed from the **front**. You can think of it
as a double ended stack.

<blockquote>
<details>
<summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
    <tr>
        <th style="width: 15%; text-align: center;">Function</th>
        <th style="width: 35%;">Definition</th>
        <th>Example</th>
    </tr>
    <tr>
        <td>enqueue</td>
        <td style="font-size: 15px;">inserts an element at the rear end of the queue</td>
        <td style="font-size: 14px;">
          Let Q be a queue<br>
          enqueue 1 into Q<br>
          enqueue 2 into Q<br>
          enqueue 3 into Q<br>
        </td>
    </tr>
    <tr>
        <td>dequeue</td>
        <td style="font-size: 15px;">deletes and returns the front element in the queue</td>
        <td style="font-size: 14px;">
          Let Q be a queue<br>
          enqueue 1 into Q<br>
          enqueue 2 into Q<br>
          enqueue 3 into Q<br>
          repeat<br>
          &nbsp;&nbsp;&nbsp;&nbsp;Let x be the element at the front of Q<br>
          &nbsp;&nbsp;&nbsp;&nbsp;dequeue from Q the front element x<br>
          &nbsp;&nbsp;&nbsp;&nbsp;output x //output will be 1 then 2 then 3<br>
          until Q is empty<br>
        </td>
    </tr>
    <tr>
        <td>front</td>
        <td style="font-size: 15px;">returns the front element in the queue</td>
        <td style="font-size: 14px;">
          Let Q be a queue<br>
          Let x be an element<br>
          enqueue x into Q<br>
          Let x be the element at the front of Q<br>
          output x<br>
        </td>
    </tr>
</table>
</details>
</blockquote>

#### 5.  Priority Queue

The priority queue is an extension of a regular queue with assigned 
**priorities** to elements. The highest-priority element is dequeued first.

<blockquote>
<details>
<summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
    <tr>
        <th style="width: 12%; text-align: center;">Function</th>
        <th style="width: 30%;">Definition</th>
        <th>Example</th>
    </tr>
    <tr>
        <td>enqueue</td>
        <td style="font-size: 14px;">inserts an element with a given priority in the priority queue</td>
        <td style="font-size: 14px;">
          Let Q be a priority queue<br>
          enqueue (x, y) into Q<br>
        </td>
    </tr>
    <tr>
        <td>dequeue</td>
        <td style="font-size: 14px;">deletes and returns an element with the minimum priority in the priority queue</td>
        <td style="font-size: 14px;">
          Let Q be a priority queue<br>
          enqueue (x, y) into Q<br>
          Let (x, y) be an element with the minimum priority y in Q<br>
          repeat<br>
          &nbsp;&nbsp;&nbsp;&nbsp;dequeue from Q an element (x, y) with the minimum priority y<br>
          &nbsp;&nbsp;&nbsp;&nbsp;Output (x, y)<br>
          Until Q is empty<br>
        </td> 
    </tr>
    <tr>
        <td>front</td>
        <td style="font-size: 14px;">returns an element with the minimum priority in the priority queue</td>
        <td style="font-size: 14px;"> 
          Let Q be a priority queue<br>
          enqueue (x, y) into Q<br> 
          Let (x, y) be an element with the minimum priority y in Q<br>
          Output (x, y)<br>
        </td>
    </tr>
</table>
</details>
</blockquote>

#### 6.  Set

A set is a collection of unique elements without an order. When defining a 
`set` you can use the mathematical notation:
 
- To denote belonging use `∈`. 
- To insert an element `x` onto a set `S` use ` S = S U {x}`.
- To delete an element `x` from a set `S` use ` S = S \ {x}`.


Alternatively you can use the  `instert` and `delete` functions. Take into account that you will see both intertwined throughout the examples. 

<blockquote>
<details>
<summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
    <tr>
        <th style="width: 15%; text-align: center;">Function</th>
        <th style="width: 45%;">Definition</th>
        <th>Example</th>
    </tr>
    <tr>
        <td>insert</td>
        <td style="font-size: 14px;">inserts an element into the set</td>
        <td style="font-size: 14px;"> 
          let S be a set<br>
          insert x into S<br> 
        </td>
    </tr>
    <tr>
        <td>delete</td>
        <td style="font-size: 14px;">deletes an element from the set</td>
        <td style="font-size: 14px;">
          let S be an empty set<br>
          S = S U {x}<br>
          for all x ∈ S do<br>
          &nbsp;&nbsp;&nbsp;&nbsp;output x<br>
          &nbsp;&nbsp;&nbsp;&nbsp;delete x from S<br>
        </td> 
    </tr>
    <tr>
        <td>member</td>
        <td style="font-size: 14px;">returns true if the element belongs to the set, false otherwise</td>
        <td style="font-size: 14px;">
          let S be an empty set<br>
          output member(x, S) //output is "false"<br>
        </td>
    </tr>
</table>
</details>
</blockquote>


#### 7.  Matrix 

A matrix is a two-dimensional [array](#1-array) organized in predetermined *i*
rows and  *j* columns.

<blockquote>
<details style="padding-left: 80px;">
    <summary>View example</summary> 
    <table>
        <tr>
            <td>
                let M[1..m][1..n] be a matrix<br>
                for i = 1 to m do<br>
                &nbsp;&nbsp;&nbsp;&nbsp;for j = 1 to n do<br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;M[i][j] = 0<br>
                output M // M will be a mxn matrix filled with 0s<br>
            </td>
        </tr>
    </table>
</details>
</blockquote>


#### 8. Dictionary

A dictionary is a structure containing a [set](#6-set) of **keys** each of 
which has an associated  **value**. The `value` of a given ` key` is accessed
using `D[key]`. 

<blockquote>
<details>
<summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
    <tr>
        <th style="width: 11%;" text-align: center;">Function</th>
        <th style="width: 40%;">Definition</th>
        <th>Example</th>
    </tr>
    <tr>
        <td>member</td>
        <td style="font-size: 14px;">returns true if the key is in the dictionary, false otherwise.</td>
        <td style="font-size: 14px;"> 
          Let D be an empty dictionary<br>
          D[x] = y // insert key x with value y into D<br>
          output member(x, D) //outputs "true" 
        </td>
    </tr>
    <tr>
        <td>lookup</td>
        <td style="font-size: 14px;">returns the element associated with the
        given key in the dictionary, nil if not found.</td>
        <td style="font-size: 14px;">
          Let D be a dictionary<br>
          D[x] = y // insert key x with value y into D<br>
          output D[x] lookup //output y 
        </td> 
    </tr>
    <tr>
        <td>insert</td>
        <td style="font-size: 14px;">inserts an element with a given key and information into the dictionary, replacing the element (if any) with the given key.</td>
        <td style="font-size: 14px;">
          Let D be a dictionary<br>
          D[x] = y // insert an key x with value y into D<br>
          D[x] = z // replacing x's value to be z <br>
          output D[x] // output is z
        </td>
    </tr>
    <tr>
        <td>delete</td>
        <td style="font-size: 14px;">deletes the element with the given key from the dictionary, if it exists.</td>
        <td style="font-size: 14px;">
        let D be a  dictionary<br>
        for all x ∈ D do<br>
        &nbsp;&nbsp;&nbsp;&nbsp; y = D[x] lookup<br>
        &nbsp;&nbsp;&nbsp;&nbsp;output (x, y)<br>
        &nbsp;&nbsp;&nbsp;&nbsp;delete x from D //removes key x and its value<br>
        </td>
    </tr>
</table>
</details>
</blockquote>



## DATA STRUCTURES

In this section you will have an introduction to the different data   
structures available when writing `pseudocode` and the abstract         
operations they take. You will also have examples to help you understand
how they work. 

#### 1.  Array

An array is a collection of a **fixed** number of elements arranged in a 
single dimension. The element in the position _i_ th of the array _A_ accessed
by indexing with `A[i]`. 

<blockquote>
<details style="padding-left: 80px;">
    <summary>View example</summary>
    <table>
        <tr>
            <td>
                let A be an empty array<br>
                for i = 1 to n do<br>
                &nbsp;&nbsp;&nbsp;&nbsp;A[i] = i<br>
                output A<br>
                // A is now an array 1 to n 
            </td>
        </tr>
    </table>
</details>
</blockquote>

#### 2.  List

A list is a sequence of elements arranged in a single dimension. It has **no**
predetermined size and only the **first** and **last** elements can be 
accessed. 

<blockquote>
<details>
    <summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
        <tr>
            <th style="width: 15%; text-align: center;">Function</th>
            <th style="width: 45%;">Definition</th>
            <th>Example</th>
        </tr>
        <tr>
            <td>front</td>
            <td style="font-size: 15px;">returns the first element in the list</td>
            <td style="font-size: 14px;"> 
              let L be a list 1 to 3<br>
              &nbsp;&nbsp;&nbsp;&nbsp;output front L    //output is 1 
            </td>
        </tr>
        <tr>
            <td>back</td>
            <td style="font-size: 15px;">returns the last element in the list</td>
            <td style="font-size: 14px;">
              let L be a list 1 to 3<br>
              output back L    //output is 3
            </td>
        </tr>
        <tr>
             <td>prev</td>
             <td style="font-size: 15px;">returns the element before a given element</td>
             <td style="font-size: 14px;">
               let L be a list 1 to 3<br>
               output L.prev(3)  //output is 2
             </td>
        </tr>
        <tr>
             <td>next</td>
             <td style="font-size: 15px;">returns the element after a given element</td>
             <td style="font-size: 14px;">
               let L be a list 1 to 3<br>
               output L.next(2)  //output is 3
             </td>
        </tr>
        <tr>
             <td>append</td>
             <td style="font-size: 15px;">inserts an element at the back of the list</td>
             <td style="font-size: 14px;">
               let L be a list 1 to 3<br>
               append 4 to L //L is now [1,2,3,4]
             </td>
        </tr>
        <tr>
             <td>concatenate</td>
             <td style="font-size: 15px;">operation deletes the elements of another list and
inserts them at the end of the first</td>
             <td style="font-size: 14px;">
               let L be a list 1 to 3 and L' be a list 4 to 6<br>
               concatenate L' to L<br> 
               //L is now [1,2,3,4,5,6] and L' is empty
             </td>
        </tr>

   </table>
</details>
</blockquote>


#### 3.  Stack

A stack is a last-in, first-out (`LIFO`) data structure. Elements are inserted
and removed from the same end of the sequence: the **top**.

<blockquote>
<details>
<summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
    <tr>
        <th style="width: 15%; text-align: center;">Function</th>
        <th style="width: 43%;">Definition</th>
        <th>Example</th>
    </tr>
    <tr>
        <td>push</td>
        <td style="font-size: 15px;">inserts a given element at the top of the stack</td>
        <td style="font-size: 14px;">
          Let S be an empty stack<br>
          push 3 onto S<br>
          push 2 onto S<br>
          push 1 onto S<br>
          // 1 is the top element in S<br>
        </td>
    </tr>
    <tr>
        <td>top</td>
        <td style="font-size: 15px;">returns the top element of a non-empty stack</td>
        <td style="font-size: 14px;">
          Let S be an empty stack<br>
          push 3 onto S<br>
          push 2 onto S<br>
          push 1 onto S<br>
          Let x be the element at the top of S<br>
          output x // output is 1
        </td>
    </tr>
    <tr>
        <td>pop</td>
        <td>deletes and returns the top element in the stack</td>
        <td style="font-size: 14px;">
         Let S be an empty stack<br>
         push 3 onto S<br>
         push 2 onto S<br>
         push 1 onto S<br>
         while S is not empty do<br>
            &nbsp;&nbsp;&nbsp;&nbsp;pop from S the top element x<br>
            &nbsp;&nbsp;&nbsp;&nbsp;output x //output is 1 then 2 then 3<br>
            <br>
            // by the end of the while loop S is empty
        </td>
    </tr>
</table>
</details>
</blockquote>

#### 4.  Queue

A queue is a first-in, first-out (`FIFO`) data structure. Elements are 
inserted at the **rear** and removed from the **front**. You can think of it
as a double ended stack.

<blockquote>
<details>
<summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
    <tr>
        <th style="width: 15%; text-align: center;">Function</th>
        <th style="width: 35%;">Definition</th>
        <th>Example</th>
    </tr>
    <tr>
        <td>enqueue</td>
        <td style="font-size: 15px;">inserts an element at the rear end of the queue</td>
        <td style="font-size: 14px;">
          Let Q be a queue<br>
          enqueue 1 into Q<br>
          enqueue 2 into Q<br>
          enqueue 3 into Q<br>
        </td>
    </tr>
    <tr>
        <td>dequeue</td>
        <td style="font-size: 15px;">deletes and returns the front element in the queue</td>
        <td style="font-size: 14px;">
          Let Q be a queue<br>
          enqueue 1 into Q<br>
          enqueue 2 into Q<br>
          enqueue 3 into Q<br>
          repeat<br>
          &nbsp;&nbsp;&nbsp;&nbsp;Let x be the element at the front of Q<br>
          &nbsp;&nbsp;&nbsp;&nbsp;dequeue from Q the front element x<br>
          &nbsp;&nbsp;&nbsp;&nbsp;output x //output will be 1 then 2 then 3<br>
          until Q is empty<br>
        </td>
    </tr>
    <tr>
        <td>front</td>
        <td style="font-size: 15px;">returns the front element in the queue</td>
        <td style="font-size: 14px;">
          Let Q be a queue<br>
          Let x be an element<br>
          enqueue x into Q<br>
          Let x be the element at the front of Q<br>
          output x<br>
        </td>
    </tr>
</table>
</details>
</blockquote>

#### 5.  Priority Queue

The priority queue is an extension of a regular queue with assigned 
**priorities** to elements. The highest-priority element is dequeued first.

<blockquote>
<details>
<summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
    <tr>
        <th style="width: 12%; text-align: center;">Function</th>
        <th style="width: 30%;">Definition</th>
        <th>Example</th>
    </tr>
    <tr>
        <td>enqueue</td>
        <td style="font-size: 14px;">inserts an element with a given priority in the priority queue</td>
        <td style="font-size: 14px;">
          Let Q be a priority queue<br>
          enqueue (x, y) into Q<br>
        </td>
    </tr>
    <tr>
        <td>dequeue</td>
        <td style="font-size: 14px;">deletes and returns an element with the minimum priority in the priority queue</td>
        <td style="font-size: 14px;">
          Let Q be a priority queue<br>
          enqueue (x, y) into Q<br>
          Let (x, y) be an element with the minimum priority y in Q<br>
          repeat<br>
          &nbsp;&nbsp;&nbsp;&nbsp;dequeue from Q an element (x, y) with the minimum priority y<br>
          &nbsp;&nbsp;&nbsp;&nbsp;Output (x, y)<br>
          Until Q is empty<br>
        </td> 
    </tr>
    <tr>
        <td>front</td>
        <td style="font-size: 14px;">returns an element with the minimum priority in the priority queue</td>
        <td style="font-size: 14px;"> 
          Let Q be a priority queue<br>
          enqueue (x, y) into Q<br> 
          Let (x, y) be an element with the minimum priority y in Q<br>
          Output (x, y)<br>
        </td>
    </tr>
</table>
</details>
</blockquote>

#### 6.  Set

A set is a collection of unique elements without an order. When defining a 
`set` you can use the mathematical notation:
 
- To denote belonging use `∈`. 
- To insert an element `x` onto a set `S` use ` S = S U {x}`.
- To delete an element `x` from a set `S` use ` S = S \ {x}`.


Alternatively you can use the  `instert` and `delete` functions. Take into account that you will see both intertwined throughout the examples. 

<blockquote>
<details>
<summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
    <tr>
        <th style="width: 15%; text-align: center;">Function</th>
        <th style="width: 45%;">Definition</th>
        <th>Example</th>
    </tr>
    <tr>
        <td>insert</td>
        <td style="font-size: 14px;">inserts an element into the set</td>
        <td style="font-size: 14px;"> 
          let S be a set<br>
          insert x into S<br> 
        </td>
    </tr>
    <tr>
        <td>delete</td>
        <td style="font-size: 14px;">deletes an element from the set</td>
        <td style="font-size: 14px;">
          let S be an empty set<br>
          S = S U {x}<br>
          for all x ∈ S do<br>
          &nbsp;&nbsp;&nbsp;&nbsp;output x<br>
          &nbsp;&nbsp;&nbsp;&nbsp;delete x from S<br>
        </td> 
    </tr>
    <tr>
        <td>member</td>
        <td style="font-size: 14px;">returns true if the element belongs to the set, false otherwise</td>
        <td style="font-size: 14px;">
          let S be an empty set<br>
          output member(x, S) //output is "false"<br>
        </td>
    </tr>
</table>
</details>
</blockquote>


#### 7.  Matrix 

A matrix is a two-dimensional [array](#1-array) organized in predetermined *i*
rows and  *j* columns.

<blockquote>
<details style="padding-left: 80px;">
    <summary>View example</summary> 
    <table>
        <tr>
            <td>
                let M[1..m][1..n] be a matrix<br>
                for i = 1 to m do<br>
                &nbsp;&nbsp;&nbsp;&nbsp;for j = 1 to n do<br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;M[i][j] = 0<br>
                output M // M will be a mxn matrix filled with 0s<br>
            </td>
        </tr>
    </table>
</details>
</blockquote>


#### 8. Dictionary

A dictionary is a structure containing a [set](#6-set) of **keys** each of 
which has an associated  **value**. The `value` of a given ` key` is accessed
using `D[key]`. 

<blockquote>
<details>
<summary style="padding-left: 80px;">View functions and examples</summary>
<table style="width: 100%;">
    <tr>
        <th style="width: 11%;" text-align: center;">Function</th>
        <th style="width: 40%;">Definition</th>
        <th>Example</th>
    </tr>
    <tr>
        <td>member</td>
        <td style="font-size: 14px;">returns true if the key is in the dictionary, false otherwise.</td>
        <td style="font-size: 14px;"> 
          Let D be an empty dictionary<br>
          D[x] = y // insert key x with value y into D<br>
          output member(x, D) //outputs "true" 
        </td>
    </tr>
    <tr>
        <td>lookup</td>
        <td style="font-size: 14px;">returns the element associated with the
        given key in the dictionary, nil if not found.</td>
        <td style="font-size: 14px;">
          Let D be a dictionary<br>
          D[x] = y // insert key x with value y into D<br>
          output D[x] lookup //output y 
        </td> 
    </tr>
    <tr>
        <td>insert</td>
        <td style="font-size: 14px;">inserts an element with a given key and information into the dictionary, replacing the element (if any) with the given key.</td>
        <td style="font-size: 14px;">
          Let D be a dictionary<br>
          D[x] = y // insert an key x with value y into D<br>
          D[x] = z // replacing x's value to be z <br>
          output D[x] // output is z
        </td>
    </tr>
    <tr>
        <td>delete</td>
        <td style="font-size: 14px;">deletes the element with the given key from the dictionary, if it exists.</td>
        <td style="font-size: 14px;">
        let D be a  dictionary<br>
        for all x ∈ D do<br>
        &nbsp;&nbsp;&nbsp;&nbsp; y = D[x] lookup<br>
        &nbsp;&nbsp;&nbsp;&nbsp;output (x, y)<br>
        &nbsp;&nbsp;&nbsp;&nbsp;delete x from D //removes key x and its value<br>
        </td>
    </tr>
</table>
</details>
</blockquote>



## DATA STRUCTURES TRANSLATION TABLE

The following table shows how the data structures we described in the previous
section can be implemented in `Python` and `C++`. Some of them require a module
to be imported, in these cases the module is included in the same cell.

<table>
  <tr style="font-size: 15px;">
    <th style="width: 25%; text-align: center;">Pseudocode</th>
    <th style="width: 25%; text-align: center;">Python</th>
    <th style="width: 25%; text-align: center;">C++ (Include these libraries)</th>
  </tr>
  <tr style="font-size: 14px; text-align: center;">
    <td>Array</td>
    <td>list</td>
    <td>#include &lt;vector&gt;</td>
  </tr>
  <tr style="font-size: 14px; text-align: center;">
    <td>List</td>
    <td>list tuple</td>
    <td>#include &lt;list&gt</td>
  </tr>
  <tr style="font-size: 14px; text-align: center;">
    <td>Stack</td>
    <td>from collections import deque</td>
    <td>#include &lt;stack&gt;</td>
  </tr>
  <tr style="font-size: 14px; text-align: center;">
    <td>Queue</td>
    <td>from collections import deque</td>
    <td>#include &lt;queue&gt;</td>
  </tr>
  <tr style="font-size: 14px; text-align: center;">
    <td>Priority queue</td>
    <td>import heapq</td>
    <td>#include &lt;queue&gt;</td>
  </tr>
  <tr style="font-size: 14px; text-align: center;">
    <td>Set</td>
    <td>set</td>
    <td>#include &lt;set&gt;</td>
  </tr>
  <tr style="font-size: 14px; text-align: center;">
    <td>Dictionary</td>
    <td>dict</td>
    <td>#include &lt;map&gt;</td>
  </tr>
</table>

 >NOTE: When defining a data structure in `c++` you need to include `std::` in
 front of all the data structures followed by the data structure and the 
 _class_  of the elements it will contain in between `< >`. For example:  

<blockquote>
<details style="padding-left: 80px;">
    <summary>View example using vector</summary>
    <table>
        <tr style="font-size: 15px;">
            <td>
                <b>#include &lt;b&gt;<vector&gt;</b></b><br>
                <br>
                int main() { <br>
                &nbsp;&nbsp;&nbsp;&nbsp;<b>std::vector&lt;int&gt;</b> v = {1, 2, 3, 4, 5};<br>
                &nbsp;&nbsp;&nbsp;&nbsp;// do something with v <br>
                }<br>
            </td>
        </tr>
    </table>
</details>
</blockquote>

## PRACTICE ACTIVITIES 

We have prepared some [problem exercises](activities/README.md) for you to practice.  




[Brainfuck]: <https://en.wikipedia.org/wiki/Brainfuck#Hello_World!>
[LOLCODE]: <https://en.wikipedia.org/wiki/LOLCODE>
[rockstar]: <https://codewithrockstar.com/>
