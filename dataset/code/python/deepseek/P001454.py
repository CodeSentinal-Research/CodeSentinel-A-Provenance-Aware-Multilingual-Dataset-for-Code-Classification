Here is the Python code for the problem:

def count_distinct_substrings(s):
    distinct_substrings = set()
    n = len(s)
    for i in range(n):
        for j in range(i + 1, n + 1):
            distinct_substrings.add(s[i:j])
    return len(distinct_substrings)

def main():
    s = input()
    print(count_distinct_substrings(s))

if __name__ == "__main__":
    main()

This code first defines a function `count_distinct_substrings` that takes a string `s` as input and returns the number of distinct substrings. It uses a set `distinct_substrings` to store the distinct substrings, and then iterates over all substrings of `s`, adding them to `distinct_substrings`. Finally, it returns the size of `distinct_substrings`, which is the number of distinct substrings.

The `main` function reads a line from stdin, calls `count_distinct_substrings` with the input string, and prints the result.

Note that this solution is not efficient for large input strings because it uses a set to store all substrings, which takes O(n^2) time. A more efficient solution would use a string of fixed size, like a 26 characters array to keep track of substrings. However, this would require additional code to handle the boundaries of the string.