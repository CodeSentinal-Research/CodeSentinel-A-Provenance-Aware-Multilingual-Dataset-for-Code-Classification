def generateParenthesis(n):
    def backtrack(s='', left=0, right=0):
        if len(s) == 2 * n:
            ans.append(s)
            return
        if left < n:
            backtrack(s+'(', left+1, right)
        if right < left:
            backtrack(s+')', left, right+1)

    ans = []
    backtrack()
    return ans

n = int(input().strip())
result = generateParenthesis(n)
for result in sorted(result):
    print(result)