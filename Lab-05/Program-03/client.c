#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int cs, cb, value;
    char buf[100];
    struct sockaddr_in sa;
    cs = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = 60018;

    cb = connect(cs, (struct sockaddr *)&sa, sizeof(sa));

    for (int i = 0; i < 100; i++)
        buf[i] = '\0';
    strcpy(buf, "ABCBA\n");
    send(cs, &buf, 100, 0);
    recv(cs, &value, sizeof(int), 0);
    if (value == 1)
    {
        printf("Yes, the given string is a Palindrome!!\n");
    }
    else
    {
        printf("No, the given string is not a Palindrome!!\n");
    }
    close(cs);
    return 0;
}