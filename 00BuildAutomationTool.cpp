/*

A build automation tool is a program that automatically performs the steps needed to
turn source code into a finished application. The build automation tool is not usually the compiler itself.
It organizes instructions to run the compiler and other required tools.
Instead of typing every command manually, you give the tool build instructions, and the build automation tool runs them for you.

    Example:

        A build automation tool can do all of these steps with one command:

            </bash>

                make

        Without build automation, You might manually type:

            </bash>

                g++ -c main.cpp
                g++ -c math.cpp
                g++ main.o math.o -o app

        With build automation, you can just type:
            
            </bash>

                make

    What it can automate

        A build automation tool can:

            - Compile source code
            - Link compiled files
            - Download libraries
            - Run tests
            - Process images and resources
            - Create APK, EXE, or other application files
            - Build debug and release versions
            - Rebuild only files that changed

    Types of build automation tools:

        | Tool   | Common use                                      |
        | ------ | ----------------------------------------------- |
        | `make` | C and C++ projects                              |
        | Gradle | Android, Java, and Kotlin                       |
        | CMake  | Generates build configurations, often for C/C++ |
        | Maven  | Java projects                                   |
        | Ninja  | Fast C/C++ builds                               |

        - Make-based tools: These tools use a Makefile to define build instructions. Examples include:
            - GNU Make
            - CMake
            - Ninja

    The basic relationship is:

        Source code
            ↓
        Build automation tool
            ↓
        Compiler and other tools
            ↓
        Finished application

*/