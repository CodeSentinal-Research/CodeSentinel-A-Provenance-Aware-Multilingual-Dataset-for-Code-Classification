Here is the Python code:

def can_partition(s, k):
    count = [0]*26
    for c in s:
        count[ord(c) - ord('a')] += 1
    odd = 0
    for v in count:
        if v % 2 == 1:
            odd += 1
    return odd <= k

def main():
    s = input().strip()
    k = int(input().strip())
    print('YES' if can_partition(s, k) else 'NO')

if __name__ == '__main__':
    main()

In this code, the function `can_partition` counts the occurrence of each character in the string `s` and then checks if there are more than `k` characters that occur an odd number of times. If yes, then it means it's not possible to partition the string into `k` palindromes, so it returns `False`. Otherwise, it returns `True`.

The `main` function reads the string and the integer from the standard input, and then calls `can_partition` with these inputs. If the result is `True`, it prints `YES`, otherwise it prints `NO`.