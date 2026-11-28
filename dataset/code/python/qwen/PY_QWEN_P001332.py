import sys

def solve():
    s = sys.stdin.readline().strip()
    n = len(s)
    
    left_parens = s.count('(')
    right_parens = s.count(')')
    
    min_removals = 0
    balance = 0
    for char in s:
        if char == '(':
            balance += 1
        elif char == ')':
            balance -= 1
        if balance < 0:
            min_removals += 1
            balance = 0
    min_removals += balance
    
    results = set()
    
    def backtrack(index, left_count, right_count, l_rem, r_rem, current):
        if index == n:
            if l_rem == 0 and r_rem == 0:
                results.add(current)
            return
            
        char = s[index]
        if char == '(':
            if l_rem > 0:
                backtrack(index + 1, left_count, right_count, l_rem - 1, r_rem, current)
            backtrack(index + 1, left_count + 1, right_count, l_rem, r_rem, current + '(')
        elif char == ')':
            if r_rem > 0:
                backtrack(index + 1, left_count, right_count, l_rem, r_rem - 1, current)
            if left_count > right_count:
                backtrack(index + 1, left_count, right_count + 1, l_rem, r_rem, current + ')')
        else:
            backtrack(index + 1, left_count, right_count, l_rem, r_rem, current + char)
            
    backtrack(0, 0, 0, min_removals, min_removals, "")
    for res in sorted(results):
        print(res)

if __name__ == "__main__":
    solve()

