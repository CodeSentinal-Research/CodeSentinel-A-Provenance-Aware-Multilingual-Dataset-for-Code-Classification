Here is a Python solution using a breadth-first search (BFS) approach. The main idea is to use a queue to store all possible combinations of parentheses which can be removed, and then use this queue to generate all valid combinations.

from collections import deque

def removeInvalidParentheses(self, s):
    def add(s):
        return {s[i] + s[i+1:] for i in range(len(s)) if s[i] == '(' or s[i] == ')'}

    found = {s}
    expand = {s}

    while expand:
        found |= add(expand)
        expand = {f for x in expand for f in add(x)}

    return found

To handle input, you can use a command line or console input. Here's an example of how you could do it:

def main():
    s = input("Enter a string: ")
    print(removeInvalidParentheses(s))

if __name__ == "__main__":
    main()

This program will prompt you to enter a string. After you input a string, it will print all the possible valid strings by removing the minimum number of invalid parentheses.