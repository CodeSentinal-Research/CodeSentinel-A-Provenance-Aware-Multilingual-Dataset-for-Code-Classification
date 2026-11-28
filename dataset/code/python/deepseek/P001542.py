Here is the Python code for the problem:

def average_window():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))

    for i in range(N-K+1):
        window = arr[i:i+K]
        avg = sum(window) / K
        print(avg)

average_window()

In this code, we first read the first line which contains N and K. Then, we read the second line which contains N integers. The function then iterates through each window of size K starting from the first to the last element of the array. For each window, it calculates the average by summing all the elements in the window and dividing by the window size. Finally, it prints the average.