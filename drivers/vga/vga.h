#ifndef VGA_H
#define VGA_H
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
#define VGA_ADDRESS 0xB8000
#define BUFFER_SIZE 2200
uint16* vga_buffer;
enum colors {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    PINK,
    BROWN,
    GRAY,
    DARK_GRAY,
    VIBRANT_BLUE,
    VIBRANT_GREEN,
    VIBRANT_CYAN,
    VIBRANT_RED,
    VIBRANT_PINK,
    YELLOW,
    WHITE,
};
#endif