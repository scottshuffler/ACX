main: acx.c
	avr-gcc -std=gnu99 -g -Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega2560 -DF_CPU=16000000L -MMD -DUSB_VID=null -DARDUINO=106 -I../lib -c -o ./output/acx.o acx.c 
	avr-gcc -std=gnu99 -g -Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega2560 -DF_CPU=16000000L -MMD -DUSB_VID=null -DARDUINO=106 -I../lib -c -o ./output/acx_asm.o acx_asm.s 


	avr-gcc -g -mmcu=atmega2560 -DF_CPU=16000000L -o ./output/acx.elf ./output/acx.o ./output/acx_asm.o
	avr-objcopy -O ihex -R .eeprom ./output/acx.elf ./output/acx.hex 

	#Starts up a screen to see serial output
	#sudo screen /dev/cu.usbmodem1421 19200

uploadMac:
	avrdude -v -v -patmega2560 -cwiring -P/dev/cu.usbmodemfa131 -b115200 -D -Uflash:w:./output/acx.hex:i 
uploadLinux:
	avrdude -v -v -patmega2560 -cwiring -P/dev/ttyACM0 -b115200 -D -Uflash:w:./output/acx.hex:i 