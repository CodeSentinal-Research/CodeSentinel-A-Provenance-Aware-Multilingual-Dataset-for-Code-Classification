Here is the python code for the given problem:

def max_difference():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))

    for i in range(N-K+1):
        window = arr[i:i+K]
        print(max(window) - min(window))

if __name__ == "__main__":
    max_difference()
This code takes two inputs from the user, N and K. Then it reads N integers, one at a time, and calculates the difference between the first and last element of each window of size K.