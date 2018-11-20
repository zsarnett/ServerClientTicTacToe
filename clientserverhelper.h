#ifndef ClientServerHelper_H
#define ClientServerHelper_H

int ReadMessage(int sock);
int ProcessWinnings(int winresult);
void SendMessage(int message, int sock);
void Error(const char *message);

int PORT = 8090;
int gameover = 0;

#endif