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
<img width="1337" alt="Ekran Resmi 2023-02-04 23 38 43" src="https://user-images.githubusercontent.com/102359028/216788676-1e0f674d-36c8-4bac-b1dc-eb6e786f9cb2.png">

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
<img width="1141" alt="Ekran Resmi 2023-02-04 23 56 04" src="https://user-images.githubusercontent.com/102359028/216789240-318410a1-54b4-46af-998d-1caa8aec0b2c.png">
</p>

```
We splitted and expand our input. Now we should parse input into nodes and analyze every node,
like this is command, this is just text and this is the outfile stream of this node etc.
```
<p align="center">
<img width="955" alt="Ekran Resmi 2023-02-05 00 17 23" src="https://user-images.githubusercontent.com/102359028/216789932-13dc0a1d-661a-4af9-9ae6-1a309771753e.png">
<img width="857" alt="Ekran Resmi 2023-02-05 00 22 44" src="https://user-images.githubusercontent.com/102359028/216790093-72fcec73-66de-4edd-b571-24866606ad5e.png">
</p>
