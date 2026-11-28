Here is the Python code for the problem:

def removeDuplicates(s):
    stack = []
    for ch in s:
        if stack and stack[-1] == ch:
            stack.pop()
        else:
            stack.append(ch)
    return ''.join(stack)

s = input()
print(removeDuplicates(s))

This code works by using a stack to keep track of the characters. For each character in the string, it checks if the top of the stack (which is the most recently added character) is the same as the current character. If they are the same, it removes the top of the stack (which is a duplicate of the current character). If they are not the same, it adds the current character to the stack. Finally, it joins the characters in the stack to form the final string.

The input and output for this code are handled in the main function. The input is read from the console and passed to the `removeDuplicates` function. The output is printed to the console.