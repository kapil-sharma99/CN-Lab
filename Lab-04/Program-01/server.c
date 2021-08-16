#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int server_socket, bind_socket, count = 0, begin, end;
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = ntohs(6011);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind_socket = bind(server_socket, (struct sockaddr *)&servaddr, sizeof(struct sockaddr));
    struct sockaddr_in tempsendaddr;
    char buf[100], msg1[100];
    int len = sizeof(struct sockaddr);
    recvfrom(server_socket, buf, 100, 0, (struct sockaddr *)&tempsendaddr, &len);
    printf("Received message from client: %s\n", buf);

    while (buf[count] != '\0')
        count++;

    end = count - 1;

    for (begin = 0; begin < count; begin++)
    {
        msg1[begin] = buf[end];
        end--;
    }

    msg1[begin] = '\0';

    sendto(server_socket, msg1, sizeof(msg1), 0, (struct sockaddr *)&tempsendaddr, sizeof(struct sockaddr));
}