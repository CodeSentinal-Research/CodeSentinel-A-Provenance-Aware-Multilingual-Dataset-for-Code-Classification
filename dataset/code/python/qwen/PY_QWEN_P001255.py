import sys

def solve():
    s = sys.stdin.readline().strip()
    balance = 0
    insertions = 0
    
    for char in s:
        if char == '(':
            balance += 1
        else:
            balance -= 1
        if balance == -1:
            insertions += 1
            balance = 1
            
    insertions += balance
    print(insertions)

if __name__ == "__main__":
    solve()

