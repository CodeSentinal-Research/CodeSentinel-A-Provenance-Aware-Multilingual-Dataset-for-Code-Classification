Here is the Python code:

def longest_semi_repetitive_substring(input_str):
    max_len = 0
    curr_len = 1

    for i in range(1, len(input_str)):
        if input_str[i] == input_str[i-1]:
            curr_len += 1
        else:
            max_len = max(max_len, curr_len)
            curr_len = 1

    return max(max_len, curr_len)

def main():
    input_str = input()
    print(longest_semi_repetitive_substring(input_str))

if __name__ == "__main__":
    main()

This program reads the input string from the user, then calls the `longest_semi_repetitive_substring` function with the input string as an argument. The function iterates over the string and updates the current length (`curr_len`) whenever a pair of adjacent digits are equal. It also keeps track of the maximum length found so far (`max_len`). The function finally returns the maximum of `max_len` and `curr_len` as the longest substring containing at most one pair of adjacent equal digits.