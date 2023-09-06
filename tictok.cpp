#include <iostream>
#include <vector>

using namespace std;

int col_check(vector<vector<int>> &matrix)
{
    for (int i = 0; i < 3; i++)
    {
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
        {
            return matrix[0][i];
        }
    }
    return 0;
}

int row_check(vector<vector<int>> &matrix)
{
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
        {
            return matrix[i][0];
        }
    }
    return 0;
}

int diagonal_check(vector<vector<int>> &matrix)
{
    if ((matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) ||
        (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]))
    {
        return matrix[1][1];
    }
    return 0;
}

void printBoard(vector<vector<int>> &matrix)
{
    cout << "Current Board:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 0)
            {
                cout << " ";
            }
            else if (matrix[i][j] == 1)
            {
                cout << "X";
            }
            else
            {
                cout << "O";
            }

            if (j < 2)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2)
        {
            cout << "---------" << endl;
        }
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> matrix(3, vector<int>(3, 0));
    int player = 1;
    int moves = 0;

    while (true)
    {
        printBoard(matrix);

        int position;
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> position;

        if (position < 1 || position > 9)
        {
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            continue;
        }

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (matrix[row][col] != 0)
        {
            cout << "Invalid move. That position is already taken." << endl;
            continue;
        }

        matrix[row][col] = player;
        moves++;

        int winner = 0;
        if (moves >= 5)
        {
            winner = col_check(matrix);
            if (winner == 0)
            {
                winner = row_check(matrix);
            }
            if (winner == 0 && moves >= 5)
            {
                winner = diagonal_check(matrix);
            }
        }

        if (winner != 0)
        {
            printBoard(matrix);
            cout << "Player " << winner << " has won!" << endl;
            break;
        }

        if (moves == 9)
        {
            printBoard(matrix);
            cout << "It's a draw! No one wins." << endl;
            break;
        }
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
