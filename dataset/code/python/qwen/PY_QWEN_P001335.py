import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    sticks = list(map(int, input_data[1:1+n]))
    
    total_len = sum(sticks)
    if total_len % 4 != 0:
        print("NO")
        return
        
    side_len = total_len // 4
    sticks.sort(reverse=True)
    sides = [0] * 4
    
    def backtrack(index):
        if index == n:
            return all(s == side_len for s in sides)
            
        for i in range(4):
            if sides[i] + sticks[index] <= side_len:
                sides[i] += sticks[index]
                if backtrack(index + 1):
                    return True
                sides[i] -= sticks[index]
            if sides[i] == 0:
                break
        return False
        
    print("YES" if backtrack(0) else "NO")

if __name__ == "__main__":
    solve()

