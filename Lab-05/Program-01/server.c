#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <unistd.h>
int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1)
    {
        perror("socket creation failed");
        exit(0);
    }
    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    server.sin_addr.s_addr = INADDR_ANY;
    int b = bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (b == -1)
    {
        perror("bind failed\n");
        exit(0);
    }
    printf("Bind succefully\n");
    listen(sockfd, 1);
    int size = sizeof(client);
    int newfd = accept(sockfd, (struct sockaddr *)&client, &size);
    if (newfd == -1)
    {
        perror("Accept failed\n");
        exit(0);
    }
    printf("Request comes from %u\n", (client.sin_addr.s_addr));
}