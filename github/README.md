# Git and GitHub

Hey there Newbie! If you came here to read this simple introduction to `Git`
and `GitHub` is because you are ready and willing to start the hero's journey.
I'm so proud of you!

> DISCLAIMER: In here, a few and very simple and common stuff will be
explained. If you believe there is something missing, unclear or simply wrong,
just open an **issue** with a small explanation and we will make it up to you!


## Bits To be Found

1. [Basic Concepts](#basic-concepts)
    - [What's a Repository?](#repositories)
    - [Want to play, don't want to mess](#branches)
    - [I improved your stuff](#commits)
    - [Acknowledge my work senpai!](#pull-requests)
    - [Having problems has never been so organized](#issues)
2. [Basic Commands](#basic-commands)
3. [Extra Resources](#extra-resources)

## Basic Concepts

No hero has ever started a crusade without knowing what was going on, except
maybe if you are the fox in [TUNIC][tunic]... This is why this section is
here to be your Virgil (if you don't get this reference you should read more).

Anyhow, let's take a small look at the `GitHub` essentials! 

> NOTE: All the activities in the dropdown menus are thought to be done in the
`GitHub` web interface, in the [commands](#basic-commands) section, we will
see some of these activities but done from the command line.

### Repositories

You can think of a **repository** as your project kingdom. In there, you can
have different folders the files, data sets, images and other project-related
needed stuff. In addition, in order to better work with others, know what the
community wants (if doing an open-source project) or needs to be fixed, have a
control over what's going to be on the final version and what won't, each
**repository** has two sections named [issues](#issues) and 
[pull requests](#pull-requests).

The final thing I will mention about what can be found in a **repository** is
the README file. This file is written in the `Markdown` language and
contains information about your project; it can contain sections such as how to
install the project, some usage examples, how to contribute to the project or
how the **repository** is organized among others.

> NOTE: Having a README file is not mandatory but recommended.

<details>
    <summary>Create your own <strong>repository</strong>!</summary>
    <br>

You can create your own **repository** in 6 easy steps:

1. Use the `+` dropdown menu on the upper-right, click `New repository`.
2. Type your repository name on the `Repository name` section.
3. Type a small description for the project on the `Description` box.
4. Decide whether the **repository** will be private or public.
5. (Recommended) Add a README file.
6. Click on `Create repository` and you are good to go!

</details>

### Branches

How many times have you made some magnificent draw with a pencil and
thought "I don't want to paint it because I will make it worse"?
And of those times, after painting it realize you were right? 
How many times did you wish to be able to visualize how would the final draw be
and paint it if it is what you expected?

Well, `GitHub` has heard you and has created the so called **branches**!

A **branch** is an independent copy of the **repository** at the
branch-creation moment. There, you can make the changes you want without
affecting the `main` **branch** (the one you see when you access the
**repository**). After that, there are two main fates for the new **branch**:

1. The changes improve the project are will be **merged** into `main`.
2. The changes do not improve the project and the **branch** will be deleted
without **merging**.

For a better understanding, let's use this stolen image:

![Stolen picture of a branching workflow](https://i0.wp.com/digitalvarys.com/wp-content/uploads/2019/06/image-7.png?resize=1024%2C497&ssl=1)

> NOTE: This is an old image so the `main` **branch** is called `master`, but
I'll still refer to it as `main`.

So, the green line, represents the `main` branch, the one that is displayed in
the **repository**. This **branch** contains 4 files with their respective
versions (which will help us keep track of what is going on). Each circle
represents a change or **commit** and the line between them represents a steady
state of the `main` **branch**. Now, two situations can be seen here:

1. Files 1 and 3 are updated to incorporate `feature_1` into `main`
2. Files 2 and 4 are updated to incorporate `feature_2` into `main`

Focussing in the first feature, a new **branch** (the pink one) is created
to modify files 1 and 3. When the pink **branch** is created, it takes all the
files in its original version. The first **commit** makes some changes in both
files. The second one, turns the files into its final version and it is
**merged** into the `main` **branch**. Note how only files 1 and 3 have changed
in this process.

Regarding the second feature, a new **branch** is created (the blue one),
which contains all the original files in the `main` **branch**. In this case,
a single **commit** is made affecting files 2 and 4 (see files versions). These
changes, are **merged** into the `main` **branch** in a second **commit**, and
we see that at the end, the `main` **branch** has two new features but non of
them were directly made there but in a _copy_ of it.


<details>
    <summary>Create your first <strong>branch</strong>!</summary>
    <br>

You can create your first **branch** in 4 easy steps:

1. In your new **repository**, click the `Code` tab.
2. Click on the dropdown menu that says `main` above the file list.
3. Type a **branch** name into the text box.
4. Click `Create branch: branch-name from main` 

`GitHub` will now bring you to the code page for your new **branch**.
Ieii! You have your first new branch to play with! 

</details>

> NOTE: You can switch **branches** in the dropdown menu above the file list.
There you will always see the name of the **branch** you are in.

### Commits

You now have a **repository** and a **branch** to modify its files without
affecting the `main` one, so let's talk about these changes, your new best
friends, the **commits**.

A **commit** is simply a saved change on a file. Each **commit** must have a
**commit** message to explain why a particular change has been made. The
advantage of having these messages is to keep track of the wonderful
changes you have made so whoever sees them can understand what have you done
and why.

I know you are dying to do a bunch of new **commits** and show your
contributions to the world, but you will have to wait for a bit. You see,
one cannot simply make a **commit** and write whatever, there are some
conventions you should follow to be a good "commiter". 

> NOTE: Here, I will keep it simple, but if you want a more detailed 
explanation, visit this awesome [blog][commitBlog].

A **commit** message is composed of three main parts, the header, the body and
the footer.

#### Header

The header of a **commit** message is mandatory. I will say it again, 
MANDATORY. The header is a short sentence (around 50 characters), that
for us, will have only two parts: the type and the subject. Overall, it will
look something like...

<p align="center">
type: subject
</p>

There are 10 types of _types_ (I feel like I am writing a recursive sentence,
something like.. _you can only understand the recursion when you understand
the recursion_):


<table>
<thead>
<tr>
<th>Type</th><th>Description</th>
</tr></thead>
<tbody>
<tr>
<td>build</td>
<td>The build type (formerly known as chore) is used to identify development changes related to the build system (involving scripts, configurations or tools) and package dependencies.</td>
</tr>
<tr>
<td>ci</td>
<td>The ci type is used to identify development changes related to the continuous integration and deployment system - involving scripts, configurations or tools.</td>
</tr>
<tr>
<td>docs</td>
<td>The docs type is used to identify documentation changes related to the project - whether intended externally for the end users (in case of a library) or internally for the developers.</td>
</tr>
<tr>
<td>feat</td>
<td>The feat type is used to identify production changes related to new backward-compatible abilities or functionality.</td>
</tr>
<tr>
<td>fix</td>
<td>The fix type is used to identify production changes related to backward-compatible bug fixes.</td>
</tr>
<tr>
<td>perf</td>
<td>The perf type is used to identify production changes related to backward-compatible performance improvements.</td>
</tr>
<tr>
<td>refactor</td>
<td>The refactor type is used to identify development changes related to modifying the codebase, which neither adds a feature nor fixes a bug - such as removing redundant code, simplifying the code, renaming variables, etc.</td>
</tr>
<tr>
<td>revert</td>
<td>For commits that revert one or more previous commits.</td>
</tr>
<tr>
<td>style</td>
<td>The style type is used to identify development changes related to styling the codebase, regardless of the meaning - such as indentations, semi-colons, quotes, trailing commas and so on.</td>
</tr>
<tr>
<td>test</td>
<td>The test type is used to identify development changes related to tests - such as refactoring existing tests or adding new tests.</td>
</tr>
</tbody>
</table>

Now, regarding the _subject_, the only thing you have do to is summarize in a
small sentence what have changed using the INFINITIVE form of the verb. For
instance, the **commit** message `docs: add basic concepts` is correct; but the
**commit** message `docs: added sections to basic concepts` is not. Remember the
fabulous design principle KISS.


#### Body

The body is completely optional and can be used if you have the urge of adding
a bigger explanation (not more than 100 characters). Between the header and the
body the must always be a blank line; do not forget it when writing a 
**commit** message from the GitHub web interface (when doing it from the
command line, you won't have to worry about this extra line. See more in the
[commands](#basic-commands) section).

#### Footer

As the body, the footer is optional. There you can mention what are the
consequences of the changes (i.e. linking closed **issues**)


<details>
    <summary>Sneak peek on a CLI <strong>commit</strong> message!</summary>
    <br>

 ```bash
 git add README.md && git commit -m "docs: add basic concepts" -m "The basic concepts repository, branch and commit have been added as they were missing; and as everyone knows, one cannot understand GitHub without understanding these concepts." -m "PR Closes nothing as no issue is opened yet"
 ```
The **log** for this **commit** will look like this

![Screenshot from 2023-07-16 16-51-42](https://github.com/deliaBlue/laPrepa/assets/103108590/6f5ddf8b-8646-4cef-9f58-e0aa4d17fe12)

</details>


> NOTE: The header will be the only part of the **commit** message that would be
seen in your **repository**, but if you place your mouse over the **commit**
message you will see the entire composition.

![Screenshot from 2023-07-16 16-53-49](https://github.com/deliaBlue/laPrepa/assets/103108590/e2d5741d-fb4d-40e6-9718-1bdcbb3125a7)

<details>
    <summary>Make your first <strong>commit</strong>!</summary>
    <br>

You are going to make your first **commit** on your recently created **branch**
in 6 simple steps:

1. Click the `README.md` file
2. Edit the file by clicking on the pencil :pencil2:
3. Write something there. Is you chance to play with `Markdown`
4. Click `Commit changes...`
5. Write the correct **commit** message and a body (in the 
`extended description` box).
6. Click `Propose changes`

Done! Now, you can check the `main` **branch** and see that the README file
has no changes while your recently created **branch** contains them.
Also, you will be able to see a message such as `This branch is one commit
ahead of main`. This simply means that you have one **commit** that the
`main` **branch** don't.

</details>

### Pull Requests

I know what you think... 

<p align="center"> 
"What's the worth of a <strong>commit</strong> if it is not shown in the <code>main</code> <strong>branch</strong>?
</p>

Well, today is your lucky day my friend, because I am about to show you the
path to the glory, also known as **pull requests**.

**Pull requests** are, citing the `GitHub` documentation, _"the heart of
collaboration on `GitHub`"_, and that's in fact, 100% right. 

When opening a **pull request** you are saying _"Hey Admin(s)! That's what
I've been working on. Could you check it out and if you like it **merge** it
into the `main` **branch**?"_ The changes your **commits** had made are then
reviewed by the admin(s) and they can either directly **merge** it or they
might ask you to apply some changes. After some back and forth between comments
and **commits** your **pull request** will be **merged** and your **branch**
deleted.

> DISCLAIMER: Sometimes, when the force is not with you, **merging** your
**pull request** will create merge conflicts. Merge conflicts can happen when
different people is making changes in the same part of the same file, if that
ugly situation occurs, you will have to resolve them by manually editing the
conflicted file and select the changes to keep in the final **merge**.

As before, **pull requests** have some rules on the naming. And in fact, it has
the SAME rules. The name of the **pull request** should follow the convention
`type: subject`. Unlike before thou, the body of the **pull request** changes
from **repository** to **repository**, do not worry, this format will be
documented within the same **repository**. 

Some important parts (that concern us) in a **pull request** are the 
`Reviewers`, `Assignees` and the `Development` sections.

In the `Reviewers` part, you can choose who do you want to review your
**pull request** so they get notified. You can also do that by adding
`@reviewer_username` in the **pull request** body.

In the `Assignees` part, you can specify who is in charge of applying the
changes, if required, in your **pull request** (I normally assign myself the
**pull requests** I opened. You know, it might be obvious but I want to have
my work recognized).

Finally, the `Development` part include the **issues** that will be closed if
the **pull request** is finally **merged**. You can specify the different
**issue(s)** in the **pull request** by adding `This PR closes #(issue_number)`
at the beginning of the **pull request** body.


<details>
    <summary>Create your first <strong>pull request</strong>!</summary>
    <br>

Did you know that you can open **pull requests** in your own **repository**
and **merge** them yourself? Let's try that out!

1. Click the `Pull requests` tab in your **repository**
2. Click `New pull request`
3. In the `Example Comparisons` box, select the **branch** you created before,
to compare with the `main` one.
4. Take this opportunity to check the changes in the `Compare` page. This is
a good way to make sure that what you are submitted is what you want to and you
did not messed up the **branches** or the **commits**.
5. Click `Create pull request` 
6. Fill properly the title and the add a brief description of your changes. If
you want, you can add a `Reviewer` and an `Assignee`.
7. Click in `Create pull request`.

Hurray! You have made your first **pull request**! Do you feel like 
**merging** it?

1. At the very end of the **pull request**, click `Merge pull request` to
**merge** the changes into `main`.
2. Click `Confirm merge`.
3. Now that the request has been successfully **merged** and closed, you can
safely delete the **branch** by clicking `Delete branch`.

You can admire your changes on the `main` **branch**! Cool right?

</details>


### Issues

Welcome to the section with the most misleading name, the **issues** section!

**Issues** are a pretty cool thing in `GitHub`; they allow you to keep track
of the work on the project. What has been done and what is left. It allow
external users to report bugs or suggest new features and they can be created
in many many many ways! I'm not even kidding here, just check the 
[**issue** creation docu][issueCreate], isn't that just crazy?

> NOTE: In this section I will not focus on the many many many ways of
creating an **issue** (really, there are a lot! Check the
[docu][issueCreate] again) but on how are they build and used.

An **issue** is a task, question or suggested improvement related to the
**repository** that contains its own discussion thread. Neat definition right?

When creating an **issue**, as in the **pull request** creation, a title and
a description is needed. Unlike with **pull requests**, the title does not have
to follow any specific convention (but it must be clear and concise). 
Some **repositories** have some requirements for body while others don't. In
any case, the body must provide enough information for the **issue** to be
closed. Let's see some examples:

- This **issue** is a task. The description could include information about
how to proceed or even a task list. 
- This **issue** is a bug. The description could include information on the
steps you took that lead to the bug. Maybe some information about your OS or
the dependencies on the environment you are working on. 
- This **issue** is a request. The description could include information about
the feature you are missing on the project, why it would be a good idea to add
it, or even suggest an approach to it (this might lead to get assigned that
**issue** by the project's admin(s)). 
- This **issue** is an improvement. The description could include how _that_
part is implemented and how it should be changed.  

<br>

As seen before, there are small bits that help on having better **issues** (
"better **issues**" what a weird concept).

When you are creating an **issue** you can add a `label`. This `label` will
appear next to the title in the **issues** tab and are very helpful to rapidly
see what kind of **issue** it is before even looking at the title. `GitHub`
provides default labels but you can always edit them or add new ones.

Also, in the **issue** creation, you can add the **issue** to a `Project` 
or/and a `Milestone` (see the [secret section](#milestones-and-projects)).
Doing so, will help on the project organization as well as on its progress
track.

During the **issue** creation or after it, `assignees` can be added to know who
is or will be working on it.

And the final bit to mention is the `Development` part. After an **issue** has
been created, on the right-most part you can see a section called
`Development`. This section allows you to create a **branch** that will be
automatically linked to the **issue**. This link implies that when creating a
**pull request** for that **branch**, it will automatically be linked with
that **issue**, which at the same time implies that once the **pull request**
is **merged** into `main`, the **issue** will automatically be closed.


<details>
    <summary>Time to wrap up everything!</summary>
    <br>


In this final activity, you will go through a complete `GitHub` workflow, are you ready? 

1. Click the `Issuess` tab in your **repository**
2. Click `New Issue`
3. Fill properly the title and add a brief description for the **issue**. You
could maybe add a new section in the `README.md`.
4. Label it as `documentation` and add yourself as an `Assignee`.
5. Click `Submit new issue`.
6. Create a **branch** from within the new **issue**.
5. Make some **commits** and create a **pull request**. 
6. **Merge** your **pull request** and delete the **branch** 

Even if you managed to do all of this without any problem, are you brave enough
to learn to do all of this from the command line?

Go ahead and enter to the [commands world](#basic-commands)

</details>


#### Milestones and Projects

Okey, okey, okey, I will not spend a lot of time here, it won't take more than
a minute. This small secret section it's just for you to have a very tiny 
notion of what are the **projects** and **milestones**; both tools help you
keep track of your project status but in different ways:

- **Projects** can have different shapes and forms. Here, I will defined them
as boards in which **issues** are placed in order to see its current state and
sort them according to its priority.

- **Milestones** help you keeping track on the progress to achieve certain
goals. These, are build of **issues**, the amount of **issues** in each
milestone can increase and decrease as the project goes by.


## Basic Commands

Oh my little plumber, you thought you reached the end but some weird
monster kidnapped your dreams again, isn't it? 

Do not worry, as you already know the basics of `GitHub`, in this section only
commands will be found. No more long and random explanations, no more
understanding, just code (and a some small random sentences to make it easier
for you to read and for me to write).

> NOTE: To ease the introduction to using `GitHub` from the command line, some
operations will be done in the `GitHub` web interface. If you really want to do
everything from the command line, check the `GitHub CLI` dropdown menus. 

In this step-by-step guide, you will open an **issue** for this repo to finally
make a **pull request**. I'm sorry to announce that you won't be able to
**merge** your **pull request** as it needs to be reviewed first by me. But do
not let the fun be taken away because of that okey?

### 0. Ready? Steady? Clone!

If you are reading this before making the installation and **cloning** of this
**repository**, stop right now and do it! 

If you have already **cloned** this **repository**, open your terminal and
traverse to the **repository** directory.

If you want to use the `GitHub` web interface instead of `GitHub CLI`, open 
the **repository** in another tab.

**DISCLAIMER:** DO NOT CHANGE THE DIRECTORY NAME, IT MUST MATCH THE REPO ONE.

### 1. The Issue Maker

The first thing we will do, is to create an **issue**, you already know how to 
do it, so no extra explanations will be added. The **issue** requirements are:

- The title must be "adding contributors data (your_name)"
- The body must be a very creative reason why you should be a contributor of
this **repository**. Be creative, not extensive. 
- Assign it to yourself and add the label `good first issue`. 
- Add it to the **milestone** "X force". There is no need to add it to any
**project** as it will be added automatically.


<details>
    <summary>Alternative: Use <code>GitHub CLI</code></summary>
    <br>

Same conditions apply, the command that you must run from the **repository**
directory is:

```bash
gh issue create [flags]
```

With the flags:

- `-a`, `--assignee <username>` (Use `@me` to self-assign) 
- `-b`, `--body <string>` 
- `-m`, `--milestone <name>`
- `-l`, `--label <label name>` 
- `-t`, `--title <string>`

</details>

### 2. The Tree Creator

Now, in order to make any changes, you need to create a **branch** for the
**issue** you just created. To do so, within your **issue**, under the
`Development` part, click on `Create a branch` and make sure to select the
`Checkout locally` option. Name the **branch** "issue_number_let-me-in
-your_name".

This will display three commands to run on your terminal, run them.

> NOTE: When you are working from the command line, and want to change the
**branch** you are in, you can use the command `git checkout branch_name`.

<details>
    <summary>Alternative: Use <code>GitHub CLI</code></summary>
    <br>

Same conditions apply, the commands that you must run from the **repository**
directory are:

```bash
# Check your issue number
gh issue list -a "@me"

# Create issue
gh issue develop [<number> | <url>] [flags]
```

With the flags:

- `-b`, `--base <string>` Name of the base **branch** to make the new 
**branch** from
- `-c`, `--checkout` Checkout the **branch** after creating it
- `-n`, `--name <string>`

</details>

### 3. The Committed Beginner

Now that you are on the correct **branch**, open the `README.md` in the main
directory, and under the `Contributors` header, add your name in **BOLD** and
something random. Something that could define you (or not).
Here's an example:

<p align="center"> <b>Iris Mestres (deliaBlue):</b> I don't think there will be
enough coffee or middle finder for this Monday. </p>

Use you favorite text editor (if you want to try `vim`, be my guest) and save 
your work.  Please, if there is already someone there, write your part 
following an ALPHABETICAL order, and do not write lines of more than 80 
characters.

When a file is changed but no further action has been taken, it is called an
**untracked file**. In simple words, this means that `Git` has no record of
these changes. In order to make `Git` acknowledge your changes, you have to 
**add** your files to it.

The `git add` command will add the specified file in the metaverse known as
**staging area**, once there, a file can be **committed** and afterwards
**pushed** to the **remote repository**. For more information about this
command, check the [git add documentation][gitadd].

On the other hand, the `git commit` command, takes whatever is in the
**staging area** and **updates** the **branch** with it. More on the
`git commit` command [here][gitcommit].

Now, again in the terminal in the `README.md` directory, run the following 
command:

```bash
git add README.md && git commit -m "your commit header here"
```

The last command in this section is to **push** your **commit** to the 
**remote repository** (which is a fancy way of saying that you will send to the
**repository** in `GitHub` your changes). Mind that in this case you will only
**push** one **commit**, but you can make several **commits** before making the
**push** and you can always make extra **commits** and **push** them after your
first **push**.

Now, to make the **push** it is as simple as

```bash
git push
```

>NOTE: Maybe someone has edited the same file before you made your **push** and
therefore, you will encounter a **merge** conflict. One way to solve it, is to
first run the command `git pull`. This command will retrieve from the 
**remote repository** the changes into your local copy and you will be able
to solve the conflict and then **push** your work.

<details>
    <summary>Alternative: Use <code>GitHub CLI</code></summary>
    <br>

Nothing to see here, you can only use the usual `Git` commands to do this part.

</details>

### 4. The Friendly Request

Are you a bit disappointed that nothing spectacular has happened after the
**push**? Oh my little child, go to `GitHub` and you should see a yellow banner
saying that your **branch** had recent **pushes** and next to it, there is
a big green button (yeah, I know, it would be much cooler if the button was
red) that says `Compare & pull request`. 

After clicking there, the conditions are:

- The title must follow the specs mentioned before. 
- The body must mention what **issue** will be closed and what are the changes
within your **pull request**.
- Add me `deliaBlue` as a reviewer
- Add the **pull request** to the project "La Prepa Is On Fire".
- Optionally, add yourself as an assignee.


<details>
    <summary>Alternative: Use <code>GitHub CLI</code></summary>
    <br>

Same conditions apply, the command that you must run from the **repository**
directory is:

```bash
gh pr create [flags]
```

With the flags:

- `-a`, `--assignee <username>` (Use `@me` to self-assign) 
- `-B`, `--base <branch>` Name of the **branch** into which you want your
**commits** merged
- `-b`, `--body <string>`
- `-H`, `--head <branch>` Name of the **branch** that contains **commits** for
your **PR**.
- `-r`, `--reviewer <username>`
- `-t`, `--title <string>`

</details>

### 5. The Achievements Blender

Nearly done! You just have to wait for my review. If everything goes fine, I
will just approve it, otherwise, I will request some changes and you will have
to repeat this process by applying the requested changes and wait again for my
review. 

If the **pull request** has been approved, you will receive an email and what
will be left will be to **merge** your **pull request** and delete your
**branch**; all of which can be done from the `GitHub` web interface.

<details>
    <summary>Alternative: Use <code>GitHub CLI</code></summary>
    <br>

Same conditions apply, the command that you must run from the **repository**
directory is:

```bash
gh pr merge [<number> | <url> | <branch>] [flags]
```

With the flags:

- `-b`, `--body <text>`
- `-d`, `--delete-branch`
- `-m`, `--merge`
- `-t`, `--subject <text>` Subject text for the **merge commit**

</details>

<br><br>

<p align="center"><b> CONGRATS!! You now know all the GitHub basics! Let the
fun begin!!</b></p>


## Extra Resources

[**GitHub CLI commands**](https://cli.github.com/manual/gh)

Documentation for all the possible commands and subcommands that `GitHub CLI`
offers.

[**GitHub Glossary**](https://docs.github.com/en/get-started/quickstart/github-glossary)

As the name suggests, here you can find a brief definition for the most
common `Git` and `GitHub` terminology.  


[**Learn Git Branching**](https://learngitbranching.js.org/)

_Learn Git Branching_ is a visual and interactive way to learn Git commands. It
is divided in levels that increase in difficulty while wrapping up the commands
previously learnt. In addition, it has a small section called `Remote` that
will teach you how to use `Git` commands to work locally and submit the changes
remotely.  

[**Markdown Basic Formatting Syntax in GitHub**](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)

Small and quick reference to the `Markdown` syntax.  



[commitBlog]: <https://nitayneeman.com/posts/understanding-semantic-commit-messages-using-git-and-angular/>
[gitadd]: <https://git-scm.com/docs/git-add>
[gitcommit]: <https://git-scm.com/docs/git-commit>
[issueCreate]: <https://docs.github.com/en/issues/tracking-your-work-with-issues/creating-an-issue>
[tunic]: <https://tunicgame.com/>
