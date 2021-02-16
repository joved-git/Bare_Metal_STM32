CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0 -Wall
LDFLAGS= -T stm32_ls.ld -nostdlib -Wl,-Map=final.map

all: main.o stm32_startup.o final.elf

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

stm32_startup.o : stm32_startup.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf: main.o stm32_startup.o
	$(CC) $(LDFLAGS) $^ -o $@
clean:
	rm -rf *.o *.elf *.map

load:
	openocd -f board/st_nucleo_f4.cfg
