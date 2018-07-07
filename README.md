# ESP32-WROOM-DEMOS
Various demo projects for ESP-WROOM-32 likely compatible with 8266 and other boards.


useful references

https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf

Arduino install and setup notes specific for ESP32.

check old install of arduino has been deleted.
- from windows button, search for arduino, right click, uninstall.
- C:\Users\username\Documents\ check Arduino and Arduino-xxx have been deleted.
- windows > settings > apps > search for arduino within installed apps

https://www.microsoft.com/
search arduino
open the windows app store
install arduino, 450MB download.

NB: until arduino is run, the directories assumed in the following steps do not exist.
run arduino. exit.

Follow these instructions assembled from
https://mytechsamples.blogspot.com/2017/10/install-and-integrate-esp32-esp-wroom.html
and
https://github.com/espressif/arduino-esp32
and
https://developers.wia.io/docs/wemos-esp-wroom-32

cd C:\Users\username\Documents\Arduino\
mkdir hardware
cd hardware
mkdir espressif
cd espressif
git clone https://github.com/espressif/arduino-esp32.git esp32
nb: destination directory is important, o/wise git installs in arduino-esp32


nb: git was missing from the linked instructions
cd esp32
git submodule update --init --recursive
nb: above recursive is important!!!


on windows we need to execute get.exe in dir as _ADMINISTRATOR_!!!
C:\Users\username\Documents\Arduino\hardware\espressif\esp32\tools

this downloads xtensa-esp32-elf-32 & installs

install drivers for windows to communicate with the ESP-WROOM-32 board.
nbb: when working with other boards, will likely require different drivers.
https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers
unzip file > I used C:\Users\username\Documents\CP210x_Universal_Windows_Driver
open CP210x_Universal_Windows_Driver_ReleaseNotes.txt
run CP210xVCPInstaller_x64.exe  this installs the driver  

Check devices (control panel > devices or 'device manager')
 - control panel > devices  > ports (COM & LPT)
 - Silicon Labs CP210x USB to UART Bridge should appear. Check com port.
 - check port settings - need 115200, 8 data bits,  parity = none, stop bits 1

in arduino :
 - check port and board shown in bottom right corner.
 - menu > tools > select port.
 - click on * star top right to open serial monitor, select baud to match baud rate in windows driver.
 - sketch also needs to open serial at same baud rate. ie: 3 baud rates must match.





open arduino, now we need to tell arduino where to get info on new boards.

menu > file > preferences > 'Additional Boards managers URLs'

https://dl.espressif.com/dl/package_esp32_dev_index.json

[NB: had to dig through multiple git issues and outdated howto's to find this on 6th July 2018.]

[for reference : this covers esp8266]
http://arduino.esp8266.com/stable/package_esp8266com_index.json

NB: we can update default location for new sketchbooks by also updating from
'C:\Users\username\Documents\Arduino' to new directory

NBB: other configs worth changing from default.
- display line numbers.
- enable code folding.


to update board configuration selected in arduino.
menu > tools >
open boards manager
search for ESP32, will find ESP32 by expressif systems.
@ 6th july 2018 was rev 1.0.0rc2
takes a few minutes to download.
more info links to https://github.com/espressif/arduino-esp32

close Arduino
reopen Arduino  
Menu > tools > board > select board  "ESP Dev Board" from list.
menu > Tools > port > select port to match port nominated in windows > devices

now load sketch and test serial port connection.


some sketches will require external libraries.

arduino > menu > sketch > include library > manage libraries > search for name of library to be downloaded.
s
