#ifndef TicTacToe_H
#define TicTacToe_H

#include <iostream>
#include <ctime>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

class TicTacToe
{
public:
  TicTacToe();
  void PrintGameGrid();
  void PlayByUser();
  void PlayByComputer();
  int CheckWinnings();
  char ggrid[3][3];
  int input1;
  int input2;
};

#endif