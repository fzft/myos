##
 

 ## main board   
    - bios
    - hard drive
    - cpu
        - registers
            - instrucure pointer
            - stack pointer

 ## boot procedure
 1. take the data from bios, contain assembly code
 2. copy the firmware to the RAM 
 3. tell process put you instrucure pointer to the RAM
 4. FW tell the cpu talk to the hard drive
 5. cpu read partition table and fs in the first megabytes the boot sector also into the RAM
 6. tell cpu jump into the bootloader, into second partition /boot/grub/grub.cfg, load these file contain menu entry which contain infomation about which os is where 
 7. the bootloader will print the list of operating system on your screen
 8. when choose, the grub tell this os on the partition  /boot/kernel.bin
 9. load kernel file to RAM, tell the cpu to jump into kernel bin


cpp os workaround :
    cpp program expect the stack pointer to be set before start running
    write two different file
        1. assemble file : load.s basically set stack pointer  jump into other file
            load.s will compile AS -> load.o
        2. kernel.cpp - > g++ 
            kernel.o
        3. ld combine two file above -> two kernel.bin
        4. these file put into /boot/ so that bootloader can find it  
        5. bootloader don't recognize kernel.bin (look at this file , it will look for magic number, )  so put the magic number in there
        6. before jump into kernel.bin, it some infomation draws from multiboot structure which contains some info : the size of RAM ... -> ax register
        7. copy the magic number into bx register, 
        8. we're outside of operating system, the regular printf it's inside dynamic lib
        dynamic lib connect our program and glibc
 RAM

 ### talk to hardware
        1. when communicate to hardware, everything needs to be byte perfect, we need to know
        exactly how many bytes are there, where are they, we need really precise
        2. returning assembly, assembly code give us a certain code
        3. program load into memory and jump into,  data segments, not allow, user space 
        4. key board, interrupted jump into
        5. idt switch memory segment
        6. deal with segment , create globel descriptor table


        code segment (can jump into)   data segment (now allowed )
        globel descriptor table (table of entries)
        start of segment, length of segment(1024), flags(this is code segment or data segments)

        8 bytes
        from low -> high
        2 bytes -> limit
        2 bytes -> pointer
        byte -> pointer
        byte -> access right
        half -> limit
        half -> flags
        byte -> pointer
4.hardware-communication /ports
    when you press a key on a keyboard, there will be a signal, which will go to PIC (programmable interrupt controller)
    not ignore that, need send some data there  
    mux demux, put a number in here , the mux or demux send data to the port recv data from that port
    asm(outb ) 
5. handle interrupt cpu would push a number a stack    

 1. FW 2. instructure pointer 3. bootloader 3.5 empty space 4. kernel bin 

 
