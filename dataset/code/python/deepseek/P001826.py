Here is the Python code for the problem:

def check_same_keys(N1, trees1, N2, trees2):
    set1 = set()
    set2 = set()

    for _ in range(N1):
        set1.add(int(input()))

    for _ in range(N2):
        set2.add(int(input()))

    return 'YES' if set1 == set2 else 'NO'


def main():
    N1 = int(input())
    trees1 = [int(input()) for _ in range(N1)]
    N2 = int(input())
    trees2 = [int(input()) for _ in range(N2)]

    print(check_same_keys(N1, trees1, N2, trees2))


if __name__ == "__main__":
    main()

This code first reads the number of keys in the first BST and the keys themselves. It then reads the number of keys in the second BST and the keys themselves. These numbers and keys are then passed to the `check_same_keys` function which returns 'YES' if the two sets of keys are the same and 'NO' otherwise.