Here is the Python code for the problem:

def count_distinct_palindromic_substrings(s):
    distinct_substrings = set()
    for i in range(len(s)):
        for j in range(i + 1, len(s) + 1):
            substr = s[i:j]
            if substr == substr[::-1]:  
                distinct_substrings.add(substr)
    return len(distinct_substrings)

def main():
    s = input().strip()
    print(count_distinct_palindromic_substrings(s))

if __name__ == "__main__":
    main()

This code firstly defines a function `count_distinct_palindromic_substrings` which takes a string as input and returns the number of distinct palindromic substrings in the string. The main function takes the string as input, calls the `count_distinct_palindromic_substrings` function with this string, and then prints the result.