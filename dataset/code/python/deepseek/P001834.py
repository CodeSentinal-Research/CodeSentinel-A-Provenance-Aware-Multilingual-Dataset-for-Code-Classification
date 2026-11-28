Here is the python code:

def solve(N, bst):
    bst.sort()
    for i in range(N - 1):
        if bst[i] == bst[i + 1] - 1:
            return 'YES'
    return 'NO'

def main():
    N = int(input().strip())
    bst = [int(input().strip()) for _ in range(N)]
    print(solve(N, bst))

if __name__ == "__main__":
    main()

This code first reads the number of elements N. Then it reads N integers. The integers are sorted in ascending order and stored in the list `bst`. The `solve` function is then called with `bst` and `N` as arguments. This function sorts the list `bst` and iterates over it. If it finds two consecutive elements in the list that are one element apart, it returns 'YES'. If it doesn't find such a pair, it returns 'NO'.

The `main` function is the entry point of the program. It first reads the number of elements N, then reads N integers and prints the result of the `solve` function.