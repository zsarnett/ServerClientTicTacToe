#include "TicTacToe.h"
#include "clientserverhelper.h"

void StartTicTacToe(int);

// Parameter: Argument Count and Arguements
// Return Integer
// Connects to the Server
int main(int argc, char *argv[])
{
    struct sockaddr_in servAddr;
    struct in_addr servIP;
    struct hostent *server;

    int sockfd;

    if (argc != 2)
    {
        printf("Please use correct arguements when running client: ./client [IP_Address]\n");
        return 0;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        Error("Error Opening Socket");
    }

    if (!inet_aton(argv[1], &servIP))
    {
        Error("ERROR: Cannot parse IP given");
    }

    if ((server = gethostbyaddr((const void *)&servIP, sizeof(servIP), AF_INET)) == NULL)
    {
        Error("ERROR: No such Host");
    }

    printf("Host Found\n");

    bzero((char *)&servAddr, sizeof(servAddr));

    servAddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&servAddr.sin_addr.s_addr, server->h_length);
    servAddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
    {
        Error("Error Connecting");
    }
    printf("Connected to Server\n\n");

    StartTicTacToe(sockfd);
    close(sockfd);
    return 0;
}

// Parameter: Server Socket
// Not Return
// Starts the TicTacToe Game on the Client Side, Loops until Game Over
void StartTicTacToe(int sock)
{
    TicTacToe T;

    while (!gameover)
    {
        T.PrintGameGrid();

        T.PlayByUser();

        SendMessage(T.input1, sock); // Send Player Turn 1
        SendMessage(T.input2, sock); // Send Player Turn 2

        if ((gameover = ProcessWinnings(ReadMessage(sock)) == 1))
        {
            continue;
        }

        T.input1 = ReadMessage(sock); // Read Computer Turn 1
        T.input2 = ReadMessage(sock); // Read Computer Turn 2
        T.ggrid[T.input1][T.input2] = 'C';

        gameover = ProcessWinnings(ReadMessage(sock));
    }
    printf("Final Game Baord:\n");
    T.PrintGameGrid();
}