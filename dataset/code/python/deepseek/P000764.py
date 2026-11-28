Here is a Python solution that uses recursion to solve the problem. The solution works by first recursively splitting the string into characters. When a character is a digit, the function repeats the characters K times. The final solution is then returned by the main function.

def decodeAtIndex(s: str, K: int) -> str:
    def get_length(s):
        length = 0
        for c in s:
            if c.isalpha():
                length += 1
            else:
                length += int(c)
        return length

    length = get_length(s)
    mod = length  

    def decode(s, K):
        nonlocal mod
        for c in s:
            if c.isdigit():
                K *= int(c)
                K %= mod
            else:
                if K == 0:
                    return c
                K -= 1

    return decode(s, K)


def main():
    s = input("Enter the encoded string: ")
    K = int(input("Enter the index: "))
    print(decodeAtIndex(s, K))


if __name__ == "__main__":
    main()
In this code, the `decodeAtIndex` function is called in the main function. This function takes the encoded string `s` and the index `K` as input, and returns the `K-th` character of the decoded string. The `get_length` function calculates the length of the decoded string, and the `mod` variable is set to this length for the purpose of the modulus operation in the `decode` function.

Please note that this code will work for small input strings, but it will be slow for large input strings due to the recursion involved. If you need to handle large input strings, you might need to use a different approach, such as a stack or a queue to handle the recursion.