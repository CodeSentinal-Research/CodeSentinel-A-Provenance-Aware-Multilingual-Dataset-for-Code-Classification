Sure, I will provide the Python code for this problem. Here's the complete code:

from collections import deque

def removeInvalidParentheses(s):
    queue = deque([s])
    visited = {s}
    while queue:
        curr = queue.popleft()
        if not isValid(curr):
            for i in range(len(curr)):
                if curr[i] in "()":
                    newStr = curr[:i] + curr[i+1:]
                    if newStr not in visited:
                        visited.add(newStr)
                        queue.append(newStr)
    return visited

def isValid(s):
    stack = []
    for ch in s:
        if ch == '(':
            stack.append(ch)
        elif ch == ')':
            if not stack or stack.pop() != '(':
                return False
    return not stack

This code uses Breadth-First Search (BFS) to find all possible valid parentheses strings from a given string. The `isValid` function checks whether a string is valid or not. The `removeInvalidParentheses` function uses this to find all valid strings from a given string. 

Main function:

def main():
    s = input("Enter a string: ")
    print(removeInvalidParentheses(s))

if __name__ == "__main__":
    main()

You can run this code in a Python environment and input a string. The code will then print out all valid strings that can be obtained by removing one parenthesis from the given string.