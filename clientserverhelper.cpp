#include "TicTacToe.h"

using namespace std;

int output;
int readSize = 1;

// Parameter: Message to print
// No Return Value
// Prints Error Message and exits
void Error(const char *message)
{
    perror(message);
    exit(0);
}

// Parameters: Message to send, Socket to send message to
// No Return Value
// Sends Message to Socket
void SendMessage(int message, int sock)
{
    if (write(sock, &message, sizeof(int)) < 0)
    {
        Error("ERROR writing to socket");
    }
}

// Parameter: Socket to read from
// Returns Integer of read message
// Reads Message from socket
int ReadMessage(int sock)
{
    if (read(sock, &output, sizeof(int)) < 0)
    {
        Error("ERROR reading from Socket");
    }

    return output;
}

// Parameter: Win Result
// Returns 1 if Game is over, Returns 0 if Game Continues
// Processes the given Win Result to tell user the result
int ProcessWinnings(int winresult)
{
    if (winresult == 1)
    {
        printf("\nCongratulations! You Won!\n");
        return 1;
    }
    else if (winresult == 2)
    {
        printf("\nGame Over. Sorry, Computer Wins!\n");
        return 1;
    }
    else if (winresult == 3)
    {
        printf("\nGame Over. No Winner.\n");
        return 1;
    }

    return 0;
}