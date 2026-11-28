#include <iostream>
using namespace std;

int count = 0;
int N;
int board[14][14];

bool is_safe(int row, int col)
{
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (int i = 0; i < row && col < N; i++, col++)
        if (board[row - i][col] == 1)
            return false;

    for (int i = 0; i < row && row - i >= 0 && col - i >= 0; i++)
        if (board[row - i][col - i] == 1)
            return false;

    return true;
}

void solve_n_queens(int row)
{
    if (row == N)
    {
        count++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (is_safe(row, i))
        {
            board[row][i] = 1;
            solve_n_queens(row + 1);
            board[row][i] = 0;
        }
    }
}

int main()
{
    cout << "Enter the value of N: ";
    cin >> N;

    if (N < 1 || N > 14)
    {
        cout << "Invalid input! N should be between 1 and 14";
        return 0;
    }

    memset(board, 0, sizeof(board));
    solve_n_queens(0);
    cout << "Total distinct arrangements: " << count << endl;
    return 0;
}