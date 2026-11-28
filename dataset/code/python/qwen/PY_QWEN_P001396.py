import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    answers = list(map(int, input_data[1:1+n]))
    
    counter = Counter(answers)
    min_rabbits = 0
    
    for answer, count in counter.items():
        group_size = answer + 1
        num_groups = (count + group_size - 1) // group_size
        min_rabbits += num_groups * group_size
        
    print(min_rabbits)

solve()

