Sure, here is the Python code for your problem:

def modular_inverse(A, M):
    if A < 0 or A >= M:
        return -1

    for x in range(1, M):
        if (A * x) % M == 1:
            return x

    return -1

A = int(input("Enter A: "))
M = int(input("Enter M: "))

print(modular_inverse(A, M))

This code first checks if A is within the range 1 to M-1. If A is not within this range, it returns -1. Otherwise, it tries to find the modular multiplicative inverse of A modulo M. If A is found to be the modular multiplicative inverse, it returns A. If A is not found, it returns -1.

Please note that the time complexity of this code is O(M), which is quite slow for large inputs. This code is designed to be simple and easy to understand. For large inputs, you might want to use a more efficient algorithm or use a library function if available.