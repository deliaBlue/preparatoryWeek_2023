# Welcome to the Preparatory Week 2023!

The 2nd course of the Bachelors Degree of Bioinformatics is the hardest one.
During this year, you are going to face a lot of new and complicated 
material.  

Do not suffer, we all have been there and succeeded. But because we know what it
takes to do it, we know that these days we are going to share together are
very important. Summer is coming to an end, and the last thing you want is to
go back to classes and what's worst, classes before the official ones! We ask
you to make an effort, this is really going to help you out.

Along the 10 scheduled hours we will cover vaguely how to work with GitHub and
`Vim`. We will do a small introduction to `C++` along with
`psuedocode`. We will get a bit more technical by talking about memory
allocation and its related errors in `C++`, ending each day with a
little bit of `Biopython`.

It sounds like a lot and, in fact, it is. Knowing that, we will try to make it
as easy for you to digest as possible and we you can always contact any of us
at any time, we are more than glad to help. The content will be uploaded day
after day, that's why you are seeing an empty repository. By the end of the
week, all the material and activities done are going to be for you to keep and
revisit.

With all this being said, we would like to welcome you to the beginning of the
preparatory week. We hope you enjoy these days as much as we did preparing them!

## Things To See Here

1. [Installation and Configuration](#installation)
    - [Installation for the Penguin Club](#linux)
    - [Installation For The Half-apple Cult](#macos)
2. [The coolest team ever!](#contributors)


## Installation

### Linux

Prior to anything, I will suppose you already have `Git` installed. But just
in case I am wrong (not an usual thing), you can make me be right with the
following commands:

```bash
sudo apt-get update
sudo apt-get install git-all
```

To verify the installation (or just to check whether you have `Git` or not),
type:

```bash
git version
```

In addition, for an easiest management (and other cool things that you can
discover and play around with), [GitHub CLI][gitcli] will also be
installed with a super easy and simple command:

```bash
type -p curl >/dev/null || (sudo apt update && sudo apt install curl -y)
curl -fsSL https://cli.github.com/packages/githubcli-archive-keyring.gpg | sudo dd of=/usr/share/keyrings/githubcli-archive-keyring.gpg \
&& sudo chmod go+r /usr/share/keyrings/githubcli-archive-keyring.gpg \
&& echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/githubcli-archive-keyring.gpg] https://cli.github.com/packages stable main" | sudo tee /etc/apt/sources.list.d/github-cli.list > /dev/null \
&& sudo apt update \
&& sudo apt install gh -y
```

Even if I'd really like to say that the next step is to **clone** this
repository and start the fun part, there's a small thing left to do: the
terrible and scary _SSH key configuration_.

Run the following command and change the email by the one you used to create a
`GitHub` account (because you already have one right? If not... what are you
waiting for?)

```bash
ssh-keygen -t ed25519 -C "cool_email@laprepa.com"
```

Afterwards, you will be asked to `Enter a file in which to save the key`. Just
press `Enter` and use the default location (unless you are very anal and have
the urge to use another file, then type it).  
The next prompt will ask you to `Enter passphrase`; citing the `GitHub` docu:

> With SSH keys, if someone gains access to your computer, the attacker can
gain access to every system that uses that key. To add an extra layer of
security, you can add a passphrase to your SSH key. To avoid entering the 
passphrase every time you connect, you can securely save your passphrase in
the SSH agent.


I'm not going to cover that, you can refer to the [official docu][passphrase],
I will proceed assuming you DID NOT `Enter passphrase` and just press `Enter`
twice. In order to finish this terrible and scary part, you will add the SSH
key you just generated to the `ssh-agent` and to your `GitHub` account.

#### Add SSH key to `ssh-agent`

```bash
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
```

> NOTE FOR FUSSY PEOPLE: If you have changed the SSH key filename, you will
have to replace the `id_ed25519` by the one you provided.


#### Add SSH key to you `GitHub` account

Okey, I might have told you a tiny little lie before when I told you that this
was the last _"small thing left to do"_, you must authenticate to the
[GitHub CLI][gitcli] in order to use it and add the SHH key. If I waited until
this point is because I wanted to have the _installation_ and _configuration_
steps separated (and because I forgot it up there and I'm to lazy to fix it
now).

To make the authentication, run the command

```bash
gh auth login
```

This command will lead you to an interrogation, but do not worry, I have the
answers for you:

First Question: `What account do you want to log into?`  
`GitHub.com`

Second Question: `What is your preferred protocol for Git operations?`  
`SSH`

Third Question: `Upload your SSH public key to your GitHub account?`  
`/home/YOUR_USER_NAME/.ssh(id_ed25519.pub`

Fourth Question: `Title for your SSH key:`  
`key_name`

Last Question: `How would you like to authenticate GitHub CLI?`  

- If you are a hero that has and remembers its token: `Paste an authentication
token`

- If you are a mortal like me: `Login with a web browser`


Done! Finally it is time to have fun... or is it?


### macOS

Let's deviate from the cool path, to make a small summary for the people that
wrongly decided to join the half-apple cult (even though they made the wrong
decision, we do not have to discriminate them).

Fruit-guys, I will assume that you have installed [homebrew][homebrew]; if you
do not, install it now. Again, in case you do not have `Git` installed in your
computer, you can do it with the command

```bash
brew install git
```

As the cool penguin users, you will also need to install [GitHub CLI][gitcli]
as we will be working from the terminal. To install it, use the command

```bash
brew install gh
```

Now, the next steps are focussed on the `GitHub` configuration in order to be
able to work without any further problems. The first thing will be to create
an SSH key, which can be done with the following command. Do not forget to
change the email with the one used to create your `GitHub` account.

```bash
ssh-keygen -t ed25519 -C "cult_email@laprepa.com"
```

You will be asked to `Enter a file in which to save the key`, you can leave
the default one by just pressing `Enter` (which is what I recommend), or change
it. The next prompt will ask you to `Enter passphrase`; citing the `GitHub`
documentation (again):

> With SSH keys, if someone gains access to your computer, the attacker can
gain access to every system that uses that key. To add an extra layer of
security, you can add a passphrase to your SSH key. To avoid entering the 
passphrase every time you connect, you can securely save your passphrase in
the SSH agent.


I'm not going to cover that, you can refer to the [official docu][passphrase],
I will proceed assuming you DID NOT `Enter passphrase` and just press `Enter`
twice. In order to finish this terrible and scary part, you will add the SSH
key you just generated to the `ssh-agent` and to your `GitHub` account. 

#### Add SSH key to the `ssh-agent` 

The first step is to start the `ssh-aggent` in the background with the command

```bash
eval "$(ssh-agent -s)"
```

If you're using `macOS Sierra 10.12.2` or later (do not ask me how to know
that 'cause I don't know), you will need to modify the `~/.ssh/config` file to
automatically load keys into the `ssh-agent`.

To begin with, check if the file exists with `open ~/.ssh/config`, if it does
not, create it with the command

```bash
touch ~/.ssh/config
```

Now, open it and modify it to contain the following lines

```
Host github.com
  AddKeysToAgent yes
  UseKeychain yes
  IdentityFile ~/.ssh/id_ed25519
```

> NOTE: If your SSH key file has a different name or path than the example
code, modify the filename or path to match your current setup.

> NOTE 2: If you DID NOT add a passphrase to the key, remove the `UseKeychain yes` line.

Finally, add the SHH key to the `shh-agent` with the command

```bash
ssh-add ~/.ssh/id_ed25519
```

> NOTE: If you DID add a passphrase to the key, the command should be 
`ssh-add --apple-use-keychain ~/.ssh/id_ed25519`

#### Add SSH key to your GitHub account

Before adding the SSH key, you need to authenticate with the command

```bash
gh auth login
```

This command will lead you to an interrogation, but do not worry, I have the
answers for you:

First Question: `What account do you want to log into?`  
`GitHub.com`

Second Question: `What is your preferred protocol for Git operations?`  
`SSH`

Third Question: `Upload your SSH public key to your GitHub account?`  
`/home/YOUR_USER_NAME/.ssh(id_ed25519.pub`

Fourth Question: `Title for your SSH key:`  
`key_name`

Last Question: `How would you like to authenticate GitHub CLI?` 

- If you are a hero that has and remembers its token: `Paste an authentication
token`

- If you are a mortal like me: `Login with a web browser`



And finally, you are ready to go! Or at least you should be...

## Contributors

**Alba Jiménez** | [Contact me][AlbaJimLup]

**Diego Benito** | [Contact me][diego-benito-j]

**Ian Perez** | [Contact me][IPerM]

**Iris Mestres** | [Contact me][deliaBlue]

### Junior Contributors

**Laia Barcenilla** | [laiabm04][laiabm04] | I play tennis.



[AlbaJimLup]: <alba.jimenez@alum.esci.upf.edu>
[deliaBlue]: <iris.mestres@alum.esci.upf.edu>
[diego-benito-j]: <diego.benito@alum.esci.upf.edu>
[gitcli]: <https://cli.github.com/>
[homebrew]: <https://brew.sh/>
[IPerM]: <ian.perez@alum.esci.upf.edu>
[laiabm04]: <https://github.com/laiabm04>
[passphrase]: <https://docs.github.com/en/authentication/connecting-to-github-with-ssh/working-with-ssh-key-passphrases>


