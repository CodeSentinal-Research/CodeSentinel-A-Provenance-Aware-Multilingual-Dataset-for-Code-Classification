Here is the Python code for the given problem:

def prefix_sum(s):
    prefix_sum_array = [0] * (len(s) + 1)

    for i in range(1, len(s) + 1):
        prefix_sum_array[i] = prefix_sum_array[i - 1] + ord(s[i - 1]) - ord('a') + 1

    print(" ".join(map(str, prefix_sum_array)))


if __name__ == "__main__":
    s = input().strip()
    prefix_sum(s)

In this code, `ord` is a built-in Python function that gets the ASCII value of a character. We add 1 to the ASCII value of the character because the prefix sum is 1-indexed. The prefix sum array is 1-indexed as well, but we subtract 1 at the end because Python's indexing is 0-indexed.