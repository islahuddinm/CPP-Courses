/*

A build automation tool (Buld System) is a program that automatically performs the steps needed to
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

        Here are common build automation tools:

            - Make: A classic tool for C and C++ projects. It uses a Makefile to define build instructions.
            - CMake: A cross-platform tool that generates build configurations for various compilers and IDEs.
            - Gradle: Popular for Android, Java, and Kotlin projects. It uses a build.gradle file to define tasks.
            - Maven: Commonly used in Java projects. It uses a pom.xml file to manage dependencies and build steps.
            - Ninja: A small, fast build system often used with CMake.

            | Tool                      | Commonly used for                              |
            | ------------------------- | ---------------------------------------------- |
            | **Make**                  | C and C++ projects                             |
            | **CMake**                 | Generates build files for C/C++ projects       |
            | **Ninja**                 | Fast C/C++ builds                              |
            | **Gradle**                | Android, Java, Kotlin, and some C/C++ projects |
            | **Maven**                 | Java projects                                  |
            | **Ant**                   | Java projects                                  |
            | **MSBuild**               | C#, .NET, and Visual Studio projects           |
            | **Bazel**                 | Large multi-language projects                  |
            | **Meson**                 | C and C++ projects                             |
            | **SCons**                 | C, C++, and other languages                    |
            | **GNU Autotools**         | Traditional Linux and Unix C/C++ projects      |
            | **Premake**               | Generates project files for C/C++              |
            | **xmake**                 | Cross-platform C/C++ projects                  |
            | **Cargo**                 | Rust projects                                  |
            | **Go build**              | Go projects                                    |
            | **npm scripts**           | JavaScript and Node.js projects                |
            | **Webpack**               | Bundles JavaScript web applications            |
            | **Vite**                  | Builds modern web applications                 |
            | **Rake**                  | Ruby projects                                  |
            | **Swift Package Manager** | Swift projects                                 |
            | **Xcode Build System**    | Apple macOS and iOS applications               |            

    The basic relationship is:

        Source code
            ↓
        Build automation tool
            ↓
        Compiler and other tools
            ↓
        Finished application
    
    A useful distinction:s

        Make, Gradle, Maven, Ninja
        → directly manage build tasks

        CMake, Meson, Premake
        → often generate instructions for another build tool

        gcc, g++, clang
        → compilers, not build automation tools


Make:

    make is a build automation program. It reads instructions from a file called a Makefile and
    runs the required commands to build your program.

    For example, you run:

        </> bash
            
            make
        
        Then make:

            1. Opens the Makefile
            2. Checks which source files changed
            3. Runs compiler commands such as g++
            4. Produces the executable program

            Example

                Makefile:

                    app: main.cpp
                        g++ main.cpp -o app

                When you run:

                    make

                make executes:

                    g++ main.cpp -o app

                and creates:

                    app

    make is not a compiler, "make" does not compile C++ itself.

        Instead:

            make → reads build instructions
            g++  → compiles the C++ code

    What is MakeFile:

        A Makefile is a text file containing instructions for the make build tool.

        It tells make:

            - Which source files must be compiled
            - Which compiler to use
            - Which compiler options to use
            - How to create the final executable
            - Which files depend on other files

        Simple example

            Suppose you have:

                main.cpp
                math.cpp
                math.h

            A Makefile might contain:

                app: main.o math.o
                    g++ main.o math.o -o app

                main.o: main.cpp math.h
                    g++ -c main.cpp

                math.o: math.cpp math.h
                    g++ -c math.cpp

                clean:
                    rm -f main.o math.o app

            Then you run:

                make

            make reads the Makefile and creates:

                app

    Relationship

        Makefile = the build instructions
        make     = the program that reads the instructions for compiler (g++)
        g++      = the compiler that compiles the code


CMake:

    CMake is a tool that creates build instructions for C and C++ projects.

    CMake usually does not compile your code directly. Instead, it generates files for another build tool, such as:

        - Makefiles for make
        - Ninja build files
        - Visual Studio project files
        - Xcode project files

    Basic workflow:

        CMakeLists.txt
            ↓
            CMake
            ↓
        Makefile / Ninja files / Visual Studio project
            ↓
        make / Ninja / MSBuild
            ↓
        Compiler such as g++ or clang++
            ↓
        Executable program

    Example project

        MyProject/
        ├── CMakeLists.txt
        ├── main.cpp
        ├── math.cpp
        └── math.h

        A simple CMakeLists.txt:

            </> file

                cmake_minimum_required(VERSION 3.20)

                project(MyApp)

                add_executable(MyApp
                    main.cpp
                    math.cpp
                )

            This tells CMake:

                The minimum CMake version
                The project name
                Which source files belong to the executable

    Building the project

        From the project folder:

        </>

            cmake -S . -B build
            cmake --build build

        The first command:
            
            cmake -S . -B build

            (reads CMakeLists.txt and creates build files inside the build folder).

        The second command:

            cmake --build build

            (uses those generated files to compile and link the program).

    So the usual relationship is:

        CMake creates the Makefile
        make reads the Makefile
        g++ compiles the C++ code

    CMake VS Make:

        | CMake                                       | Make                             |
        | ------------------------------------------- | -------------------------------- |
        | Reads `CMakeLists.txt`                      | Reads a `Makefile`               |
        | Generates build instructions                | Executes build instructions      |
        | Works with many platforms and build systems | Usually executes Makefile rules  |
        | Common for cross-platform C++ projects      | Common as a low-level build tool |

    CMake is especially useful because the same CMakeLists.txt can be used on Windows, Linux, and
    macOS, even though each platform may use a different compiler or build system.


*/