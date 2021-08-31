#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

void main()
{
    int ss, sb, fd1, length, count;
    char buf[100];
    struct sockaddr_in sa, ta1;

    ss = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.01");
    sa.sin_port = 60018;

    sb = bind(ss, (struct sockaddr *)&sa, sizeof(sa));

    listen(ss, 5);

    length = sizeof(sa);
    fd1 = accept(ss, (struct sockaddr *)&ta1, &length);

    for (int i = 0; i < 100; i++)
        buf[i] = '\0';
    recv(fd1, &buf, 100, 0);
    printf("%s", buf);

    for (int i = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] == 'a' || buf[i] == 'e' || buf[i] == 'i' || buf[i] == 'o' || buf[i] == 'u' || buf[i] == 'A' || buf[i] == 'E' || buf[i] == 'I' || buf[i] == 'O' || buf[i] == 'U')
        {
            count++;
        }
    }
    send(fd1, &count, sizeof(int), 0);
    close(fd1);
}