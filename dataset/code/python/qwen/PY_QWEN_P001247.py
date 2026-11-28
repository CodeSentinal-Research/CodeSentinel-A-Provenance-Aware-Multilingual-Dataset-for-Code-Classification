import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    a = list(map(int, input_data[idx:idx+n])); idx += n
    b = list(map(int, input_data[idx:idx+n])); idx += n
    
    a_sorted = sorted(a)
    b_sorted = sorted(b)
    
    # Map b values to indices in original b
    b_indices = sorted(range(n), key=lambda i: b[i])
    
    result = [0] * n
    a_ptr = 0
    b_ptr = 0
    unused_a = []
    
    for i in range(n):
        if a_sorted[a_ptr] > b[b_indices[b_ptr]]:
            result[b_indices[b_ptr]] = a_sorted[a_ptr]
            a_ptr += 1
            b_ptr += 1
        else:
            unused_a.append(a_sorted[a_ptr])
            a_ptr += 1
            
    # Fill remaining spots with unused_a
    for i in range(n):
        if result[b_indices[i]] == 0:
             # This logic is flawed for general case. 
             # Correct greedy: Use smallest A that beats B. If none, use smallest A.
             pass
             
    # Simpler approach:
    a_with_idx = sorted([(val, i) for i, val in enumerate(a)])
    b_with_idx = sorted([(val, i) for i, val in enumerate(b)])
    
    ans = [0] * n
    used = [False] * n
    
    a_ptr = 0
    for b_val, b_idx in b_with_idx:
        while a_ptr < n and a_with_idx[a_ptr][0] <= b_val:
            a_ptr += 1
        if a_ptr < n:
            ans[b_idx] = a_with_idx[a_ptr][0]
            used[a_with_idx[a_ptr][1]] = True
            a_ptr += 1
            
    # Fill remaining
    remaining_a = [a_with_idx[i][0] for i in range(n) if not used[a_with_idx[i][1]]]
    rem_ptr = 0
    for i in range(n):
        if ans[i] == 0:
            ans[i] = remaining_a[rem_ptr]
            rem_ptr += 1
            
    print(*ans)

if __name__ == "__main__":
    solve()

