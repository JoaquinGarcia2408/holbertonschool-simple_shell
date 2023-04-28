<h1> Description </h1>
A simple shell program is a program that provides a basic command-line interface for interacting with an operating system. It allows users to enter commands and receive output from the system.
<h1> Requirements </h1>
<ul>
<li>Allowed editors: vi, vim, emacs</li>
<li>All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89</li>
<li>All your files should end with a new line</li>
<li>A README.md file, at the root of the folder of the project is mandatory</li>
<li>Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl</li>
<li>Your shell should not have any memory leaks</li>
<li>No more than 5 functions per file</li>
<li>All your header files should be include guarded</li>
<li>Use system calls only when you need to</li>
</ul>
Only use the following functions and system calls:

<ul>
   <li> all functions from strings.h</li>
   <li>access (man 2 access)</li>
   <li> chdir (man 2 chdir)</li>
   <li> close (man 2 close)</li>
   <li> closedir (man 3 closedir)</li>
   <li> execve (man 2 execve)</li>
   <li> exit (man 3 exit)</li>
   <li> _exit (man 2 _exit)</li>
   <li> fflush (man 3 fflush)</li>
   <li> fork (man 2 fork)</li>
   <li>free (man 3 free)</li>
   <li> getcwd (man 3 getcwd)</li>
   <li> getline (man 3 getline)</li>
   <li> getpid (man 2 getpid)</li>
   <li>isatty (man 3 isatty)</li>
   <li> kill (man 2 kill)</li>
   <li> malloc (man 3 malloc)</li>
   <li> open (man 2 open)</li>
   <li> opendir (man 3 opendir)</li>
   <li> perror (man 3 perror)</li>
   <li> printf (man 3 printf)</li>
   <li> fprintf (man 3 fprintf)</li>
   <li> vfprintf (man 3 vfprintf)</li>
   <li> sprintf (man 3 sprintf)</li>
   <li> putchar (man 3 putchar)</li>
   <li> read (man 2 read)</li>
   <li> readdir (man 3 readdir)</li>
   <li> signal (man 2 signal)</li>
   <li> stat (__xstat) (man 2 stat)</li>
   <li> lstat (__lxstat) (man 2 lstat)</li>
   <li> fstat (__fxstat) (man 2 fstat)</li>
   <li> strtok (man 3 strtok)</li>
   <li> wait (man 2 wait)</li>
   <li> waitpid (man 2 waitpid)</li>
   <li> wait3 (man 2 wait3)</li>
   <li> wait4 (man 2 wait4)</li>
   <li> write (man 2 write)</li>
</ul>
<h1> Compilation </h1>
Compilation must be using this flags:

<code>
 gcc -Wall -Wextra -Werror -pedantic -g *.c -o hsh
</code>
You could add -g to test with valgrind flags
<h1> Testing </h1>
Your shell should work like this in interactive mode:

```ruby
$ ./hsh                        
($) /bin/ls                    
hsh main.c shell.c             
($)                            
($) exit                       
$                              
```
But also in non-interactive mode:

```ruby

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
<h1> File Description</h1>
<h2> functions.c </h2>
<ul>
<li> tokenize_line function that - Tokenizes arguments given by the user </li> 
<li> _get_env - Search for specific word inside env </li>
<li> path_attacher - Add corresponding path to the given command </li>
<li> fork_handler - Fork to create a child proccess and execute a program </li>
<li> execute </li>
</ul>
<h2> print_env </h2> 
print_env - Print enviroment
<h2> main.h </h2> 
main.h - this is the header file, all the Libraries and prototypes that we used in the shell
<h2> simpleshell.c </h2> 
simpleshell.c - Contains the main function that runs the simple shell
<h2> auxf2.c </h2>
<ul>
<li> free_grid - Frees a 2 dimensional grid </li>
</ul>
<h1> Flowchart </h1>




