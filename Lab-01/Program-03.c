#include <stdio.h>

typedef unsigned char BYTE;

int main()
{
    unsigned int value = 0x11223344; //4 Bytes value

    BYTE a, b, c, d; //to store byte by byte value

    a = (value & 0xFF);         //extract first byte
    b = ((value >> 8) & 0xFF);  //extract second byte
    c = ((value >> 16) & 0xFF); //extract third byte
    d = ((value >> 24) & 0xFF); //extract fourth byte

    printf("a= %02X\n", a);
    printf("b= %02X\n", b);
    printf("c= %02X\n", c);
    printf("d= %02X\n", d);
    return 0;
}