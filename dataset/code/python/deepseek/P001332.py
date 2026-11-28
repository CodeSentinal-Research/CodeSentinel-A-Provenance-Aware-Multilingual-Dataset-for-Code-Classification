Here is the Python code:

def restore_valid_parentheses(s):
    count = s.count('(') - s.count(')')
    
    def dfs(s, count, start):
        if not s:
            if count == 0:
                yield ''
        else:
            for i in range(start, len(s)):
                if s[i] == '(':
                    count += 1
                    yield from dfs(s[0:i] + s[i+1:], count, i+1)
                elif s[i] == ')' and count == 1:
                    count -= 1
                    yield from dfs(s[0:i] + s[i+1:], count, i+1)
    for r in dfs(s, count, 0):
        print(r)

def main():
    s = input()
    restore_valid_parentheses(s)

main()

This code works by first counting the number of parentheses in the string and then recursively generating all valid strings by removing one parenthesis at a time. The `dfs` function is a generator function that yields all valid strings by removing one parenthesis at a time.