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

*/