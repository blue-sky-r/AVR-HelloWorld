# AVR-HelloWorld

Very simple "Hello World" app to test setup of your development environment.

## Development Environment

Minimalistic AVR development environment mostly consist of:

* GUI editor configured to handle project / workspace
* compiler / assembler to build project files
* AVR programmer to upload the compiled binaries to AVR prototype
* communication tool like terminal to receive data back from AVR prototype

All parts have to be properly configured for seamless integration.
Other optional parts might get included, but four listed above are the basic ones.

To configure the parts and verify their functionality we need simple app like "Hello World"

The following example is demonstrating linux AVR IDE setup:

* GUI Editor ... Code::Blocks
* compiler   ... gcc-avr, avr-libc
* programmer ... avrdude, USB ASP clone
* terminal   ... minicom / usbasp_uart

### Step 1 - compiler

AVR gcc version 4.8.2 and AVR libc version 1.8.0

### Step 2 - GUI Editor

The Code::Blocks version 16.10 32-bit version:


### Step 3 - source files

The "Hello World" mini-app consists of two files:

    * main.c  ... with executable code
    * fuses.c ... with configuration settings

### Step 4 - compile

### Step 5 - AVR prototype

### Step 5 - programmer

### Step 6 - program the code and fuses

### Step 7 - communication

### Done

Congratulation ! Now you just have a working AVR-IDE.

