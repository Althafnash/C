#include <netinet/in.h> //structure for storing address information 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h> //for socket APIs 
#include <sys/types.h> 
#include <string.h>

int main(int argc, char const* argv[])
{
	int servSockD = socket(AF_INET, SOCK_STREAM, 0);

	char serMsg[255] = "Message from the server to the "
					"client \'Hello Client\' ";

	struct sockaddr_in servAddr;

	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(9001);
	servAddr.sin_addr.s_addr = INADDR_ANY;

	bind(servSockD, (struct sockaddr*)&servAddr, 
		sizeof(servAddr));

	listen(servSockD, 1);

	int clientSocket = accept(servSockD, NULL, NULL);

	send(clientSocket, serMsg, sizeof(serMsg), 0);

	char recvBuffer[255]; 
    memset(recvBuffer, 0, sizeof(recvBuffer)); 

    int bytesReceived = recv(clientSocket, recvBuffer, sizeof(recvBuffer) - 1, 0);  

    if (bytesReceived < 0) {
        perror("recv failed");
        exit(1);
    }

    recvBuffer[bytesReceived] = '\0';

    printf("Received from client: %s\n", recvBuffer);

	return 0;
}
