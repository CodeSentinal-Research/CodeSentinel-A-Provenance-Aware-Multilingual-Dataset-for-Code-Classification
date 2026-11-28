Here is the code for the problem:

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the size of the matrix: ";
    cin >> N;
    if (N <= 0 || N > 1000) {
        cout << "Invalid input" << endl;
        return 0;
    }

    int** A = new int*[N];
    for (int i = 0; i < N; i++) {
        A[i] = new int[N];
    }

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int primary_diagonal_sum = 0, secondary_diagonal_sum = 0;
    for (int i = 0; i < N; i++) {
        primary_diagonal_sum += A[i][i];
        secondary_diagonal_sum += A[i][N - i - 1];
    }

    cout << "The sum of the main diagonal: " << primary_diagonal_sum << endl;
    cout << "The sum of the secondary diagonal: " << secondary_diagonal_sum << endl;

    for (int i = 0; i < N; i++) {
        delete [] A[i];
    }
    delete [] A;

    return 0;
}
This program first takes the size of the matrix from the user. It then checks if the size is valid (between 1 and 1000). If not, it prints an error message and terminates.

Next, it allocates memory for the matrix A. Then, it takes the elements of the matrix from the user.

It then calculates the sum of the main diagonal and the secondary diagonal by summing up the elements at the positions `i`, `N-i-1` for `i` ranging from 0 to N-1 (where N is the size of the matrix).

Finally, it prints the sum of the main diagonal and the secondary diagonal.

It is important to note that the memory for the matrix A is dynamically allocated and deallocated using `delete[]` to avoid memory leaks.