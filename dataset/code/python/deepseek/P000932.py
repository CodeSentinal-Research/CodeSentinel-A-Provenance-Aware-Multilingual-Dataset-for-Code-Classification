Here is a Python solution using nested for loops to compute the trace of a square matrix:

def trace_of_matrix(N, A):
    trace = 0
    for i in range(N):
        trace += A[i][i]
    return trace

N = int(input("Enter the size of the matrix: "))
A = []
for i in range(N):
    row = list(map(int, input("Enter the elements of row {}: ".format(i + 1)).split()))
    A.append(row)

print("The trace of the matrix is: ", trace_of_matrix(N, A))

In this code, the user is asked to enter the size of the matrix and the elements of the matrix. The `trace_of_matrix` function calculates the trace by summing up the main diagonal elements of the matrix. The user is then asked to input the size and the matrix elements. The code then calls the function with the input and prints the result.