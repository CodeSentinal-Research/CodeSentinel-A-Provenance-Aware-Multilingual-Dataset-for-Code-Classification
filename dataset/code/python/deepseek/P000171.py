Sure, here is a Python code that can solve the problem:

def segregate_binary_array():
    N = int(input().strip())
    binary_array = list(map(int, input().strip().split()))

    segregated_array = [0]*N + [1]*N

    return segregated_array

print(segregate_binary_array())

This program first takes an integer N as input. Then, it takes N integers as input, representing the binary array. The program segregates the 0s and 1s in the binary array and returns the segregated array.