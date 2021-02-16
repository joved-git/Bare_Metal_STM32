rm -f main.c main.h led.c led.h

cp ./stm32f407x/makefile_f407x ./Makefile
cp ./stm32f407x/stm32_ls_f407x.ld ./stm32_ls.ld
cp ./stm32f407x/stm32_startup_f407x.c ./stm32_startup.c

cp ./stm32f407x/main.* .
cp ./stm32f407x/led.* .