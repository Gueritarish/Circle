#include <stdio.h>
#include <math.h>

#define RADIUS 20
#define POWER 2


double distance(double x1, double y1, double x2, double y2)
{
    double a = pow(fabs(x2 - x1), POWER);
    double b = pow(fabs(y2 - y1), POWER);
    return pow(a + b, 1.0 / POWER);
}

void display(int board[2 * RADIUS][2 * RADIUS])
{
    for (int i = 1; i < 2 * RADIUS; i++)
    {
        for (int j = 1; j < 2 * RADIUS; j++)
        {
            if (board[i][j] == 0)
                printf(". ");
            else
                printf("# ");
        }
        printf("\n");
    }
}

int dont_stay(int board[2 * RADIUS][2 * RADIUS], int i, int j)
{
    if (i == 0 || i == 2 * RADIUS - 1 || j == 0 || j == 2 * RADIUS - 1)
        return 0;
    if (i == 1 || j == 1)
        return 0;
    if (board[i + 1][j] == 0 || board[i][j + 1] == 0 || board[i - 1][j] == 0 || board[i][j - 1] == 0)
        return 0;
    if (board[i + 1][j + 1] == 0 || board[i - 1][j + 1] == 0 || board[i - 1][j - 1] == 0 || board[i + 1][j - 1] == 0)
        return 0;
    return 1;
}

void empty_circle(int board[2 * RADIUS][2 * RADIUS], int new_board[2 * RADIUS][2 * RADIUS])
{

    for (int i = 0; i < 2 * RADIUS; i++)
    {
        for (int j = 0; j < 2 * RADIUS; j++)
        {
            if (board[i][j] == 1 && !dont_stay(board, i, j))
                new_board[i][j] = 1;
            else
                new_board[i][j] = 0;
        }
    }
}

int main(int argc, char* argv[])
{

    int board[2 * RADIUS][2 * RADIUS] = { { 0 } };
    board[RADIUS][RADIUS] = 2;
    for (int i = 0; i < 2 * RADIUS; i++)
    {
        for (int j = 0; j < 2 * RADIUS; j++)
        {
            double dist = distance(j, i, RADIUS, RADIUS);
            if (dist < RADIUS)
                board[i][j] = 1;
        }
    }
    int new_board[2 * RADIUS][2 * RADIUS] = { { 0 } };
    empty_circle(board, new_board);
    display(new_board);
    
    return 0;
}