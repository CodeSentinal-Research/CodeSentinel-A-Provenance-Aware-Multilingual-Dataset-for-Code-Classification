Sure, here is the Python code for the problem:

def generateParenthesis(n):
    def backtrack(s='', left=0, right=0):
        if len(s) == 2 * n:
            result.append(s)
            return
        if left < n:
            backtrack(s+'(', left+1, right)
        if right < left:
            backtrack(s+')', left, right+1)

    result = []
    backtrack()
    return result


n = 3
print(generateParenthesis(n))
In this code, we use the backtracking algorithm to generate all the combinations of parentheses. The function `generateParenthesis(n)` is calling `backtrack()` which in turn calls two additional functions, `backtrack(s='', left=0, right=0)`. The `backtrack()` function recursively tries to add parentheses to the current string `s`. If the length of `s` is 2 * `n`, it means we have generated a valid parentheses string, so we append it to the result list. If there are still parentheses left to add (`left < n`), we add a left parenthesis. If there are more parentheses left than the ones already added (`right < left`), we add a right parenthesis.