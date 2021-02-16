rm -f main.c main.h led.c led.h

cp ./stm32f446x/makefile_f446x ./Makefile
cp ./stm32f446x/stm32_ls_f446x.ld ./stm32_ls.ld
cp ./stm32f446x/stm32_startup_f446x.c ./stm32_startup.c
cp ./stm32f446x/main_f446x.c ./main.c
