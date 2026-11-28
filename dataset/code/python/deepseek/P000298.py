def longestValidParentheses(s):
    stack = [-1]  
    max_length = 0  

    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i)  
        else:
            stack.pop()  
            if len(stack) == 0:
                stack.append(i)  
            else:
                max_length = max(max_length, i - stack[-1])  

    return max_length

s = input("Enter a string: ")
print("Length of the longest valid parentheses is: ", longestValidParentheses(s))

This Python code uses a stack to track the indices of the parentheses. It pushes the index of the current opening parenthesis to the stack when a new opening parenthesis is encountered. Then it pops the index from the stack when a closing parenthesis is encountered. If the stack is empty, it means that the current closing parenthesis is a part of the longest valid parentheses substring, so it updates the max length. In the end, it returns the max length.