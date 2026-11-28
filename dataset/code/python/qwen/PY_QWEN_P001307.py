import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    street = input_data[idx]; idx += 1
    
    police = []
    thieves = []
    
    for i in range(n):
        if street[i] == 'P':
            police.append(i)
        else:
            thieves.append(i)
            
    p_idx = 0
    t_idx = 0
    caught = 0
    
    while p_idx < len(police) and t_idx < len(thieves):
        if abs(police[p_idx] - thieves[t_idx]) <= k:
            caught += 1
            p_idx += 1
            t_idx += 1
        elif police[p_idx] < thieves[t_idx]:
            p_idx += 1
        else:
            t_idx += 1
            
    print(caught)

if __name__ == "__main__":
    solve()

