#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle(numRows);

    for(int row = 0; row < numRows; row++){
        triangle[row].resize(row+1);
        triangle[row][0] = triangle[row][row] = 1;

        for(int col = 1; col < row; col++){
            triangle[row][col] = triangle[row-1][col-1] + triangle[row-1][col];
        }
    }

    return triangle;
}

int main() {
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    if(numRows < 1 || numRows > 30){
        cout << "Invalid input! Please enter a number between 1 and 30." << endl;
        return -1;
    }

    vector<vector<int>> triangle = generate(numRows);

    for(int row = 0; row < numRows; row++){
        for(int col = 0; col <= row; col++){
            cout << triangle[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
This C++ solution takes an integer input for numRows representing the number of rows to generate in Pascal's Triangle. It then generates the Pascal's Triangle up to numRows. The solution uses two nested loops to generate each row of the triangle. It first initializes a vector of vectors, and then populates each row of the triangle, following Pascal's Triangle rule. Finally, it prints out the triangle.