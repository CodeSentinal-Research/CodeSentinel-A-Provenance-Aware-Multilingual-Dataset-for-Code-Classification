import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    a = int(input_data[0])
    b = int(input_data[1])
    c = int(input_data[2])
    
    score = 0
    while a > 0 and b > 0:
        a -= 1
        b -= 1
        score += 1
    while a > 0 and c > 0:
        a -= 1
        c -= 1
        score += 1
    while b > 0 and c > 0:
        b -= 1
        c -= 1
        score += 1
        
    print(score)

if __name__ == "__main__":
    solve()

