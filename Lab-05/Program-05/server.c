#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int ss, sb, fd1, length, value = 0;
    int buf[100];
    struct sockaddr_in sa, ta1;

    ss = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = 60018;

    sb = bind(ss, (struct sockaddr *)&sa, sizeof(sa));

    listen(ss, 5);

    length = sizeof(sa);
    fd1 = accept(ss, (struct sockaddr *)&ta1, &length);
    recv(fd1, &buf, 100, 0);
    printf("Message recieved from Client: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", buf[i]);
    }

    for (int i = 0; i < 9; i++)
    {
        if (buf[i] > buf[i + 1])
        {
            int temp = buf[i];
            buf[i] = buf[i + 1];
            buf[i + 1] = temp;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", buf[i]);
    }

    value = buf[8];

    send(fd1, &value, sizeof(int), 0);
    close(fd1);
    return 0;
}