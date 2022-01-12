#include "types.h"
#include "gdt.h"

// specific memory location in RAM 0xb8000  [a, color info  ,b], this black and white or text in there in very beginning
// copy the high byte as same before and overwrite the low byte
void printf(char *str)
{
    static uint16_t *VideoMemeory = (uint16_t *)0xb8000;

    static uint8_t x = 0, y = 0;
    // copy str to this location
    for (int i = 0; str[i] != '\0'; ++i)
    {
        switch(str[i])
        {   
            case '\n':
                y++;
                x = 0;
                break;
            default:
                VideoMemeory[80 * y + x] = (VideoMemeory[80 * y + x] & 0xFF00) | str[i];
                x++;
        }
        
        if (x >= 80)
        {
            y++;
            x = 0;
        }
        if (y >= 25)
        {
            for (y = 0; y < 25; y++)
                for (x = 0; x < 80; x++)
                    VideoMemeory[80 * y + x] = (VideoMemeory[80 * y + x] & 0xFF00) | ' ';

            x = 0;
            y = 0;
        }
    }
}

extern "C" void kernelMain(void *mutlboot_structure, uint32_t magicnumber)
{
    printf("Hello Welcome to fzftOS\n");
    printf("Hello Welcome to fzftOS");
    GlobalDescriptorTable gdt;
    while (1)
        ;
}