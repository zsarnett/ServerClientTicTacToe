#include "TicTacToe.h"

using namespace std;

// Class Constructor
// No Parameters
// No Return Value
// Constructs the Gaming Grid with Question Marks
TicTacToe::TicTacToe()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ggrid[i][j] = '?';
        }
    }
}

// No Parameters
// No Return Value
// Decides Computer's Play by looking at the best move based on current Board
void TicTacToe::PlayByComputer()
{
    if (ggrid[0][0] == 'C' && ggrid[0][1] == 'C' && ggrid[0][2] == '?') //1 - 2 = 3 win
    {
        input1 = 0;
        input2 = 2;
        return;
    }

    if (ggrid[1][0] == 'C' && ggrid[1][1] == 'C' && ggrid[1][2] == '?') //4 - 5 = 6 win
    {
        input1 = 1;
        input2 = 2;
        return;
    }

    if (ggrid[2][0] == 'C' && ggrid[2][1] == 'C' && ggrid[2][2] == '?') //7 - 8 = 9 win
    {
        input1 = 2;
        input2 = 2;
        return;
    }

    if (ggrid[0][0] == 'C' && ggrid[1][0] == 'C' && ggrid[2][0] == '?') //1 - 4 = 7 win
    {
        input1 = 2;
        input2 = 0;
        return;
    }

    if (ggrid[0][1] == 'C' && ggrid[1][1] == 'C' && ggrid[2][1] == '?') //2 - 5 = 8 win
    {
        input1 = 2;
        input2 = 1;
        return;
    }

    if (ggrid[0][2] == 'C' && ggrid[1][2] == 'C' && ggrid[2][2] == '?') //3 - 6 = 9 win
    {
        input1 = 2;
        input2 = 2;
        return;
    }

    if (ggrid[0][0] == 'C' && ggrid[1][1] == 'C' && ggrid[2][2] == '?') //1 - 5 = 9 win
    {
        input1 = 2;
        input2 = 2;
        return;
    }

    if (ggrid[0][2] == 'C' && ggrid[1][1] == 'C' && ggrid[2][0] == '?') //3 - 5 = 7 win
    {
        input1 = 2;
        input2 = 0;
        return;
    }
    if ((ggrid[0][0] == 'C' && ggrid[2][2] == 'C') && ggrid[1][1] == '?') //1 - 9 = 5 diagonal
    {
        input1 = 1;
        input2 = 1;
        return;
    }

    if ((ggrid[1][1] == 'C' && ggrid[2][2] == 'C') && ggrid[0][0] == '?') //5 - 9 = 1 diagonal
    {
        input1 = 0;
        input2 = 0;
        return;
    }
    if ((ggrid[2][0] == 'C' && ggrid[1][1] == 'C') && ggrid[0][2] == '?') //7 - 5 = 3 diagonal
    {
        input1 = 0;
        input2 = 2;
        return;
    }

    if ((ggrid[2][0] == 'C' && ggrid[0][2] == 'C') && ggrid[1][1] == '?') //7 - 3 = 5 diagonal
    {
        input1 = 1;
        input2 = 1;
        return;
    }
    if ((ggrid[0][0] == 'C' && ggrid[0][2] == 'C') && ggrid[0][1] == '?') //1 - 3 = 2 horizontal
    {
        input1 = 0;
        input2 = 1;
        return;
    }

    if ((ggrid[0][1] == 'C' && ggrid[0][2] == 'C') && ggrid[0][0] == '?') //2 - 3 = 1 horizontal
    {
        input1 = 0;
        input2 = 0;
        return;
    }
    if ((ggrid[1][0] == 'C' && ggrid[1][2] == 'C') && ggrid[1][1] == '?') //4 - 6  = 5 horizontal line 2
    {
        input1 = 1;
        input2 = 1;
        return;
    }

    if ((ggrid[1][1] == 'C' && ggrid[1][2] == 'C') && ggrid[1][0] == '?') //5 - 6 = 4 horizontal line 2
    {
        input1 = 1;
        input2 = 0;
        return;
    }
    if ((ggrid[2][0] == 'C' && ggrid[2][2] == 'C') && ggrid[2][1] == '?') //7 - 9 = 8 horizontal line 3
    {
        input1 = 2;
        input2 = 1;
        return;
    }

    if ((ggrid[2][1] == 'C' && ggrid[2][2] == 'C') && ggrid[2][0] == '?') //8 - 9 = 7 horizontal line 3
    {
        input1 = 2;
        input2 = 0;
    }
    if ((ggrid[0][0] == 'C' && ggrid[2][0] == 'C') && ggrid[1][0] == '?') //1 - 7 = 4 vertical row 1
    {
        input1 = 1;
        input2 = 0;
        return;
    }

    if ((ggrid[1][0] == 'C' && ggrid[2][0] == 'C') && ggrid[0][0] == '?') //4 - 7 = 1 vertical row 1
    {
        input1 = 0;
        input2 = 0;
        return;
    }
    if ((ggrid[0][1] == 'C' && ggrid[2][1] == 'C') && ggrid[1][1] == '?') //2 - 8 = 5 vertical row 2
    {
        input1 = 1;
        input2 = 1;
        return;
    }

    if ((ggrid[1][1] == 'C' && ggrid[2][1] == 'C') && ggrid[0][1] == '?') //5 - 8 = 2 vertical row 2
    {
        input1 = 0;
        input2 = 1;
        return;
    }
    if ((ggrid[0][2] == 'C' && ggrid[2][2] == 'C') && ggrid[1][2] == '?') //3 - 9 = 6 vertical row 3
    {
        input1 = 1;
        input2 = 2;
        return;
    }

    if ((ggrid[1][2] == 'C' && ggrid[2][2] == 'C') && ggrid[0][2] == '?') //6 - 9 = 3 vertical row 3
    {
        input1 = 0;
        input2 = 2;
        return;
    }

    if ((input1 == 0 && input2 == 0) || (input1 == 1 && input2 == 1) || (input1 == 2 && input2 == 2))
    {
        if ((ggrid[0][0] == 'U' && ggrid[1][1] == 'U') && ggrid[2][2] == '?') //1 - 5 = 9 diagonal
        {
            input1 = 2;
            input2 = 2;
            return;
        }

        if ((ggrid[0][0] == 'U' && ggrid[2][2] == 'U') && ggrid[1][1] == '?') //1 - 9 = 5 diagonal
        {
            input1 = 1;
            input2 = 1;
            return;
        }

        if ((ggrid[1][1] == 'U' && ggrid[2][2] == 'U') && ggrid[0][0] == '?') //5 - 9 = 1 diagonal
        {
            input1 = 0;
            input2 = 0;
            return;
        }
    }

    if ((input1 == 0 && input2 == 2) || (input1 == 1 && input2 == 1) || (input1 == 2 && input2 == 0))
    {
        if ((ggrid[2][0] == 'U' && ggrid[1][1] == 'U') && ggrid[0][2] == '?') //7 - 5 = 3 diagonal
        {
            input1 = 0;
            input2 = 2;
            return;
        }

        if ((ggrid[2][0] == 'U' && ggrid[0][2] == 'U') && ggrid[1][1] == '?') //7 - 3 = 5 diagonal
        {
            input1 = 1;
            input2 = 1;
            return;
        }

        if ((ggrid[1][1] == 'U' && ggrid[0][2] == 'U') && ggrid[2][0] == '?') //5 - 3 = 7 diagonal
        {
            input1 = 2;
            input2 = 0;
            return;
        }
    }

    if ((input1 == 0 && input2 == 0) || (input1 == 0 && input2 == 1) || (input1 == 0 && input2 == 2))
    {
        if ((ggrid[0][0] == 'U' && ggrid[0][1] == 'U') && ggrid[0][2] == '?') // 1 - 2 = 3 horizontal
        {
            input1 = 0;
            input2 = 2;
            return;
        }

        if ((ggrid[0][0] == 'U' && ggrid[0][2] == 'U') && ggrid[0][1] == '?') //1 - 3 = 2 horizontal
        {
            input1 = 0;
            input2 = 1;
            return;
        }

        if ((ggrid[0][1] == 'U' && ggrid[0][2] == 'U') && ggrid[0][0] == '?') //2 - 3 = 1 horizontal
        {
            input1 = 0;
            input2 = 0;
            return;
        }
    }

    if ((input1 == 1 && input2 == 0) || (input1 == 1 && input2 == 1) || (input1 == 1 && input2 == 2))
    {
        if ((ggrid[1][0] == 'U' && ggrid[1][1] == 'U') && ggrid[1][2] == '?') //4 - 5 = 6 horizontal line 2
        {
            input1 = 1;
            input2 = 2;
            return;
        }

        if ((ggrid[1][0] == 'U' && ggrid[1][2] == 'U') && ggrid[1][1] == '?') //4 - 6  = 5 horizontal line 2
        {
            input1 = 1;
            input2 = 1;
            return;
        }

        if ((ggrid[1][1] == 'U' && ggrid[1][2] == 'U') && ggrid[1][0] == '?') //5 - 6 = 4 horizontal line 2
        {
            input1 = 1;
            input2 = 0;
            return;
        }
    }

    if ((input1 == 2 && input2 == 0) || (input1 == 2 && input2 == 1) || (input1 == 2 && input2 == 2))
    {
        if ((ggrid[2][0] == 'U' && ggrid[2][1] == 'U') && ggrid[2][2] == '?') //7 - 8 = 9 horizontal line 3
        {
            input1 = 2;
            input2 = 2;
            return;
        }

        if ((ggrid[2][0] == 'U' && ggrid[2][2] == 'U') && ggrid[2][1] == '?') //7 - 9 = 8 horizontal line 3
        {
            input1 = 2;
            input2 = 1;
            return;
        }

        if ((ggrid[2][1] == 'U' && ggrid[2][2] == 'U') && ggrid[2][0] == '?') //8 - 9 = 7 horizontal line 3
        {
            input1 = 2;
            input2 = 0;
            return;
        }
    }

    if ((input1 == 0 && input2 == 0) || (input1 == 1 && input2 == 0) || (input1 == 2 && input2 == 0))
    {
        if ((ggrid[0][0] == 'U' && ggrid[1][0] == 'U') && ggrid[2][0] == '?') //1 - 4 = 7 vertical row 1
        {
            input1 = 2;
            input2 = 0;
            return;
        }

        if ((ggrid[0][0] == 'U' && ggrid[2][0] == 'U') && ggrid[1][0] == '?') //1 - 7 = 4 vertical row 1
        {
            input1 = 1;
            input2 = 0;
            return;
        }

        if ((ggrid[1][0] == 'U' && ggrid[2][0] == 'U') && ggrid[0][0] == '?') //4 - 7 = 1 vertical row 1
        {
            input1 = 0;
            input2 = 0;
            return;
        }
    }

    if ((input1 == 0 && input2 == 1) || (input1 == 1 && input2 == 1) || (input1 == 2 && input2 == 1))
    {
        if ((ggrid[0][1] == 'U' && ggrid[1][1] == 'U') && ggrid[2][1] == '?') //2 - 5 = 8 vertical row 2
        {
            input1 = 2;
            input2 = 1;
            return;
        }

        if ((ggrid[0][1] == 'U' && ggrid[2][1] == 'U') && ggrid[1][1] == '?') //2 - 8 = 5 vertical row 2
        {
            input1 = 1;
            input2 = 1;
            return;
        }

        if ((ggrid[1][1] == 'U' && ggrid[2][1] == 'U') && ggrid[0][1] == '?') //5 - 8 = 2 vertical row 2
        {
            input1 = 0;
            input2 = 1;
            return;
        }
    }

    if ((input1 == 0 && input2 == 2) || (input1 == 1 && input2 == 2) || (input1 == 2 && input2 == 2))
    {
        if ((ggrid[0][2] == 'U' && ggrid[1][2] == 'U') && ggrid[2][2] == '?') //3 - 6 = 9 vertical row 3
        {
            input1 = 2;
            input2 = 2;
            return;
        }

        if ((ggrid[0][2] == 'U' && ggrid[2][2] == 'U') && ggrid[1][2] == '?') //3 - 9 = 6 vertical row 3
        {
            input1 = 1;
            input2 = 2;
            return;
        }

        if ((ggrid[1][2] == 'U' && ggrid[2][2] == 'U') && ggrid[0][2] == '?') //6 - 9 = 3 vertical row 3
        {
            input1 = 0;
            input2 = 2;
            return;
        }
    }

    srand(time(0));
    int d1 = rand() % 3;
    int d2 = rand() % 3;

    while (!(ggrid[d1][d2] == '?'))
    {
        d1 = rand() % 3;
        d2 = rand() % 3;
    }
    input1 = d1;
    input2 = d2;
}

