Here is the Python code:

def decodeString(s):
    stack = []
    i = 0
    while i < len(s):
        if s[i] == ']':
            temp = ''
            while stack[-1] != '[':
                temp = stack.pop() + temp
            stack.pop()
            k = ''
            while stack and stack[-1].isdigit():
                k = stack.pop() + k
            k = int(k) if k else 1
            temp = temp * k
            stack.append(temp)
        else:
            stack.append(s[i])
        i += 1
    return stack[-1]

def main():
    s = input("Enter an encoded string: ")
    print("Decoded String:", decodeString(s))

if __name__ == "__main__":
    main()

This Python code works by maintaining a stack of characters. It iterates over the input string `s`, pushing each character onto the stack. When it encounters a ']', it pops characters from the stack until it encounters a '[' and appends a repeated copy of the popped string to the stack. The number of repetitions is then popped off the stack and the popped string is repeated `k` times. The final decoded string is the last character of the stack.

The `main` function gets the input string from the user and calls the `decodeString` function with this input. The output of this function is printed to the console.