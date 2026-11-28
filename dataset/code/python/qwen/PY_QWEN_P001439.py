import sys

MORSE = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    transformations = set()
    for _ in range(n):
        word = input_data[idx]; idx += 1
        morse = "".join(MORSE[ord(c) - ord('a')] for c in word)
        transformations.add(morse)
        
    print(len(transformations))

solve()

