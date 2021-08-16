#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int server_socket, bind_socket;
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = ntohs(6011);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(server_socket, (struct sockaddr *)&servaddr, sizeof(struct sockaddr));
    struct sockaddr_in tempsendaddr;
    char buf[100];
    int len = sizeof(struct sockaddr);
    recvfrom(server_socket, buf, 100, 0, (struct sockaddr *)&tempsendaddr, &len);
    printf("Receive from : %s", buf);
}