#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int client_socket, bind_socket;
    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in x;
    x.sin_family = AF_INET;
    x.sin_port = ntohs(6009);
    x.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind_socket = bind(client_socket, (struct sockaddr *)&x, sizeof(x));
    int msg[10] = {34, 45, 22, 13, 56, 88, 98, 23, 66, 91}, msg1[10];

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = ntohs(6011);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(client_socket, msg, sizeof(msg), 0, (struct sockaddr *)&server, sizeof(struct sockaddr));
    recvfrom(client_socket, &msg1, 100, 0, (struct sockaddr *)&server, sizeof(struct sockaddr));
    printf("Sorted array recieved from Server: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", msg1[i]);
    }
    close(client_socket);
    return 0;
}