#include "vga.h"

uint16 vga_start(unsigned char ch, uint8 fore_color, uint8 back_color) 
{
  uint16 ax = 0;
  uint8 ah = 0, al = 0;

  ah = back_color;
  ah <<= 4;
  ah |= fore_color;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

//clear video buffer array
void clear_vga_buffer(uint16 **buffer, uint8 fore_color, uint8 back_color)
{
  uint32 i;
  for(i = 0; i < BUFFER_SIZE; i++){
    (*buffer)[i] = vga_start(0, fore_color, back_color);
  }
}

//initialize vga buffer
void init_vga(uint8 fore_color, uint8 back_color)
{
  vga_buffer = (uint16*)VGA_ADDRESS;  //point vga_buffer pointer to VGA_ADDRESS 
  clear_vga_buffer(&vga_buffer, fore_color, back_color);  //clear buffer
}

void vga_entry()
{
  //first init vga with fore & back colors
  init_vga(WHITE, BLACK);

  //assign each ASCII character to video buffer
  //you can change colors here
  vga_buffer[0] = vga_start('[', WHITE, BLACK);
  vga_buffer[1] = vga_start('O', GREEN, BLACK);
  vga_buffer[2] = vga_start('K', GREEN, BLACK);
  vga_buffer[3] = vga_start(']', WHITE, BLACK);
  vga_buffer[4] = vga_start(' ', WHITE, BLACK);
  vga_buffer[5] = vga_start('S', WHITE, BLACK);
  vga_buffer[6] = vga_start('y', WHITE, BLACK);
  vga_buffer[7] = vga_start('s', WHITE, BLACK);
  vga_buffer[8] = vga_start('t', WHITE, BLACK);
  vga_buffer[9] = vga_start('e', WHITE, BLACK);
  vga_buffer[10] = vga_start('m', WHITE, BLACK);
  vga_buffer[11] = vga_start(' ', WHITE, BLACK);
  vga_buffer[12] = vga_start('U', WHITE, BLACK);
  vga_buffer[13] = vga_start('p', WHITE, BLACK);
  vga_buffer[14] = vga_start('!', WHITE, BLACK);


}