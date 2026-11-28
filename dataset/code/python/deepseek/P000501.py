Here is the Python code for the problem:

def reverse_substrings(s: str) -> str:
    stack = []
    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i)
        elif s[i] == ')':
            j = stack.pop()
            s[j:i] = s[j:i][::-1]
    return s

The main function to handle the input:

def main():
    s = input().strip()
    print(reverse_substrings(s))

To run the program, save the code to a file (for example, `main.py`), and then run the file using the following command in your terminal:

python main.py

Please note that the code uses Python's built-in `input` function to handle the input string. This function reads a line from the standard input (usually your keyboard), converts it to a string, and returns it. The string is then passed to the `reverse_substrings` function.