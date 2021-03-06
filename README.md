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

* GUI Editor ... Code::Blocks IDE
* compiler   ... gcc-avr, avr-libc
* programmer ... avrdude, USB ASP clone, 9-10 male-male cable (Du-Pont)
* terminal   ... minicom, cu / usbasp_uart

### Step 1 - compiler

AVR gcc version 4.8.2 and AVR libc version 1.8.0

### Step 2 - GUI Editor

The Code::Blocks version 16.10 32-bit version:

### Step 3 - source files

The "Hello World" mini-app consists of two files:

	* main.c  ... executable code
	* fuses.c ... configuration settings

### Step 4 - compile

Build / Rebuild should result in 0 errors and 0 warnings

	Process terminated with status 0 (0 minute(s), 0 second(s))
	0 error(s), 0 warning(s) (0 minute(s), 0 second(s))

### Step 5 - AVR prototype

Buils a simple atmega328 breadboard prototype:

	* Vcc, GND from USBasp
	* resistor on RESET [ pin 1 and Vcc ] value is not critical 10k-100k
	* LED on any pin like pin 14 (Port B Bit 0 = PortB0) and resistor 10k-1k to GND
	* USBasp [ will supply Vcc ]

![Bredboard](images/breadboard.jpg) 

![Bredboard](images/breadboard-angle.jpg)

![USBASP cable](images/cable-a.jpg) 

![USBASP cable](images/cable-b.jpg) 
	
### Step 5 - programmer

USBasp clone - consider upgrading the firmware with UART modality [USBasp UART](https://github.com/akrasuski1/usbasp-uart)

To update USBasp firmware use the second USBasp module. You can buy USBasp clones on ebay for a few bucks so get two pieces.
Connect both modules via flat cable and then close jumper JP2 on the module to be updated. 
The module without JP2 jumper connect to the PC USB port and then run update.

![USBASP FW upgrade](images/usbasp-fw-upgrade.jpg)

### Step 6 - program the code and fuses

From command line:

	avrdude -p m328p -P usb -c usbasp-clone -U flash:w:blink.hex -U lfuse:w:blink.lfs

screenshot

IDE Code::Blocks click Tools / Configure tools / Add 

	Name: Flash
	Executable: avrdude
	Parameters: -p m328p -P usb -c usbasp-clone -U flash:w:${TARGET_OUTPUT_BASENAME}.hex
	Working dir: ${PROJECT_DIR}/${TARGET_OUTPUT_DIR}

screenshot

IDE Code::Blocks click Tools / Configure tools / Add 

	Name: Fuses
	Executable: avrdude
	Parameters: -p m328p -P usb -c usbasp-clone \ 
			-U lfuse:w:{$TARGETOUTPUTBASENAME}.lfs \ 
			-U hfuse:w:{$TARGETOUTPUTBASENAME}.hfs \ 
			-U efuse:w:{$TARGETOUTPUTBASENAME}.efs
	Working dir: ${PROJECT_DIR}/${TARGET_OUTPUT_DIR}

screenshot

### Step 7 - communication

Either use [USBASP with UART modality](https://github.com/akrasuski1/usbasp-uart)

and execute: 
	
	./usbasp_uart 

picture

or connect any serial port RX pin 3 (TxD) and configure 9600-8N1

should echo stream of U characters

picture

screenshot

### Done

Congratulations ! Now you just have a working AVR-IDE.

