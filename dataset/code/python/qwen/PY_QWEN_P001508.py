import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    fruits = list(map(int, input_data[1:1+n]))
    
    basket = Counter()
    left = 0
    max_fruits = 0
    
    for right in range(n):
        basket[fruits[right]] += 1
        while len(basket) > 2:
            basket[fruits[left]] -= 1
            if basket[fruits[left]] == 0:
                del basket[fruits[left]]
            left += 1
        max_fruits = max(max_fruits, right - left + 1)
        
    print(max_fruits)

solve()

