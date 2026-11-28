import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    stickers = []
    for _ in range(n):
        stickers.append(input_data[idx]); idx += 1
        
    target = input_data[idx]; idx += 1
    target_counts = Counter(target)
    
    memo = {}
    
    def dfs(target_tuple):
        if target_tuple in memo:
            return memo[target_tuple]
        if not target_tuple:
            return 0
            
        min_stickers = float('inf')
        for sticker in stickers:
            sticker_counts = Counter(sticker)
            new_target = dict(target_tuple)
            for char, cnt in sticker_counts.items():
                if char in new_target:
                    new_target[char] = max(0, new_target[char] - cnt)
            new_target_tuple = tuple(sorted((k, v) for k, v in new_target.items() if v > 0))
            if len(new_target_tuple) < len(target_tuple):
                res = dfs(new_target_tuple)
                if res != -1:
                    min_stickers = min(min_stickers, 1 + res)
                    
        memo[target_tuple] = min_stickers if min_stickers != float('inf') else -1
        return memo[target_tuple]
        
    print(dfs(tuple(sorted(target_counts.items()))))

if __name__ == "__main__":
    solve()