// No Parameters
// Returns Integer based on who wins the game.
// 0 : Game Not Over
// 1 : Player Wins
// 2 : Computer Wins
// 3 : Neither Wins. Game Over
// Checks the game board for 3 'C' or 'U' Characters in a row
int TicTacToe::CheckWinnings()
{
    for (int i = 0; i < 3; i++)
    {
        if ((ggrid[i][0] == ggrid[i][1]) && (ggrid[i][1] == ggrid[i][2]))
        {
            if (ggrid[i][0] == 'U')
            {
                return 1;
            }

            if (ggrid[i][0] == 'C')
            {
                return 2;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if ((ggrid[0][i] == ggrid[1][i]) && (ggrid[1][i] == ggrid[2][i]))
        {
            if (ggrid[0][i] == 'U')
            {
                return 1;
            }

            if (ggrid[0][i] == 'C')
            {
                return 2;
            }
        }
    }

    if ((ggrid[0][0] == ggrid[1][1]) && (ggrid[1][1] == ggrid[2][2]))
    {
        if (ggrid[0][0] == 'U')
        {
            return 1;
        }

        if (ggrid[0][0] == 'C')
        {
            return 2;
        }
    }

    if ((ggrid[0][2] == ggrid[1][1]) && (ggrid[1][1] == ggrid[2][0]))
    {
        if (ggrid[0][2] == 'U')
        {
            return 1;
        }

        if (ggrid[0][2] == 'C')
        {
            return 2;
        }
    }

    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!(ggrid[i][j] == '?'))
            {
                counter++;
            }
            if (counter == 9)
            {
                return 3;
            }
        }
    }
    return 0;
}

