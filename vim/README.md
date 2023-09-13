# Vim

You might be asking, what the hell is `Vim`? Well my friend, let me tell you.
`Vim` is not just a text editor as many might call it; `Vim` is portability,
`Vim` is smoothness, `Vim` is speed, and it is fully customizable (from key
mappings to plugins). For instance, there's one plugin that allows you to
control Spotify  from within it, while editing a file. How rad is that?
Okey, maybe, you are trying to find a more practical example, so picture this:

You have to run a script on a cluster, which does not have the same
specifications as you computer and therefore, you don't know how your script
might behave or what problem you will have to face. In this scenario, there
are two possible ways to act; on the left, you can see the steps to do when you
don't use `Vim`, on the right, the steps to take when you do use `Vim`.

<br>
<p align="center">
  <img width='360' height='400' src="https://github.com/deliaBlue/laPrepa/assets/103108590/7df60816-80dc-4831-bc41-619c91ec76fc">
</p>


Do you see now one of its many advantages now?

But as amazing as it sounds, `Vim` is not very friendly at first. Among all
the things `Vim` can be, fancy is not one of it. There are no cool pull-down
menus or mouse-driven events, it's just your keyboard, `Vim` and you. This
implies that you will have to make a small effort to get to know `Vim`, and
believe me when I say **it is worth it**.

## Bits to Discover Vim

