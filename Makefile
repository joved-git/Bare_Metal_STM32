CC=arm-none-eabi-gcc
MACH=cortex-m3
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0 -Wall
LDFLAGS= -T stm32_ls.ld -nostdlib -Wl,-Map=final.map

all: final.elf

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf: main.o stm32_startup.o
	$(CC) $(LDFLAGS) $^ -o $@
clean:
	rm -rf *.o *.elf *.map

load:
	openocd -f board/bluepill.cfg
