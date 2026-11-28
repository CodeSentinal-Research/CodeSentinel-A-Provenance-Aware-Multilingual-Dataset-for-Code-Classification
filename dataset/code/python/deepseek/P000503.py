def scoreOfParentheses(s: str) -> int:
    stack = []
    for c in s:
        if c == '(':
            stack.append(c)
        else: 
            if stack[-1] == '(': 
                stack.pop()
                if len(stack) == 0: 
                    stack.append(1)
                else: 
                    temp = 0
                    while stack[-1] != '(': 
                        temp += stack.pop()
                    stack.pop() 
                    stack.append(temp * 2) 
            else: 
                stack.append(2 * stack.pop()) 
    return sum(stack)

This Python code works by using a stack to keep track of the parentheses scores. It iterates over the input string, and when it encounters an opening bracket, it pushes it onto the stack. When it encounters a closing bracket, it checks the top of the stack to see if it's an opening bracket for a parentheses pair. If so, it pops the opening and closing brackets, and then pushes the score (which is twice the partial score) back onto the stack. If the closing bracket is for a partial pair, it just adds the score of the partial pair to the total score.