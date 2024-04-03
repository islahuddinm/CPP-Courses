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