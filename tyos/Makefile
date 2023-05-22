boot_obj = stage1.o stage2.o utils.o

boot.bin : $(boot_obj) boot.ld rt0.o
	ld -melf_i386 --orphan-handling=discard -T boot.ld $(boot_obj) -o $@

stage1.o stage2.o utils.o :%.o: %.c
	gcc -m16 -O0 -I. -Wall -fno-pic -fcf-protection=none --freestanding -c $< -o $@

$(boot_obj) : utils.h

rt0.o : rt0.S
	gcc -m16 -O0 -Wall -c $< -o $@

floppy.img : boot.bin
	rm -f $@
	dd bs=512 count=2880 if=/dev/zero of=$@
	mkfs.fat -R 2 $@

boot.img : boot.bin floppy.img
	cp floppy.img $@
	dd conv=notrunc ibs=1 obs=1 skip=62 seek=62 if=$< of=$@

%.img/run : %.img
	qemu-system-i386 -drive format=raw,file=$< -net none

clean :
	rm -f *.bin *.elf *.o *.s *.iso *.img *.i
