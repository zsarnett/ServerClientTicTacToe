#include "TicTacToe.h"
#include "clientserverhelper.h"

using namespace std;

void StartTicTacToe(int);

// Parameter: Argument Count and Arguements
// Return Integer
// Initiates Server, Listens for Clients
int main(int argc, char *argv[])
{
    struct sockaddr_in servAddr, clientAddr;
    socklen_t clientLen;
    int sockfd, new_socket, pid;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        Error("ERROR Opening Socket");
    }
    printf("Socket Created\n");

    bzero((char *)&servAddr, sizeof(servAddr));

    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
    {
        Error("ERROR Binding");
    }
    printf("Binding Complete\n");

    listen(sockfd, 5);
    printf("Waiting for Player Connection - Port: %d\n", PORT);

    clientLen = sizeof(clientAddr);
    while (1)
    {
        if ((new_socket = accept(sockfd, (struct sockaddr *)&clientAddr, &clientLen)) < 0)
        {
            Error("ERROR Accepting");
        }

        printf("Accepted Connection from: %s\n", inet_ntoa(clientAddr.sin_addr));

        pid = fork();

        if (pid < 0)
        {
            Error("ERROR Forking");
        }
        if (pid == 0)
        {
            close(sockfd);
            StartTicTacToe(new_socket);
            exit(0);
        }
        else
        {
            close(new_socket);
        }
    }
}

// Parameter: Client Socket
// No Return Value
// Starts the TicTacToe Game on the Server Side, Loops until Game Over
void StartTicTacToe(int sock)
{
    TicTacToe T;

    while (gameover == 0)
    {
        T.input1 = ReadMessage(sock);
        T.input2 = ReadMessage(sock);
        T.ggrid[T.input1][T.input2] = 'U';
        printf("Move Received from Player: %d %d\n", T.input1, T.input2);

        gameover = T.CheckWinnings();
        SendMessage(gameover, sock);
        if (gameover > 0)
        {
            continue;
        }

        T.PlayByComputer();
        T.ggrid[T.input1][T.input2] = 'C';

        SendMessage(T.input1, sock);
        SendMessage(T.input2, sock);
        printf("Move Sent to Player: %d %d\n", T.input1, T.input2);

        gameover = T.CheckWinnings();
        SendMessage(gameover, sock);
    }
    printf("Connection with Player Closed\n");
    close(sock);
}