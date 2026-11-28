Here is the Python code for your problem:

def search_values(N, arr, Q):
    for i in range(Q):
        x = arr[i]
        if x in arr:
            print("Found")
        else:
            print("Not Found")

N = int(input().strip())
arr = list(map(int, input().strip().split()))
Q = int(input().strip())
search_values(N, arr, Q)

In this code, we first read the number N, the array of integers and the number Q. Then for each query value, we check if it exists in the array using the 'in' operator. If it exists, we print 'Found', otherwise, we print 'Not Found'.