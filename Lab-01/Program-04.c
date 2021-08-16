#include <stdio.h>
struct pkt
{
    char ch1;
    char ch2[2];
    char ch3;
};
int main()
{
    unsigned int i = 0x11706151;
    printf("Original Value: \n");
    printf("%x\n", i);
    struct pkt p;
    p.ch1 = i & 0xFF;
    p.ch2[0] = (i >> 8) & 0xFF;
    p.ch2[1] = (i >> 16) & 0xFF;
    p.ch3 = (i >> 24) & 0xFF;
    printf("Value after destructuring: \n");
    printf("%x, %x, %x, %x", p.ch1, p.ch2[0], p.ch2[1], p.ch3);
    unsigned int x;
    int a = p.ch3 << 24;
    int b = p.ch2[1] << 16;
    int c = p.ch2[0] << 8;
    int d = p.ch1;
    x = (a | b | c | d);
    printf("Value after aggregation: \n");
    printf("%x\n", x);
    return 0;
}