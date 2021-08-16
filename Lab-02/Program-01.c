//socket

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int sockFd, result;
    sockFd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockFd == -1)
    {
        printf("Socket not created Successfully!!\n");
    }
    else
    {
        printf("Socket created Successfully!!\n");
    }
    struct sockaddr_in X;
    X.sin_family = AF_INET;
    X.sin_port = ntohs(6000);
    X.sin_addr.s_addr = INADDR_ANY;
    int res = bind(sockFd, (struct sockaddr *)&X, sizeof(X));

    if (res == -1)
    {
        printf("Bind not created Succesfully!!\n");
    }
    else
    {
        printf("Bind created Succesfully!!\n");
    }

    return 0;
}