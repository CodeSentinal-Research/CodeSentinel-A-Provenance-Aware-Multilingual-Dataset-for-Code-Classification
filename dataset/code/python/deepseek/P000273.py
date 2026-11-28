Here is the Python code that handles the problem:

def is_valid(s):
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    for char in s:
        if char in mapping.values():
            stack.append(char)
        elif not stack or mapping[char] != stack.pop():
            return 'Invalid'
    return 'Valid' if not stack else 'Invalid'

def main():
    s = input("Enter a string: ")
    print(is_valid(s))

if __name__ == "__main__":
    main()
This code uses a stack data structure to handle the parentheses. For each character in the input string, if the character is a start character of a pair of parentheses, it is pushed onto the stack. Otherwise, if the stack is not empty and the top element of the stack is the corresponding end character of the pair, the top element is popped. Otherwise, the input string is invalid. Finally, if the stack is not empty, the input string is invalid.