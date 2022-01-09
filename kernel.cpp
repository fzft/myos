#include "types.h"

// specific memory location in RAM 0xb8000  [a, color info  ,b], this black and white or text in there in very beginning
// copy the high byte as same before and overwrite the low byte
void printf(char* str)
{
    static uint16_t* VideoMemeory = (uint16_t*)0xb8000;

    // copy str to this location
    for (int i = 0; str[i] != '\0'; ++i)
        VideoMemeory[i] = (VideoMemeory[i] & 0xFF00) | str[i];
}

extern "C" void kernelMain(void* mutlboot_structure, uint32_t /*magicnumber* /)
{
    printf("Hello Welcome to fzftOS");

    while (1)
        ;
}