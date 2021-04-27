# SLIP-Echo
SLIP (Serial IP) Echo Test on Hercules LAUNCHXL2-RM46L852 board

## Build Guide:
On **command line**, execute the following: 
- cd Desktop
- git clone https://github.com/TejasAnilkumar12/SLIP-Echo.git

Now follow the steps below:
- Open Code Composer Studio
- **Project** &#8594; Import CCS project &#8594; Browse
- Select the directory SLIP_Echo, check Discovered projects and click on Finish.
- Right click on the Project and select Properties.
- **Build** &#8594; ARM Compiler &#8594; Include Options
- Add the locations of include and source directory
- Now, click on Build Project.

## Flashing  Guide:
You can use CCS UniFlash(Windows only) or Code Composer Studio to Flash the program onto Hercules Launchpad.
Below are the steps for Flashing:
- On Code Composer Studio
- Right click on the Project and select Properties.
- **Build** &#8594; Debug Compiler &#8594; Flash Settings
- On CCS UniFlash
- **File** &#8594; New Configuration
- Connection will be Texas Instruments XDS110 USB Debug Probe and Board or Device will RM46L852
- Flash Settings will be similar. Leave the defaults as it is. Check on Verify.
- In Erase Options, check Entire Flash.
- CCS UniFlash requires an additional step of providing the .out file. This is located based on the build version i.e. Debug or Release.
- **Select Programs**  &#8594; Add  &#8594; Location of SLIP_Echo.out 
- Code Composer Studio will automatically flash when debug is selected. 
- For CCS UniFlash, click on program option to flash the file.
- Reset the board.

## Test:
On Windows, use Device Manager to find the UART port of XDS110
On Linux, the Port is usually ttyACM0 (Use dmesg | grep serial to find information) 
- Open a Serial COM port with Baud Rate of 9600 and two Stop-bits using PuTTY
- You should see SLIP Echo Test.
- Send data in SLIP Format with the END character and it will be echoed back in the SLIP format.

| SLIP Character  |Hex Value | ASCII Value|
| ------------- | ------------- | ------------- |
| END           | 0xC0          |       À       |
| ESC           | 0xDB          |       Û       |
| ESC_END       | 0xDC          |       Ü       |
| ESC_ESC       | 0xDD          |       Ý       |

# Example Case 1:
Data with **ESC** character:
abcd**Û**
**Encoded Packet:**
ÀabcdÛÝÀ

# Example Case 2:
Data with **END** Character:
ab**À**cd
**Encoded Packet:**
ÀabÛÜcdÀ





  
