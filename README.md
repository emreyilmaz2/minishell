<p align="center">
MINISHELL
</p>
<p align="center">
hello there im emre and this is the readme of minishell
</p>

### The project is about writing your own bash, so what is bash ?
```
Bash is a command processor that typically runs in a text window where the user types commands that cause actions.
Bash can also read and execute commands from a file, called a shell script. Long story short, bash is the 
terminal's language in Unix/Linux systems.
```
#### In ecole 42 schools me and my friend Can started the project minishell together. We finished in almost 2 moths.(yeah, a little much)<br/>We messed around with tons of segmentation faults, bus errors and aborts.
<p align="center">
So this is a command line processor and we had to choose a walkthrough. You can see it below,
</p><img width="1083" alt="Ekran Resmi 2023-02-04 02 34 41" src="https://user-images.githubusercontent.com/102359028/216730215-b4bc79f8-fa51-4fb9-b82d-a3764e716b83.png">

```
So in 'lexer' stage we need split command (our input) into pieces like below;
```
<img width="1495" alt="Ekran Resmi 2023-02-04 15 33 35" src="https://user-images.githubusercontent.com/102359028/216767896-e30d2881-5e2e-4144-9307-22ffd2c76d88.png">

```
In expander, we should expand variables contained by environment variables like HOME, USER, PWD etc.
```
```
 Before that what is environment variables? The shell uses environment variables to store information,
 such as the name of the current user, the name of the host computer, and the default paths to any commands.
 Environment variables are inherited by all commands executed in the shell's context, and some commands
 depend on environment variables.
```

<p align="center">
<img width="857" alt="Ekran Resmi 2023-02-04 15 55 53" src="https://user-images.githubusercontent.com/102359028/216768961-72e8cc6f-7fd4-424e-bc53-a176643430a8.png">
<img width="1225" alt="Ekran Resmi 2023-02-04 15 57 21" src="https://user-images.githubusercontent.com/102359028/216768952-b4e7a4d1-0e07-444d-af3f-99cae06e17eb.png">
</p>
