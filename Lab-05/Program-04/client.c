#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int cs, cb, value = 0;
    int buf[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    struct sockaddr_in sa;
    cs = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = 60018;

    cb = connect(cs, (struct sockaddr *)&sa, sizeof(sa));

    send(cs, &buf, 100, 0);
    recv(cs, &value, sizeof(int), 0);
    printf("Sum of array: %d\n", value);
    close(cs);
    return 0;
}