1. [`Vim` Modes](#Vim-modes)
    - [Normal Mode](#normal-mode)
    - [Insert Mode](#insert-mode)
    - [Visual Mode](#visual-mode)
    - [Replace Mode](#replace-mode)
2. [`Vim` Motions](#vim-motions)
    - [`Vim` Motions I](#motions1)
    - [`Vim` Motions II](#motions2)
3. [`Vim` Operators](#vim-operators)
    - [`Vim` Operators I](#operators1)
    - [`Vim` Operators II](#operators2)
4. [Search, Find and Replace](#search-find-and-replace)
    - [Search in `Vim`](#search)
    - [Find and Replace in `Vim`](#findrep)
5. [Save and Exit `Vim`](#save-and-exit-vim)
6. [Extra Resources](#extra-resources)


## `Vim` Modes

As everyone, `Vim` has its moods, we will call them **modes**. Depending on
where you look, you can find from 4 to 7 **modes**. We will explain only 4 (and
try to keep it as easy as we can)

Before, entering the different **modes**, there is a small thing to be
mentioned. Suppose you create a new file called `file.txt` with `Vim` using the
**command**

```bash
vim file.txt
```

Your screen will look something like this



<p align="center">
   <img width="460" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/caf1c52e-7d41-4336-9240-a787f4095c26">
</p>

The white square indicates the cursor position while the tilde (`~`) lines
indicate lines that are not in the file, _i.e._ when `Vim` runs out of file to
display, it displays tilde lines.
Finally, at the bottom of the screen, a message line indicates the name of the
file (when the file is not new it will display other information such as the
number of lines or bytes the file has). In this line, other relevant
information will be seen; for instance the **mode** you are in, or the
**command** you are typing.


### Normal Mode

In **Normal mode** (the default **mode** when launching `Vim`, also known as 
**Command mode**) you cannot write. When in **Normal mode**, you will be able
to navigate the text, copy/cut/paste characters, words and lines, roll-back
actions, write commands and much more.

The fastest way to get to the **Normal mode** from any other **mode** you are
in, is to press the `<ESC>` key (sometimes twice). Another way, a faster way
if you don't want to _move your hands from the main keys_ is `<Ctrl-C>`.


### Insert Mode

In **Insert mode** you will be able to modify the text in your files the same
way you would in most text editors. There are different ways to enter the
**Insert mode**, three of them are:

- `i` (for "**i**nsert"). This will immediately switch `Vim` to **Insert**
**mode**.
- `a` (for "**a**ppend"). This will move the cursor after the current char
and enter **Insert mode**.
- `o`. This will insert a new line bellow the current line and enter **Insert**
**mode** on the new line.

These commands have an uppercase counterpart, but we will mostly work with
these three (and most probable only with `i`). You will know you are in the
**Insert mode** because at the bottom of the window `Vim` will display
`--INSERT--`.

<p align="center">
   <img width="460" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/5efc3c54-6924-4ea5-8537-404cd81067e8">
</p>

Now you can write whatever you fancy, for instance...

<p align="center">
   <img width="460" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/5c4ded77-cc42-4e4e-a952-6a39f404c1a5">
</p>


If you press `<ESC>` or `<Ctrl-C>` to return to **Normal mode**, the last line
will be blank. **BE CAREFUL**, this does **NOT** imply you have saved the file.


### Visual Mode

In **Visual mode** you will be able to visually highlight (select) text areas
and run commands on them (something similar to how clicking and dragging with
a mouse behaves). There are three different variants for **Visual mode**, each
of which can be access in a different way:

- `v` (for "**v**isual"). This will enter **Visual mode** and mark a starting
selection point. The selection here, will be made char by char. If you are in
a line and switch to the one bellow or above, the cursor will move to the same
char in that line and select all the text in between.
- `V` (for "**V**isual line"). This will enter **Visual line mode** and mark the
whole line the cursor is in. As the name suggests, the selection here will be
made line by line.
- `<Ctrl+V>` (for "**v**isual block"). This will enter **Visual block mode**
and mark a starting selection point. The selection here, will be made as in
the standard **Visual mode** but if you move one line above or bellow, the
selection will be made rectangle-wise or in blocks.

When you enter the standard **Visual mode**, the char you are on will be
selected (for instance, the `b` from `because`) and `Vim` will display in the
bottom of the window the following:

> NOTE: From here, when the cursor is over a character or a set of characters
are selected, instead of the actual square you would see on your terminal,
that character(s) will be underlined.

<p align="center">
   <img width="460" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/02533d75-199b-44ab-8516-f46c8d428e01">
</p>


If you now move, the positions you are passing by will also be selected:


<p align="center">
   <img width="460" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/01250533-a138-4a3b-a2e0-1325a78127ca">
</p>


When you enter the **Visual line mode**, the line you are on will be
selected (for instance, the second one) and `Vim` will display in the
bottom of the window the following:

<p align="center">
   <img width="460" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/e9a94773-c8dd-47f1-8bc9-15d31e2e7937">
</p>


Finally, when you enter the **Visual block mode**, the char you are on will be
selected (for instance, the `f` from `funny`) and `Vim` will display in the
bottom of the window the following:

<p align="center">
   <img width="460" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/09ce8622-afdd-436a-8d99-ff1d749a736c">
</p>


Now, suppose you move one position to the left and to the upper line. Only the
four positions in that square will be the only ones selected:

<p align="center">
   <img width="460" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/899d9d83-eeb5-4617-b9d9-bdd2c4ca5c9c">
</p>



Again, remember that to exit **Visual mode** and enter **Normal mode** you just
have to press `<ESC>` or `<Ctrl-C>`

### Replace Mode

In **Replace mode**, as the name suggests, you will be able to replace the
char where the cursor is. There are two ways to enter **Replace mode**:

- `r` (for "**r**eplace"). When you enter the **Replace mode** this way, no
message will be displayed on the bottom of your screen and you will be able
to ONLY replace the char the cursor is in. Then, you will be back to the
**Normal mode**.
- `R` (for "**R**eplace"). When you enter the **Replace mode** this way, you
will be able to replace as many chars as you want until you go back to the
**Normal mode**.

Suppose you only want to change the `T` from `True`. Once over that char, the
sequence will be `r t`.
Now, if you enter **Replace mode** with `R`, the first thing you will see is
the **mode** in the bottom of your screen.

<p align="center">
   <img width="460" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/f96f4041-63e2-4628-ad9b-b726d772dd95">
</p>

Now, every key you press (except for the arrows and `<ESC>`) will change the
char where the cursor is and the cursor will move one position to the right.

## `Vim` Motions

Learning `Vim` is a bit like learning a new programming language, it has its own
syntax. Even if at first it will be hard for you to remember everything, after
some time, you won't be able to work in any other way.

> IMPORTANT NOTE: All of what is about to be explained is done in the
**Normal Mode** unless stated otherwise.

---

<a name="motions1"></a><p align="center"><b>Vim Motions I</b></p>

A **motion** is anything that moves the cursor, and one of the first things
everyone will tell you about `Vim` is how to move the cursor without using
the mouse usage just the keyboard. I know what you must be thinking:

<p align="center"><i>What's the problem with that? Just use the arrow keys!</i></p>

Well, that's clearly a valid option, but it's not the `Vim` option. In `Vim`,
the main idea is not to move your hands from the text keys - and remember that
there are some keyboards that do not have arrow keys or they are on weird
places. With this premise, the keys you should use to move within `vim` are:

<p align="center">
<code>h</code> to move to the <b>left</b><br>
<code>j</code> to move <b>downwards</b><br>
<code>k</code> to move <b>upwards</b><br>
<code>l</code> to move to the <b>right</b><br>
</p>

Yeah, it is odd to use `l`  in order to go to the **r**ight, but you will get
used to it. One thing you can use to remember these keys, is that the `j` is
similar to a down arrow or think of this diagram:

<br>

<p align="center">
  <img width='160' height='170' src="https://github.com/deliaBlue/laPrepa/assets/103108590/57cf0d93-4300-490b-a534-71aa506e98f7">
</p>

Moving one character/line at a time does not seduce you at all, I know, and
`Vim` knows. That's why you can add a **count** to your **motion**. This
**count** will define how many **motions** are to be made. For instance,
using the same example as before, if your cursor was after the word `True`,
and you wanted to go to the `T`, you could press `hhhh` or you could type
`4h`.

<p align="center">
  <img width='460' height='300' src="https://github.com/deliaBlue/laPrepa/assets/103108590/7778215c-2525-4e38-aa47-8d0bd96eff36">
</p>

Again, using the arrow keys is fine, but you should get used to this way of
movement; do not take it as a priority but as a thing to improve your speed in
`Vim`.

<blockquote><details>
    <summary>Improve your motions and be the best!</summary>
    <br>

In the [attached file](hjkl_race.txt), you will find a maze. Download it and
once you open it with `Vim`, the cursor will be placed at the starting line
(position 0,0). Use only they `h j k l` keys to navigate through it.

- Your **objective** is to follow the path to the end while avoiding the
poisonous water (`~`). If you touch the water, go back to the start (also using
`h j k l`).
- The **numbers** `100`, `200`, `300` and `400` represent the number of
keystrokes from the start to reach that point in the race.
- **Expect to struggle**. Everyone does with `Vim` at first.
- There are two levels:
  - **Level 1**: Make one motion at a time.
  - **Level 2**: Use counts and motions at all times.

**Time yourself** and send us your time(s) and level(s) and we will set a
ranking. Good luck and **HAVE FUN!**

</details>
</blockquote>


---

<a name="motions2"></a><p align="center"><b>Vim Motions II</b></p>

In this section, three more different **motions** will be explained.

1. **Word Movement**

Even with a **count**, sometimes you just want to be faster in your horizontal
**motions** or you just simply don't want to count how many characters you
have until your target position. For this reason, you can move forward and
backwards one word at a time.


<p align="center">
<code>w</code> to move to the <b>beginning of the next word</b><br>
<code>b</code> to move to the <b>beginning of the previous word</b><br>
<code>e</code> to move to the <b>end of the next word</b><br>
<code>ge</code> to move to the <b>end of the previous word</b><br>
</p>

As with the previous **motions**, here you can also add the number of words you
want to advance or go backwards. This time, the cursor is under the `b`,
and if you want to go to the `T` in `True`, you can either type `wwww` or `4w`.

<p align="center">

<img src="https://github.com/deliaBlue/laPrepa/assets/103108590/7b339983-7a0c-4d6f-8b93-7324c4a5d5b8" style="width:49%">
<img src="https://github.com/deliaBlue/laPrepa/assets/103108590/f4f39dbd-7536-4733-991e-0416ec672699" style="width:49%">

</p>

2. **Line Movement**

As you can imagine by now, using `{count}e` to go to the end of the line or
`{count}b`, is not fast enough for `Vim`. That's why the **motions** `0` and `$`
exist.

<p align="center">
<code>0</code> to move to the <b>beginning of the line</b><br>
<code>$</code> to move to the <b>end of the line</b><br>
</p>

This time, the only **motion** with a **count** is `$`. If you add a **count**
to this **motion**, you will jump to the end of the number of lines state in
the **count** bellow yours. Starting at the same position as before, this is
how your cursor would behave.


<p align="center">
  <img width='460' height='300' src="https://github.com/deliaBlue/laPrepa/assets/103108590/7ff61909-7d4c-451c-96db-1ab64925add4">
</p>

<table style="padding-left: 150px;padding-right:150px;">
<tr><td>
<p align="center"><b>Jumping with f and t</b></p>

Sometimes, you just want to go to the first occurrence of a certain character
in the line you are in. In order to do so, you can use the following
**motions**:

<p align="center">
<code>f{char}</code> to jump to the <b>next occurrence</b> of character {char}
<code>F{char}</code> to jump to the <b>previous occurrence</b> of character {char}<br>
<code>t{char}></code> to jump <b>before the next occurrence</b> of character {char}<br>
<code>T{char}></code> to jump <b>before the previous occurrence</b> of character {char}<br>

</p>
</td></tr>
</table>
<br>

Now you know how to move **horizontally** through a line, but what about the
**vertical motions**? We've seen that by using `j` and `k` we could jump
from line to line. But, what if you know exactly to which line you want to go?
Surely you will end up finding a way, something like `9999k` to go to the top
of the file and then `#j` where `#` is the line number you want but, what a
waste of keystrokes. In order to go to a specific line, the `G` **motion**
is what you are looking for.

Imagine you want to go to line 88, then the sequence you would type is `88G`.
No matter at what line you are at, if line 88 is in your file, you will jump
there. If there is no line 88, or you don't add a **count** to this **motion**,
you will jump to the end of the file. Hold on, there's another small little
improvement `Vim` decided to add. If you want to go to the first line of your
file, you could now use `1G` and by doing so, you would have to move your
fingers from the text keys. To avoid this, if you want to go to the first line
of your file, you just have to type `gg`; easy, fast and handy. In this new
example, the cursor is at line 7; to go to line 3 `3G` is used and to go at the
bottom of the file `gg` is typed.


<p align="center">
  <img width='460' height='300' src="https://github.com/deliaBlue/laPrepa/assets/103108590/26e80dfd-4c30-48e2-b33f-01460e8af23b">
</p>

> NOTE: You can also jump to a particular line with `:line_number`.

3. **Scrolling**

One last thing you can do with your mouse is to scroll up and down. And yes,
you can also do it with `Re Pag` and `Av Pag` but, where are these keys? Maybe
you have them along the arrow keys so to use them you have to additionally
press `Fn`, or maybe you have them alone at the right side of your keyboard.
Again, all options are far from the text keys, that's why four **motions**
are here to save the day.


<p align="center">
<code>< Ctrl-U ></code> to move <b>up half a screen of text</b><br>
<code>< Ctrl-D ></code> to move <b>down half a screen of text</b><br>
<code>< Ctrl-B ></code> to move <b>backwards a whole screen of text</b><br>
<code>< Ctrl-F ></code> to move <b>forward a whole screen of text</b><br>
</p>

Bellow there's a representation of what these **motions** do. There's no fancy
shell this time, but you can get the concept.

<p align="center">
<img src="https://github.com/deliaBlue/laPrepa/assets/103108590/a883d3f5-9514-4052-a45d-dfcfc09d48d6" style="width:48%">
<img src="https://github.com/deliaBlue/laPrepa/assets/103108590/e38ed2b1-258a-4eb3-baef-f95b231828b4" style="width:51%">
</p>

---



## `Vim` Operators

Until now, you have seen some basic **motions** to navigate a file. Now, we will
see some **operators** to edit a file.


Previously, we've seen that **motions** can be altered when adding a **count**
in front of them. When working with **operators** you can combine them
with **motions** and, if they allow it, add the **count**.

<p align="center">
   <img width="460" height="300" src="https://www.barbarianmeetscoding.com/images/vim-operators.jpg">
</p>

Using this combination will not only help you on the exercises but in getting
faster and more efficient when working with `Vim`.

<table style="padding-left: 150px;padding-right:150px;">
<tr><td>
<p align="center"><b>Undo and Redo</b></p>

All **operators** modify text. If you do something in a way you did not intend,
or a key combination does not what you expect, or you just _undo_ too many
times, there are a couple of commands that will save your day:

<p align="center">
<code>u</code> to <b>undo</b> the changes
<br><code>< Ctrl-R ></code> to <b>redo</b> the undo
</p>

</td></tr>
</table>
<br>

If you only want to read what's in this section is fine. However, we highly
recommend, that you open the file [code_along](code_along.md) and practice the
**operators** at your own pace. For those willing to follow the exercises,
there will be pull-down menus with the key combination(s) and what you should
have as the result of them for you to see and even improve. Even if it is hard
at first, we encourage you to try to use **counts** with the **motions**,
_i.e_ use `3j` instead of `jjj`.

> IMPORTANT NOTE: All of what is about to be explained is done in the
**Normal Mode** unless stated otherwise.

---

<a name="operators1"></a><p align="center"><b>Vim Operators I</b></p>

The first **operators** you need to learn to work with are:

<p align="center">
<code>y</code> to <b>y</b>ank (copy) text<br>
<code>d</code> to <b>d</b>elete text<br>
<code>p</code> to <b>p</b>aste text<br>
<code>c</code> to <b>c</b>hange text<br>
</p>

Each of these **operators** has it own peculiarities. Lets take a look at them.

1. **Copy / Paste**

Copy and paste go hand in hand, that's why they have a section in together.
Just a small note, from now one, instead of _copy_, I will say _yank_; you
know; `Vim` jargon.

There are a lot of ways to yank specific bits of text. Here you will see the
ones you will use the most, but in the exercises you will be challenged to use
the **motions** we've previously seen.

<p align="center">
<code>yy</code> to yank the <b>whole line</b><br>
<code>y{count}w</code> to yank <code>{count}</code> <b>w</b>ords after the
cursor<br>
<code>y{0, $}</code> to yank from the cursor until the <b>beginning</b>
(<code>0</code>) / <b>end</b> (<code>$</code>) of the line<br>
<code>y{count}{j,k}</code> to yank <code>{count}</code> lines <b>downwards</b>
(<code>j</code>) / <b>upwards</b> (<code>k</code>)<br>
</p>

Prior to an example, lets see the two different options to paste in the
**Normal mode**.

<p align="center">
<code>p</code> to paste <b>after</b> the cursor position<br>
<code>P</code> to paste <b>before</b> the cursor position
</p>


Now, picture this, you need a to build a script that looks like this:

```python

def random_function(x, y):

   if x > y:
      return x + y

   elif x < y:
      return x - y

   return 404  
```

You write the header of the function and the first conditional and return to
**Normal mode**. Your cursor will be place over the `y`. Then, in order to 
yank the line you are in, the conditional and the blank line above you type
`y2k`. This will place the cursor on the last line you yanked and a message
will appear in the bottom of the screen.

<p align="center">
   <img width="760" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/9ebb92b2-f918-475f-b416-738bca205234">
</p>

Then, you return to the initial position (maybe with `3$`) and then paste with
`p` what you have just yanked. See the message in the bottom of the screen.

<p align="center">
   <img width="760" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/9ee9da97-2d6d-4555-9ddd-8c0ad2b3951d">
</p>

Now you just have to add `el` in front of the `if`, replace the `>` by a `<`
and the `+` by a `-`. Do you remember how?


<blockquote>
<details>
  <summary>Time to code along!</summary>
  <br>

<table>
<tr>
<th>Version 1</th><th>Version 2</th></tr>
<tr><td>

```
3j
3w
y4e
11G
$P
18G
$P
24G
$P
```
</td>
<td>

```
3j
fkyt,
:11
$P
:18
$P
:24
$P
```

</td></tr>
</table>


You, that decided to practice, that are willing to push your knowledge further,
I will reward you with a very useful usage of yank and paste.

<table style="padding-left: 150px;padding-right:150px;">
<tr><td>
<p align="center"><b>Copy to and paste from the outside</b></p>


What you yank in <code>Vim</code>, does not go to the system clipboard, so you
cannot paste it outside <code>Vim</code>.<br> What you copy outside
<code>Vim</code>, does not go to the <code>Vim</code> buffer, so you cannot
paste it in the file.

To achieve that, there are these two commands:

<p align="center">
<code>"+y{count}{motion}</code> to yank <b>to</b> the system clipboard
<br><code>"+p</code> to paste <b>from</b> the system clipboard
</p>

</td></tr>
</table>

</details>
</blockquote>


2. **Delete**

Knowing how to delete text is as important as knowing how to write it. It is
common sense that while in the **Insert mode**, you can just delete as you do
normally; `<DEL>` to delete backwards and `<SUPR>` to delete forward. But if
you are navigating a file a see some things to be erased, changing the **mode**
is a bit tedious. 

As before, there are a lot of combinations to delete specific bits of text, but
we will only see the ones you will be using the most.

<p align="center">
<code>x</code> to delete a <b>single character</b><br>
<code>dd</code> to delete the <b>whole line</b><br>
<code>D</code> to delete from the cursor to the <b>end</b> of the line<br>
<code>d{count}w</code> to delete <code>{count}</code> <b>w</b>ords after the
cursor<br>
<code>d{count}{j,k}</code> to delete <code>{count}</code> lines <b>downwards</b>
(<code>j</code>) / <b>upwards</b> (<code>k</code>)<br>
</p>


:bulb: **Tip:** When you delete something, you are actually cutting it. This
means that you can then paste it afterwards!

Heading back to our `random_function`. You've finished it and decide that
there's no need of doing anything if `x` is not bigger than `y`; the central
condition can be removed. To do so, you place your cursor on the `elif` line
and type `3dd` (which is the same as `d3j`).


<p align="center">
   <img width="760" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/9741829a-fc1d-42c1-8e28-3a8a3b0143cd">
</p>


<blockquote><details>
  <summary>Time to code along!</summary>
  <br>


<table>
<tr>
<th>Version 1</th><th>Version 2</th></tr>
<tr><td>
Part 1

```
38G
fBdts
26G
w 
dw
7G
2w
dw
G
3w
dw
43G
$2b
dw
10G
fm
dw
14G
5w
dw
w
dw
22G
3w
dw
```

Part 2

```
46G
$2h
x
21G
4w3l
x
7G
$
2b2l
rh
30G
$
bx
48G
2w
rt
37G
$X
```

</td>
<td>

Part 1

```
:38
fBdts
:26
fFdiwx OR fFdta
:7
3ediwx
:G
fLdtP
:43
/lion
diwx
:10
/chi
nbdiwx
:14
/one
diwx
ee
diwx
:22
/run
dta
```

Part 2

```
:21
$bbfgx
:7
:s/otter/other
:30
fkx
:48
fbrt
:37
$jx
```

</td></tr>
</table>

</details>
</blockquote>



3. **Change**

You can think of this **operator** as a fast `d{count}{motion}  i` (delete
and enter **Insert mode**). Due to its nature, it works exactly as the
`d` **operator**, that's why for the change **operator** four specific
combinations will be explained.


<p align="center">
<code>ci"</code> to change all the <b>inner</b> content within two double quotes<br>
<code>ci(</code> to change all the <b>inner</b> content within two parenthesis <br>
<code>ci{</code> to change all the <b>inner</b> content within two curly brackets<br>
<code>ci[</code> to change all the <b>inner</b> content within two square brackets
</p>

Lets retake our `random_function` once more. This time, you decide to give the
arguments more significant names than `x` and `y`. You decided to start by the 
function definition statement, so you put your cursor in that line. Once there
to change the `x` and `y` names, you just write `ci(`.

<p align="center">
   <img width="760" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/6ed7c289-48ee-4df0-be18-1e4e28fee1e2">
</p>

Everything between the parenthesis has been removed, the cursor is after the
first parenthesis, and you are now in the **Insert mode** ready to type the new
names.

<blockquote><details>
  <summary>Time to code along!</summary>

<table>
<tr>
<th>Version 1</th><th>Version 2</th></tr>
<tr><td>

```
28G
ci(
as all men know,
  in this kingdom by the sea

<ESC>
```
</td>
<td>

```
:28
Jci(as all men know, in this kingdom by the sea
<ESC>
F,a
<ENTER>
<TAB>
```

</td></tr>
</table>
  <br>
</details>
</blockquote>


<table style="padding-left: 150px;padding-right:150px;">
<tr><td>
<p align="center">Copy, Paste and Cut in <b>Visual mode</b></p>

When in <b>Visual mode</b> (any of them), you can use these actions over
the selected text just by pressing the desired **operator** once.
</td></tr>
</table>

---

<a name="operators2"></a><p align="center"><b>Vim Operators II</b></p>

Before switching on to another topic, there are four more **operators** to be
seen.

<p align="center">
<code>>{count}{motion}</code> shift line(s)<code>{count}</code> tabs to the right<br>
<code><{count}{motion}</code> shift line(s)<code>{count}</code> tabs to the left<br>
<code>gu{count}{motion}</code> to switch <code>{count}{motion}</code> to lower-case<br>
<code>gU{count}{motion}</code> to switch <code>{count}{motion}</code> to upper-case<br>
</p>

:bulb: **Tip:** If you just want to switch the case of a single character,
place the cursor over it and type `~`.

<blockquote><details>
  <summary>Time to code along!</summary>

<table>
<tr>
<th>Version 1</th><th>Version 2</th></tr>
<tr><td>

Part 1

```
17G
0
<Ctrl-V>
7j
2<
41G
0
<Ctrl-V>
8j
5<
```

Part 2

```
gg
<Ctrl-V>
47j 
```
</td>
<td>

Part 1

```
:17
qr0xxjxxxxjq3@r

:41
h
<Ctrl-V>
07jx
```

Part 2

```
gg
jj
<Ctrl-V>
G0~
```

</td></tr>
</table>

  <br>

</details>
</blockquote>



<table style="padding-left:150px;padding-right:150px;">
<tr><td>
<p align="center">Shifting in <b>Visual mode</b></p>

When in <b>Visual mode</b>, there are two way to shift text depending on the
<b>Visual mode</b> you are in.

- <b>Visual</b> and <b>Visual Line</b>. In these two **modes** you will always
shift the whole line(s) no matter you position on it.<br>
- <b>Visual Block</b>. When in this **mode**, you will always shift from the
first position of your selected block.

</td></tr>
</table>

---

## Search, Find and Replace

> NOTE: After typing any of the commands in this section, you need to press
`<ENTER>` unless specified otherwise.

---

<a name="search"></a><p align="center"><b>Search in Vim</b></p>

You have been making notes for your finals the whole trimester but during the
recap session, you realize there are some details you did not wrote down. Once
at home, you open your notes on `Vim` and all of the sudden, you become aware
of the fact that you have no clue in which sections you have the incomplete
concepts but you know the keywords around them. 

<p align="center">
<code>/pattern</code> to search for a pattern forward<br>
<code>?pattern</code> to search for a pattern backwards
</p>

If the pattern is found, the cursor will appear at the beginning of the
pattern. You can go its next instances within the file by
pressing `n`. If you want to go to any previous instance use `N`.


:bulb: **Tip:** In order to make searches not case sensitives, in
**Normal mode** type `:set ignorecase` and hit `<ENTER>`. Now, _Word_, _WORD_
and _word_ will be considered the same.

In the following example, there's no cursor so you can see the movements in
only two pictures. We start with the cursor in the second line of the left
window. After searching for _laPrepa_, the cursor goes to the fourth line in
the right window. From there, we go to either the last line with `n`, or two
the first one with `2N`. The `X` indicates the line in which the cursor is
after the **command**.

<p align="center">
   <img width="800" height="220" src="https://github.com/deliaBlue/laPrepa/assets/103108590/93de0fe7-4851-4206-b164-c0290a03ac85">
</p>

When you press `/`, it will be typed  at the bottom of the screen, and the
pattern you write will, in fact, by typed there. As a final note on this
section, when you search for a pattern, you can apply any **operator** to
it, and then press `n` (or `N`) to locate the next one and do the same.

<blockquote><details>
  <summary>Time to code along!</summary>

<table>
<tr>
<th>Version 1</th><th>Version 2</th></tr>
<tr><td>

```
gg
2w
dw
/Ammabel
$P n
$P n
$P n
$P n
$P n
$P n
$P n
```
</td>
<td>

```
/Lee
diwx

/Ammabel
ciwAmmabel Lee
<ESC>
n.n.n.n.n.n.
```

</td></tr>
</table>

  <br>


You, that decided to practice, that are willing to push your knowledge further,
I will reward you with a very useful trick for searching.

<table style="padding-left: 150px;padding-right:150px;">
<tr><td>
<p align="center"><b>Search Without a Pattern</b></p>

A fastest way to look for a pattern, is to place your cursor over that word and
use `*`. This **command** will lead you to the next instance of that word. That
way, if you see a typo, one you usually do, you just have to be on that word
and fix it along the file.

</td></tr>
</table>
</details>
</blockquote>



---

<a name="findrep"></a><p align="center"><b>Find and Replace in Vim</b></p>

Another very useful thing, is to find and replace. There are several ways
to do that, but we will focus mainly in two of them.

<p align="center">
<code>:%s/old/new/g</code> to replace all <i>old</i> in the file by <i>new</i><br>
<code>:%s/old/new/gc</code>  to replace all <i>old</i> in the file by <i>new</i> but asking for confirmation
</p>

As well as with the pattern searching, once you type the colon (`:`), it will
appear at the bottom of the screen (as well as everything you type
afterwards).  **MIND** that all **commands** that start with `:` will behave
the same.

Suppose you have the following script:

```python
import sys
from math import prod

s = sys.stdin.readline().strip()
feetSqr = 0

while s != "":
    
    size = sorted([int(dim) for dim in s.split('x')])
    ribbon = 1
    feetSqr += 2*s[0]+ 2*s[1] + prod(s)

    size = sys.stdin.readline().strip()

print(feetSqr) 
```

You realize that the same variable has two different names, `s` and `string`.
Using find and replace in the whole files is dangerous as a bunch of words
start with _s_. Therefore, you type `:%s/s/size/gc`, and have this screen:


<p align="center">
   <img width="460" height="300" src="https://github.com/deliaBlue/laPrepa/assets/103108590/58c667ae-f87f-4b42-9822-2e33c81d1e14">
</p>

The provided options are:

- `y` -> **Y**es
- `n` ->  **N**o
- `a` -> **A**ll; make this change and all the remaining ones without further
confirmation
- `q` -> **Q**uit; don't make any more changes
- `l` -> **L**ast; make this change and quit
- `<Ctrl-E>` -> Scroll the text one line up
- `<Ctrl-Y>` -> Scroll the text one line down


<blockquote><details>
  <summary>Time to code along!</summary>


```
:%s/Ammabel/Annabel/g
```

You, that decided to practice, that are willing to push your knowledge further,
I will reward you with a very useful trick for a better find and replace
strategy.

<table style="padding-left: 150px;padding-right:150px;">
<tr><td>
<p align="center"><b>Find Exactly Matching Pattern</b></p>

The seen example shows one of the perks of using this **command** as it is.
If you want `Vim` to only find the words that fully and exactly match your
pattern, use the following

<p align="center"><code>:%s/\< old\>/new/gc</code></p>

</td></tr>
</table>
</details>
</blockquote>

---

## Save and Exit `Vim`

Now that you have all this new knowledge, you are probably impatient to know
how to save, exit, or exit without saving your changes.

Be aware that bellow this section, there are some extra useful and cool 
resources. If you are reading this in `Vim` do not quit before seeing them!

<p align="center">
<code>:w</code> to <b>w</b>rite (save)<br>
<code>:wq</code> to <b>w</b>rite and <b>q</b>uit (save and exit)<br>
<code>:q</code> to <b>q</b>uit<br> 
<code>:q!</code> to <b>q</b>uit without saving
</p>


## Extra Resources

[Vim Cheat Sheet 1][vim-cheat1] | [Vim Cheat Sheet 2][vim-cheat2]

[Boost Your Coding Fu with VSCode and Vim][vim-boost]

This is a very cool (free) book that takes your hand while you first connect
with `Vim` and increases little by little the difficulty while blending all you
have previously seen.

[Vim Genius][vim-genius]

This is an interactive way to practice and master the different concepts taught
by `VimTutor`.

[Vim Help][vim-help]

This is the complete `Vim` help file, the same one you would find if you type
`:help` within `Vim`.

[Vim Hero][vim-hero]

`VimHero` is another interactive way of learning `Vim`, with the stress put on
the **Normal** and **Insert Modes**. It features interactive examples,
challenges and games.

[Vim Modes Transition Diagram][vim-mode-trans]

In this diagram, you can see all the ways to go from one **mode** to another
one. It contains a lot of information, so do not panic and remember that you
don't need to learn all of this to be able to work with `Vim`.

[Vim Snake][vim-snake]

Fancy playing snake with `Vim` motions?


[vim-boost]: <https://www.barbarianmeetscoding.com/boost-your-coding-fu-with-vscode-and-vim/table-of-contents>
[vim-cheat1]: <https://devhints.io/vim>
[vim-cheat2]: <https://vim.rtorr.com/>
[vim-genius]: <http://www.vimgenius.com/lessons/vim-intro>
[vim-help]: <https://vimhelp.org/usr_toc.txt.html>
[vim-hero]: <https://www.vim-hero.com/lessons/intro-to-modes>
[vim-mode-trans]: <https://rawgit.com/darcyparker/1886716/raw/vimModeStateDiagram.svg>
[vim-snake]: <https://themouseless.dev/snake/>
