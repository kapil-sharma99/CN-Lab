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
    char msg[] = "Kapil", msg1[100];

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = ntohs(6011);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(client_socket, msg, sizeof(msg), 0, (struct sockaddr *)&server, sizeof(struct sockaddr));

    recvfrom(client_socket, msg1, 100, 0, (struct sockaddr *)&server, sizeof(struct sockaddr));
    printf("Recieved Reversed String: %s\n", msg1);
    close(client_socket);
}