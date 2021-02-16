rm -f main.c main.h led.c led.h

cp ./stm32f103x/makefile_f103x ./Makefile
cp ./stm32f103x/stm32_ls_f103x.ld ./stm32_ls.ld
cp ./stm32f103x/stm32_startup_f103x.c ./stm32_startup.c
cp ./stm32f103x/main_f103x.c ./main.c