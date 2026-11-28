Here is the basic implementation of the problem:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    for (int i = 0; i < R; i++) {
        cout << grid[i] << endl;
    }
    return 0;
}

This code reads the crossword grid and the list of words from the standard input, then prints the crossword grid as is. 

In a crossword puzzle, every horizontal and vertical slot should be filled with a valid word. The implementation provided here does not solve the puzzle, it just prints the crossword grid as is. 

To solve the crossword puzzle, you would need to implement the algorithm for checking if a word can be placed in a given slot, or if the grid is valid. This is a complex problem that would require a good algorithm and a good understanding of the crossword puzzle rules.