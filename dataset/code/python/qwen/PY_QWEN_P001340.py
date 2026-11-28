import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    cookies = list(map(int, input_data[idx:idx+n]))
    
    cookies.sort(reverse=True)
    children = [0] * k
    
    def backtrack(index):
        if index == n:
            return max(children)
        min_unfairness = float('inf')
        for i in range(k):
            children[i] += cookies[index]
            unfairness = backtrack(index + 1)
            min_unfairness = min(min_unfairness, unfairness)
            children[i] -= cookies[index]
            if children[i] == 0:
                break
        return min_unfairness
        
    print(backtrack(0))

if __name__ == "__main__":
    solve()

