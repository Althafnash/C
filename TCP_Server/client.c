#include <netinet/in.h> // Structure for storing address information
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const* argv[]) 
{ 

    int sockD = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockD == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in servAddr; 

    servAddr.sin_family = AF_INET; 
    servAddr.sin_port = htons(9001); 
    servAddr.sin_addr.s_addr = INADDR_ANY; 

    int connectStatus = connect(sockD, (struct sockaddr*)&servAddr, sizeof(servAddr)); 
    if (connectStatus == -1) { 
        perror("Connection failed");
        close(sockD);
        exit(1);
    } 

    char strData[255]; 
    int bytesReceived = recv(sockD, strData, sizeof(strData), 0);
    if (bytesReceived > 0) {
        strData[bytesReceived] = '\0'; 
        printf("Message from server: %s\n", strData); 
    } else {
        printf("No data received\n");
    }

    char Sending_Msg[255];
    printf("\nEnter the message you want to send: ");
    fgets(Sending_Msg, sizeof(Sending_Msg), stdin); 

    int bytesSent = send(sockD, Sending_Msg, strlen(Sending_Msg), 0);
    if (bytesSent == -1) {
        perror("Failed to send message");
        close(sockD);
        exit(1);
    }

    close(sockD); 
    return 0; 
}
