Here is the C++ code to find the median of a row-wise sorted matrix of odd dimensions:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedian(vector<int> &arr) {
    int n = arr.size();
    if (n % 2 != 0)
        return (double)arr[n / 2];

    return (double)(arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> row(cols);
    double median = 0.0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            row[j] = matrix[i][j];
        }
        sort(row.begin(), row.end());
        median += findMedian(row);
    }

    median /= rows;

    cout << fixed << median << endl;

    return 0;
}
This code reads the dimensions of the matrix and then the matrix itself. It then sorts each row in the matrix and calculates the median of the sorted row. The medians are then averaged to find the overall median. The median is printed to the console.

Note: This code assumes that the input matrix is sorted row-wise. If the input matrix is not sorted row-wise, you need to sort each row first before calculating the median.