// No Parameters
// No Return Value
// Prompts User for input, checks if the input is valid and marks the game board with 'U' if the input is valid
void TicTacToe::PlayByUser()
{
    input1 = 0;
    input2 = 0;
    printf("\nWhich cell would you like to mark (row and column)? ");
    cin >> input1 >> input2;
    while (cin.fail() || (input1 >= 3) || (input1 <= -1) || (input2 >= 3) || (input2 <= -1) || !(ggrid[input1][input2] == '?')) //cin.fail() checks to see if the value in the cin
    {
        if (cin.fail())
        {
            cin.clear();           //This corrects the stream.
            cin.ignore(256, '\n'); //This skips the left over stream data.

            printf("Invalid Input!\n");
            printf("\nWhich cell would you like to mark (row and column)? ");
            cin >> input1 >> input2;
        }

        else if ((input1 >= 3) || (input1 <= -1) || (input2 >= 3) || (input2 <= -1))
        {
            printf("Invalid cell position! Please try again...\n");
            printf("\nWhich cell would you like to mark (row and column)? ");
            cin >> input1 >> input2;
        }
        else if (ggrid[input1][input2] != '?')
        {
            printf("The cell has been marked already! Please try again...\n");
            printf("\nWhich cell would you like to mark (row and column)? ");
            cin >> input1 >> input2;
        }
    }

    ggrid[input1][input2] = 'U';
}

// No Parameters
// No Return Value
// Prints Game Board
void TicTacToe::PrintGameGrid()
{
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", ggrid[i][j]);
        }
        printf("\n");
    }
}