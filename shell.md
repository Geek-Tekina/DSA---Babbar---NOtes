### why linux as scripting?
- open source
- highly secure
- faster


### terms
1. Linux - community based os
1. Kernel - Kernel acts as a bridge between applications and data processing performed at hardware level using inter-process communication and system calls. __Kernel loads first into memory when an operating system is loaded__ and remains into memory until operating system is shut down again. It is responsible for various tasks such as disk management, task management, and memory management.  

<hr>

### SHell
Simply put, the shell is a program that takes commands from the keyboard and gives them to the operating system to perform. In the old days, it was the only user interface available on a Unix-like system such as Linux. Nowadays, we have graphical user interfaces (GUIs) in addition to command line interfaces (CLIs) such as the shell.

On most Linux systems a program called bash (which stands for Bourne Again SHell, an enhanced version of the original Unix shell program, sh, written by Steve Bourne) acts as the shell program. Besides bash, there are other shell programs available for Linux systems. These include: ksh, tcsh and zsh.


<hr>

### basic commands
```bash
nano <file_name>
# enter your data
# save aka Write Out : ctrl o
# Exit : ctrl x

cd    # change directory
pwd   # print working directory
ls    # list
    ls --help
    ls Desktop    # ls <path>
    ls -a    # gives all including .(current but w/o hiddens) and ..(ls one directory back)
    ls -A    # all but without . and .. in list
    ls -l    # more detail about files

cp    # copy
    # cp <file> <directory>/
    cp file.txt Desktop/dev/dsa-res/         

mv    # move and also used for renaming
    # mv <file> <directory>
    mv dir1/dir2/file.ext .    # moved file to current dir
    mv file.ext dir1/dir2
    mv file.ext new-name       # file renamed if no folder with `new-name` exists 
    
rm    # remove
# read more at https://www.geeksforgeeks.org/rm-command-linux-examples/

echo    # print
    x=10    # to create a variable
    echo $x
    echo this is a string    # this is a string
    echo "this is a \tstring"    # this is a \tstring
    # -e acts as an interpretation of escaped characters that are backslashed.
    echo -e "this is a \tstring"    # this is a     string
    echo *    # to echo all the files in cd
    echo *.jpeg    # all jpegs
    echo "<h>new header</h>" > testpage.html
    cat testpage.html 

cat    # concatenates the file data into terminal
less   # does the same but opens up the cleaner terminal 

grep   # global search for regular expression
    # with file : grep <regex> <filename>
    grep query f1.cpp f2.cpp
    grep query *       # checking all the files present
    grep -i query *    # case sensitive
    # with a command : <command> | grep <regex> 
    ls | grep arrays
    # options
    # -i : case sensitive
    # -v : inverted search (files and lines that do not contain  query)
    # -r : searching recursively subdirectories
    # -vi : -v and -i
    ls | grep -v stacks

mkdir - make directory
touch - creaste files

chmod - change mode
    # chmod -options permissions <file_name>
    # see below for whole info

man + help - manual
--help as option
```


#### chmod
`chmod` modifies the permissions of the file. It uses combinations formed by r,w,x for u,g and o.

Let's say you are the owner of a file named myfile, and you want to set its permissions so that:
- __user__ can read, write, and execute it;
- __members of your group__ can read and execute it; and
- __others__ may only read it.
- HENCE, `chmod u=rwx,g=rx,o=r myfile`
- OR, `chmod 754 myfile`

where
- 0, no permission
- x = 1
- w = 2
- xw = 1+2 = 3
- r = 4
- rx = 4+1 = 5
- rw = 4+2 = 6
- rwx = 4+2+1 = 7

```sh
# viewing permissions of a file
ls -l file.txt
ls -l
```

### scripting
```bash
nano shell.sh

# in file
# starts with `#!/bin/sh` which tells the location of shell executor
#!/bin/sh
echo "enterr name"
read NAME
echo "hellow $NAME"

# eof
chmod +x shell.sh
./shell.sh
```

### variables
- Local Variable : accessible by current instance of the shell only
- Env. Variable : available to all the child process of the shell
- Special Variable : predefined variables that give info about the program and more.
- Shell Variable : set by the shell in order to function correctly.
```bash
NAME="hi"        # DONT give SPACES
read NAME        # take input
readonly NAME    # more like final const
unset NAME       # echo $NAME will give blank space

# special variables
#!/bin/sh
echo "Script name $0"

# $@ and $* prints the same thing why??
# $@ holds input like [argument1, argument2,...]
# for ./shell.sh "first arg" secon_arg third 4
# $@ = [first arg, secon_arg, third, 4]
# $* = first arg secon_arg third 4
for ARGS in $@
do
    let i=i+1
    echo "Argument $i is $ARGS"
done

echo "Parameter list: (individually) $@"
echo "Parameter list: (as a single list) $*"
echo "Total number of parameters $#"
echo "Process ID of last command $$"
echo "Exit Status of last command $?"

# exit status can be used like this
echo "Executing echo command..."
if [ $? -eq '0' ]
then
  echo "The last command executed successfully: Exit status $?"
else
  echo "The last command was unsuccessful: Exit status $?"
fi
``` 

### more topics
- [conditional statments](https://www.geeksforgeeks.org/conditional-statements-shell-script/)
- [operators](.assets/Unix%20_%20Linux%20-%20Shell%20Basic%20Operators.pdf)
- [loops](https://www.geeksforgeeks.org/looping-statements-shell-script/)
- [shell functions](https://www.tutorialspoint.com/unix/unix-shell-functions.htm)



### FAQs
1. ___last 2 lines?___ tail -2 filename
1. ___first line?___ head -1 filename
1. ___what is awk?___ [gfg.com](https://www.geeksforgeeks.org/awk-command-unixlinux-examples/)
1. ___what is the shebang line?___ absolute path for the shell interpreter. It should be the first line - which is ready by kernel and then the kernel loads the shell interpreter.
1. ___`$* vs $@` ?___
1. ___what is the file system?___
1. ___lifespan of a shell var?___ till the execution
1. ___default permissions on a file?___ 666 rw-rw-rw 
1. ___shell script if else shorthand / ternary command?___ `[ $AGE == 25 ] && result="true" || result="false"`
1. ___print substring?___ name=Somename && echo ${name:start_i:Len}
1. ___arrays in shell?___ - [init, index, print](https://www.geeksforgeeks.org/array-basics-shell-scripting-set-1/)
1.  
1. ___---Experienced ones---___
1. ___redirect standard output and input to same location?___
1. ___difference between ' and " ?___ `''` doesnot evaluate the string e.g. `echo 'name is $name'` gives the exact same output while `""` whill use name variable value
1. what is crontab - stands for crontable. It is a utility that uses cron 
1. two files of crontab - cron.allow and cron.deny (decides which users are denied the use of cron)
1. ___what is a linux cron file?___ describe
1. ___tar / backup file extension?___ tar (tape archive) creates a backup archive of the File
1. ___debug shell scripts?___ by printing required information OR using `set -x` below shebang line 
1. ___while echoing to execute some command, use backticks like this___ echo "current PWD is `pwd`" 
