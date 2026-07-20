/*

Reading a GitHub project is like exploring a new city: do not try to understand every street immediately.
First understand the map, then follow one path through the program.

    1. Start with the README

        Open the project’s main GitHub page and look for:

            README.md

        The README usually explains:

            - What the project does
            - Which programming language it uses
            - How to install or compile it
            - How to run it
            - Basic examples

    2. Identify the programming language

        Look for file extensions:

            - .cpp, .h, .hpp, .cxx, .cc, .c++ for C++
            - .py for Python
            - .java for Java
            - .js for JavaScript
            - .rb for Ruby
            - .go for Go
            - .rs for Rust

            | Extension                   | Language                 |
            | --------------------------- | ------------------------ |
            | `.cpp`, `.cc`, `.h`, `.hpp` | C++                      |
            | `.c`, `.h`                  | C                        |
            | `.java`                     | Java                     |
            | `.kt`                       | Kotlin                   |
            | `.py`                       | Python                   |
            | `.js`, `.ts`                | JavaScript or TypeScript |
            | `.cs`                       | C#                       |

    3. Understand the main folders

        Look for folders like:

            - src or source: contains the main source code (.cpp files & .h files)
            - include: contains header files (.h or .hpp files)
            - tests or test: contains unit tests (assets/samples and main.cpp file or c++ main() function)            
            - examples: contains example usage (main.cpp file or c++ main() function)
            - lib: contains libraries
            - docs: contains documentation
            - build or cmake: contains build scripts (CMakeLists.txt, Makefile, etc.)

    4. Find the program’s entry point

        The entry point is where the program starts.

        In C++, look for:

            - main.cpp
            - main.cxx
            - main.cc
            - main.c++
            - main() function

            Example:

                int main() {
                    Scanner scanner;
                    scanner.start();

                    return 0;
                }

            This tells you that the program:

                1.Creates a Scanner
                2. Calls scanner.start()
                3. Ends

                Then find where Scanner is defined.

        In Java, look for:

            public static void main(String[] args)

        In Python, look for:

            if __name__ == "__main__":

        In Kotlin, look for:

            class MainActivity : ComponentActivity()

        In Android, look for:

            Android applications normally do not have a traditional main() function.

            Start with files such as:

                AndroidManifest.xml
                MainActivity.kt
                MainActivity.java

    5. Follow one function at a time (This is called tracing the program flow)

        Suppose the main file contains:

            int main() {
                BarcodeReader reader;
                reader.openImage("barcode.png");
                reader.decode();
            }

            Do not read every file. Follow this path:

                main()
                  ↓
                BarcodeReader
                  ↓
                openImage()
                  ↓
                decode()

            Find the definition of each function. For example:

                void BarcodeReader::decode() {
                    result = ZXing::ReadBarcode(image);
                }

                Now you know that decode() uses ZXing to read the barcode.

    6. Separate declarations from implementations
    
        In C++, a header might contain a declaration:

            // BarcodeReader.h

            class BarcodeReader {
            public:
                void decode();
            };

        The source file contains the implementation:

            // BarcodeReader.cpp

            void BarcodeReader::decode() {
                // Actual code
            }

        The header tells you:

            This function exists.

        The .cpp file tells you:

            This is what the function does.

    7. Understand the build files of builder tools (CMake, Makefile, etc.)

        Build files explain how the project is compiled.

            Common examples:

                CMakeLists.txt      C or C++ using CMake
                Makefile            C or C++
                build.gradle        Android, Java, or Kotlin
                pom.xml             Java using Maven
                package.json        JavaScript or TypeScript
                requirements.txt    Python dependencies
                Cargo.toml          Rust

            For a C++ project, you might see:

                add_executable(barcode_app
                    src/main.cpp
                    src/BarcodeReader.cpp
                )

                This tells you which files are combined to create the program.

            You may also see:

                target_link_libraries(barcode_app ZXing)

                This means the program uses the ZXing library.

    8. Look at examples before complicated source code

        The easiest files for beginners are often inside:

            examples/
            demo/
            samples/

        An example may show the entire basic usage:

            #include <ZXing/ReadBarcode.h>

            int main() {
                auto result = ZXing::ReadBarcode(image);

                if (result.isValid()) {
                    std::cout << result.text();
                }
            }

        This is usually easier than starting with the internal library code.

    9. Ignore difficult parts at first

        You do not need to understand these immediately:

            .github/
            .gitignore
            LICENSE
            build/
            generated/
            third_party/
            vendor/

        Also avoid reading external library code first. Focus on the project’s own:

            main file
            examples
            public classes
            important functions

*/