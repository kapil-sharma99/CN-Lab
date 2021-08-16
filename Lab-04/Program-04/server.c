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
    int buf[10];
    int len = sizeof(struct sockaddr);
    recvfrom(server_socket, buf, 100, 0, (struct sockaddr *)&tempsendaddr, &len);
    printf("Received message(unsorted array) from client: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", buf[i]);
    }

    int counter = 1;
    while (counter < 9)
    {
        for (int i = 0; i < 10 - counter; i++)
        {
            if (buf[i] > buf[i + 1])
            {
                int temp = buf[i];
                buf[i] = buf[i + 1];
                buf[i + 1] = temp;
            }
        }
        counter++;
    }

    sendto(server_socket, &buf, sizeof(buf), 0, (struct sockaddr *)&tempsendaddr, sizeof(struct sockaddr));
}