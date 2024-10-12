#@copy_Right : Ziad Abdelhakeem
CC= arm-none-eabi-
CFLAGS =  -mcpu=cortex-m4  -gdwarf-2 -g
INCS = -I .
LIBS = 
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
PROJECT_NAME= unit_3__Lesson_4_cortex-m4

all: $(PROJECT_NAME).bin
	@echo " <<<<===== Build is Done ======>>>>  "

#startup.o: startup.s
#	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_Script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@


clean_all: 
	rm *.o *.elf *.bin

clea: 
	rm *.elf *.bin
	



	
