#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

void main()
{
    int cs, cb, count;
    char buf[100];
    struct sockaddr_in sa;
    cs = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = 60018;

    cb = connect(cs, (struct sockaddr *)&sa, sizeof(sa));
    strcpy(buf, "Welcome to KIIT\n");
    send(cs, &buf, 100, 0);
    recv(cs, &count, sizeof(int), 0);
    printf("%d\n", count);
    close(cs);
}