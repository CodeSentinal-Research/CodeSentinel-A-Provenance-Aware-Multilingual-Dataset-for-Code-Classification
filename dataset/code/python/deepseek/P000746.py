Here is the Python code:

def josephus(N, K):
    if N == 1:
        return 1
    else:
        return (josephus(N-1, K) + K-1) % N + 1

if __name__ == "__main__":
    N, K = map(int, input().split())
    print(josephus(N, K))

In this code, the function josephus(N, K) is defined which is the main function. It uses recursion to solve the Josephus Problem. 

The recursion works by calling itself with the arguments (N-1, K) and then adding K-1. This is because the person K-1 is removed from the circle, and the person (K-1+1) who was removed is now the next person who gets to remove a person.

The base case for the recursion is when there is only one person left in the circle. In this case, the function returns the first person.

The input handling is done in the main function, where N and K are read from the standard input. The input is expected to be two integers separated by a space.

The output is the position of the survivor.

Please note that this code assumes that the K-th person is eliminated first, starting with 1 as the first person. If the problem assumes the eliminating person is the first person, then the code would need to be adjusted.