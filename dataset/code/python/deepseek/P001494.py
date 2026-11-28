Here is a Python solution for the problem:

def find_permutation(s):
    I, D, N = s.count('I'), s.count('D'), len(s)
    prefix, suffix = [], []

    max_num, min_num = 1, N + 1
    for i in range(I):
        prefix.append(max_num)
        max_num += 1
    for i in range(D):
        suffix.append(min_num)
        min_num -= 1

    res = prefix + [x for x in range(min_num, max_num)] + suffix
    return res


def main():
    s = input().strip()
    res = find_permutation(s)
    print(res)


if __name__ == "__main__":
    main()

This Python code uses a simple approach to solve the problem. It first counts the number of 'I' and 'D' operations, and then constructs the prefix and suffix arrays to satisfy the increasing and decreasing constraints. Finally, it merges the prefix, middle, and suffix arrays to form the final permutation. The main function reads the input string, calls the `find_permutation` function, and prints the result.