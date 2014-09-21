obj-m = test.o
all:
	make -C /home/pranith/kernel/linux/ M=$(PWD) modules
clean:
	make -C /home/pranith/kernel/linux/ M=$(PWD) clean

