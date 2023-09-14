The following are simple problem examples we have prepared for you to 
practice. Our goal is for you to get familiar with the correct words and 
syntax you need to use for each specific language you will be working with.
For this reason problems in [Block 1](#block-1) will be recycled throughout the
classes activities. 

### Block 1
------------

#### Problem 1: DNA to RNA

Build a function that given a DNA sequence returns its RNA version. Ignore 
start and stop codons, simply exchange Thymines by Cracils.

<blockquote>
Example: 

- Input: _GATTACA_
- Output: _GAUUACA_
</blockquote>


<blockquote>
<details>
   <summary>View pseudocode model solution</summary>
   <table style="padding-left: 80px";>
   <tr><td>
function DNA-TO-RNA(s)<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;let s' be a copy of s<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;for i = 1 to |s| do<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if s[i] = T then <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;s'[i] = U<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;else <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;s'[i] = s[i]<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;return s'<br>
   </td> </tr>
   </table>
</details>
</blockquote>


#### Problem 2: Find coding region

The reading frame starts whenever ATG is encountered and it stops whenever
TAA, TAG, or TGA is encountered. Write a function that given a DNA strand,
finds the coding region **not including the start and end codons**. Note that
if there is not start or no stop codon the function should return nothing
(empty string).

<blockquote>
Example: 

-  Input: ATG-GATTACA-TGATTT
-  Output: -GATTACA-
</blockquote>

<blockquote>
<details>
   <summary>View pseudocode model solution</summary>
   <table>
   <tr><td>
function CODING-REGION(s)<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; let s' be an empty string<br>
&nbsp;&nbsp;&nbsp;&nbsp; let i = 1<br>
&nbsp;&nbsp;&nbsp;&nbsp; let n = |s|<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; while i + 2 <= n do<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; if s[i:i+2] = ATG then<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j = i + 3<br><br>
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; while j <= n-2 do<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if s[j:j+2] ∈ {TAA, TAG, TGA} then<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; return s[i+3:j-1]<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;j = j +3 <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i = i + 1<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; return an empty string<br>
   </td></tr>
   </table>
</details>
</blockquote>


#### Problem 3: GC content 

The *GC content* is the percentage of guanine (G) and cytosine (C) nucleotides
in a DNA or RNA molecule. Write a function than given a DNA or RNA strand it
returns its GC content in percentage and one rounded decimal.

<blockquote>
Example:

- Input: GCAAATTTTT
- Output: _20.0%_
</blockquote>

<blockquote>
<details>
   <summary>View pseudocode model solution</summary>
   <table>
   <tr><td>
function GC-content(s)<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; let n = |s|<br>
&nbsp;&nbsp;&nbsp;&nbsp; let gc = 0<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; for i = 1 to n do<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; if s[i] ∈ [G, C] then<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; gc = gc+1<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;gc = gc*100 / |s|<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;return gc               
   </td></tr>
   </table>
</details>
</blockquote>


#### Problem 4: Flip a string

We read words left to right. Write a function that given a word it flips it.
It should return the word read from right to left.

<blockquote>
Example:

- Input: _STRESSED_
- Output: _DESSERTS_
</blockquote>

<blockquote>
<details>
   <summary>View pseudocode model solution</summary>
   <table>
   <tr><td>
function REVERSE(s)<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;let s' be a copy of s<br>
&nbsp;&nbsp;&nbsp;&nbsp;let n = |s|<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; for i = 1 to n do<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; s'[i] = s[n - i + 1]<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; return s'
   </td></tr>
   </table>
</details>
</blockquote>


###  Block 2
------------

#### Problem 5: Find maximum

Write a function that given a list of numbers it output the biggest one. The
point is to loop over all the input numbers so please do **NOT** use any 
pre-existing _max_ functions. If the input is empty return nothing.

<blockquote>
<details>
   <summary>Example</summary>

- Input: _1 2 4 5 8_
- Output: _8_

</details>
</blockquote>


<blockquote>
<details>
   <summary>View pseudocode model solution</summary>
   <table>
   <tr><td>
function MAXIMUM(L)<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; m = L[1]<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; for i = 2 to |L| do<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; if m < L[i] then <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; m = L[i]<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; return m<br> 
   </td></tr>
   </table>
</details>
</blockquote>

#### Problem 6: Pizza count 

Imagine you had a lot of friends and you were all at a pizzeria trying to
order. In this situation, in order to help the waitress you volunteer to keep
a count of how many pizzas of each type you will order as a group. Write a 
function that given a list of pizzas prints how many of each you will order.
The output should be alphabetically ordered as in the output example.

<blockquote>
<details>
   <summary>Example</summary>

- Input:<br>
 Pepperoni<br> 
 Hawaiian<br> 
 BBQ<br> 
 Veggie<br> 
 Hawaiian<br> 
 BBQ<br> 
 Cheeses<br> 
 BBQ<br>

- Output:<br>
    Cheeses: 1<br>
    Hawaiian: 2<br>
    Pepperoni: 1<br>
    Veggie: 1<br>
    BQQ: 2 
</details>
</blockquote>

<blockquote>
<details>
   <summary>View pseudocode model solution</summary>
   <table>
   <tr><td>
function ORDER-PIZZA(L)<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; let D be an empty dictionary <br><br>
&nbsp;&nbsp;&nbsp;&nbsp; for x in L do<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if x ∈  D then <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; D[x] = D[x] +1<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;else<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;D[x] = 1<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; return D<br>
   </td></tr>
   </table>
</details>
</blockquote>



#### Problem 7: ESCI colors

You have just got sent and email by ESCI administration. They want to change
their official color from _Blue_ to another one. They asked the students which
color they think best fits the institution. They now ask you to write a 
function that takes all colors proposed by students which will passed to the
marketing team. Your function should return all the colors **excluding _Blue_** in alphabetical order.

<blockquote>
<details>
   <summary>Example</summary>

   - Input:<br>
      _Red<br> 
      Blue <br> 
      Red <br> 
      Green <br> 
      Orange <br> 
      Violet<br> 
      Violet <br> 
      Green_<br> 

  - Output:<br> 
     _Green<br> 
     Orange<br> 
     Red<br>
     Violet_<br>
</blockquote>
</details>

<blockquote>
<details>
   <summary>View pseudocode model solution</summary>
   <table>
   <tr><td>
function COLORS-SET(L)<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; let S be an empty set<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; for all x in L do<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; if x is no Blue then<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; S = S U {x}<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; let L' be a list with all the elements in S<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;  return sorted L'<br>
   </td></tr>
   </table>
</details>
</blockquote>



#### Problem 8: Fill the rows

As a teacher in an exam day, you need to assist the students to find where they
need to sit. There are three rows in the class,  students need to fill all
the _ith_ place of all rows before moving onto the _i+1th_ place of the 1st
row. For example the 1st positions of the 1st row is filled, then the 1st of
the second row and then the 1st of the 3rd, then, the 2nd of the 1st, 2nd of
the 2nd, and so on. Write a function that takes a list of students and returns
3 list corresponding to the 3 rows. 

>NOTE: for this problem do **not** use matrices, use three different lists. 

<blockquote>
<details>
   <summary>Example</summary>


- Input:<br>
  _Anna A.<br> 
  Jordi A.<br> 
  Jorge B. <br> 
  Marc C. <br> 
  Antonio F. <br> 
  Violet P.<br> 
  Adria P. <br> 
  Maria Z._<br> 

- Output:<br> 
   _Row 1: Anna A., Marc C., Adria P._<br> 
   _Row 2: Jordi A., Antonio F.,  Maria Z._<br> 
   _Row 3: Jorge B., Violet P._ <br> 
</details>
</blockquote>

<blockquote>
<details>
   <summary>View pseudocode model solution</summary>
   <table style="padding-left: 80px";>
   <tr><td>
function FILL-THE-ROWS(L)<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;n = |L|<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;let row1 be an empty list<br>
&nbsp;&nbsp;&nbsp;&nbsp;let row2 be a copy of row1<br>
&nbsp;&nbsp;&nbsp;&nbsp;let row3 be a copy of row1<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;for i = 1 to n do<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;row1.append(L[i])<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if i+1 <= n then <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;row2.append(L[i+1])<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if i+2 <= n then  <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; row3.append(L[i+2])<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; i = i +3<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; let Outlist be a list containg row1 row2 and row3<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;return Outlist<br>
   </td> </tr>
   </table>
</details>
</blockquote>

----

### Extra exercise: Elections day 


This year you will have to decide again who you want your class representative
to be. You will be the one counting the votes this year. Since you are very
smart, you decide to write a program that does the work for you. Write a
function that takes as input a list of names and returns the most repeated
name. In case of a tie, use alphabetical order to decide. For this exercise
do not use a dictionary. 

<blockquote>
<details><summary>Example</summary>

- Input:<br>
Anna<br>
Marta<br>
Jordi<br>
Pau <br>
Anna <br>
Emma <br>
Jordi<br>
- Output: _Anna_
</details>
</blockquote>

<blockquote> 
<details> 
   <summary ">Small clues to find the solution</summary>

This algorithm is not easy to find. Here there are some clues to lead you the
way. They are not in any specific order and do not tell you what to 
write, but each one of them contains a small bit of code information.<br>
Think hard and try different things before looking at the solution!<br>

- The spotlight is yours until someone changes it.<br>
- Having a counter for each possible student is having too much counters. How
about a single one?<br>
- Keeping track of which student is being voted, is hard if their names are
all over the place, isn't it?<br>
- If you have a list of names, why not traverse it?<br>
- The winner is the winner until someone gets more popular.<br>
- Do not forget the last vote!<br>

</details>
</blockquote>

            
<blockquote> 
<details> 
   <summary ">View pseudocode model solution</summary>
   <table ">
   <tr><td>
function ELECT-STUDENT(L)<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; sort L <br>
&nbsp;&nbsp;&nbsp;&nbsp; let votes = 0 <br>
&nbsp;&nbsp;&nbsp;&nbsp; let winner be an empty string<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; for all x in L do<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if winner is empty then<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; winner = x <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; let current_votes = 0 <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; let current_student = x <br><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if x = current_student then<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; current_votes = current_votes +1<br><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;else<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if current_votes > votes then <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; winner = current_student<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp; votes = current_votes<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;current_student = x <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;current_votes = 1 <br><br>
&nbsp;&nbsp;&nbsp;&nbsp; if current_votes > votes then<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return current_student<br><br>
&nbsp;&nbsp;&nbsp;&nbsp; return winner
   </td></tr>
   </table>
</details>
</blockquote>


