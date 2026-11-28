Here is the Python code:

def find_common_prefix(N, A, B):
    common = [0] * N
    prefix = 0
    for i in range(N):
        if A[i] == B[i]:
            prefix += 1
            common[i] = prefix
    return common

def main():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    B = list(map(int, input().strip().split()))
    common = find_common_prefix(N, A, B)
    print(' '.join(map(str, common)))

if __name__ == "__main__":
    main()

This Python code first reads the number N and two permutations A and B from the input. It then finds and prints the common prefix array by calling the `find_common_prefix` function and passing in N, A, and B as arguments.