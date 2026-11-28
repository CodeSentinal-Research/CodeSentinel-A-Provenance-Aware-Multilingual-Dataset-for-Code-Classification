Here is the Python code that fulfills the requirements:

def removeKdigits(num, k):
    if len(num) == k:
        return '0'
    else:
        stack = []
        for digit in num:
            while k and stack and stack[-1] > digit:
                stack.pop()
                k -= 1
            stack.append(digit)
        while k:
            stack.pop()
            k -= 1
        return ''.join(stack).lstrip('0') or '0'

def main():
    num = input("Enter a non-negative integer: ")
    k = int(input("Enter the number of digits to remove: "))
    print("The smallest possible number after removing", k, "digits is: ", removeKdigits(num, k))

if __name__ == "__main__":
    main()
In this code, we are using a stack data structure to handle the removal of digits. The stack is used to keep track of the digits in the order they were entered. When we encounter a digit that is greater than the top of the stack (i.e., the number we want to remove), we pop from the stack. This process continues until we have removed k digits or the stack is empty. If the result is empty after k removals, we return '0'.

In the `main` function, we first input the number and the number of digits to remove, and then print the resulting number after removing the specified number of digits.

Please note that this code assumes that the input will be a valid non-negative integer and the number of digits to remove will be a valid integer.