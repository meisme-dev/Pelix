int init_kb(){
asm volatile("mov ah, 0h" \
             "int 0x16");
register int i asm("al");
return i;
}