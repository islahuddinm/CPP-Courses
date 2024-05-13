/*

standard commands & flags for Terminal /////////////////////////////////////////////////////////////////////

Command: A command is an instruction given to a computer program to perform a specific action.
Flag: A flag is a variable or a value that acts as a signal for a certain condition or behavior.

In summary, a flag is a variable that indicates a certain condition, while a command is an instruction
to perform a specific action.

Example : 'ls' command. 'ls -l' command and flag.
A command is what you type on the command line to perform an action, like ls to list directory contents.
A flag modifies the behavior of a command, such as -l to get a detailed listing. Flags are specific to
the command they are used with and determine how the command executes or what output it generates.

what are dir, ls, cd, rm, del, pwd, and clear command?

'dir' (Windows) or 'ls' (Linux/macOS): Lists the files and directories in the current directory.
'cd': Changes the current directory.
'rm' (Linux/macOS) or 'del' (Windows): Removes (deletes) a file.
'pwd': Prints the current working directory (shows the path of the current directory).
'clear' (Linux/macOS) or 'cls' (Windows): Clears the terminal screen.
'mkdir': Creates a new directory.
'rmdir' (Windows) or 'rm -r' (Linux/macOS): Removes (deletes) a directory.
'cp' (Linux/macOS) or 'copy' (Windows): Copies files and directories.
'mv' (Linux/macOS) or 'move' (Windows): Moves or renames files and directories.
'cat' (Linux/macOS) or 'type' (Windows): Displays the contents of a file.


can you show flags is commonly used?

'-l': Long listing format, displaying detailed information about files and directories.
'-a': Include hidden files (those starting with a dot .).
'-h': Human-readable file sizes (e.g., 1K, 2M).
'-t': Sort by modification time, newest first.
'-r': Reverse the order of sort to get the oldest or newest files first.
'-R': Recursively list subdirectories.
'-F': Append indicators (like / for directories, * for executables) to entries.
'-i': 'ignore-case' flag This flag, when set, tells the command to perform its operation (like searching or matching)
without considering the case of the characters. For instance, grep -i 'pattern' file.txt would search
for 'pattern' in 'file.txt' ignoring the case of the characters (ignonere: 'Pattern', 'patTern').

For example, ls -l will list files in long format, ls -a will list all files (including hidden ones),
and ls -lh will list files with human-readable sizes.


standard flags for GCC /////////////////////////////////////////////////////////////////////////////////////

'-c': Compile or assemble the source files, but do not link. This flag is used when you want to
compile individual source files into object files.

'-o <file>': Place the output into <file>. By default, the output executable file is named a.out.

'-g': Generate debug information. This flag includes debugging information in the output file, which
can be useful for debugging with tools like GDB.

'-Wall': Enable all warning messages. This flag enables a set of common warning messages that can
help you write better code.

'-Werror': Treat all warnings as errors. This flag makes the compiler treat any warning message as an error,
causing the compilation to fail.

'-std=<standard>': Specify the C++ standard to use. For example, -std=c++11 specifies the C++11 standard.
'-I <directory>': Add <directory> to the list of directories to be searched (for header files).
'-L <directory>': Add <directory> to the list of directories to be searched (for libraries).

'-l <library>': Link against the specified library. The library name should be specified without
the lib prefix and the file extension.

These are just a few examples of the many flags available in GCC. You can find a comprehensive list of
GCC options and flags in the GCC documentation.

*/

/*
Exploring Ubuntu can be a fun way to learn about the Linux operating system. Here are some basic commands
you can use in the terminal to navigate and explore your Ubuntu system:

Navigating the File System:

ls: List files and directories in the current directory.
cd: Change directory. Use cd <directory> to move to a specific directory.

Viewing Files:

cat: Display the contents of a file.
less or more: Display the contents of a file one page at a time. Use arrow keys to navigate.

Creating and Managing Files and Directories:

mkdir: Create a new directory. Use mkdir <directory_name> to create a directory.
touch: Create a new empty file or update the timestamp of an existing file. Use touch <filename> to
create a file.
cp: Copy files and directories. Use cp <source> <destination> to copy a file/directory to a new location.
mv: Move or rename files and directories. Use mv <source> <destination> to move a file/directory.

Removing Files and Directories:

rm: Remove files or directories. Use rm <filename> to remove a file. Use rm -r <directory> to remove
a directory and its contents (be careful with this command as it is irreversible).

Viewing System Information:

uname -a: Display information about the system kernel.
lsb_release -a: Display information about the Ubuntu release.
df -h: Display disk space usage.

Managing Packages:
apt (Advanced Package Tool) is a package manager used in Debian-based Linux distributions such as Ubuntu.
It is used to install, update, upgrade, and manage software packages.

apt update: Update the package index.
apt upgrade: Upgrade all upgradable packages.
apt install <package>: Install a new package.
apt remove <package>: Remove a package.
apt search <keyword>: Search for a package.

sudo: commonly used to perform administrative tasks that require root (administrator) permissions,
such as installing or removing software, modifying system configurations, or accessing files and
directories that are restricted to the root user.

These are just a few basic commands to get you started. Ubuntu provides a vast array of tools and
commands for exploring and managing the system. As you become more comfortable with the terminal,
you can explore more advanced commands and utilities.
*/

/*
what is '|' command?

The '|' symbol in a command is called a pipe. It is used to connect the standard output (stdout) of
one command to the standard input (stdin) of another command. This allows you to chain multiple commands
together, creating a pipeline where the output of one command is passed as input to the next command.

For example, in the command cat file.txt | grep "pattern", the cat file.txt command reads the contents of
file.txt and outputs them to stdout. The | (pipe) then takes this output and passes it as input to
the grep "pattern" command, which searches for the specified pattern in the input and outputs
the matching lines to stdout.

Pipes are a powerful feature of Unix-like operating systems, allowing you to combine simple commands to
perform complex tasks efficiently.
*/