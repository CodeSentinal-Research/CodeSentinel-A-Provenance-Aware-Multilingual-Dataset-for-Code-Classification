import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    q = int(input_data[idx]); idx += 1
    nums = list(map(int, input_data[idx:idx+n])); idx += n
    
    distinct_set = set(nums)
    counter = Counter(nums)
    distinct_count = len(distinct_set)
    
    output = []
    for _ in range(q):
        index = int(input_data[idx]); idx += 1
        new_val = int(input_data[idx]); idx += 1
        
        old_val = nums[index]
        if old_val == new_val:
            output.append(distinct_count)
            continue
            
        # Update counter
        counter[old_val] -= 1
        if counter[old_val] == 0:
            distinct_count -= 1
            del counter[old_val]
            
        if new_val not in counter:
            distinct_count += 1
        counter[new_val] += 1
        
        nums[index] = new_val
        output.append(distinct_count)
        
    print("\n".join(map(str, output)))

solve()

