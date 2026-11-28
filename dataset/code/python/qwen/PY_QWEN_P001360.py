import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    words = []
    for _ in range(n):
        words.append(input_data[idx]); idx += 1
        
    available = input_data[idx]; idx += 1
    scores = list(map(int, input_data[idx:idx+26]))
    
    max_score = 0
    
    def backtrack(index, current_score, char_counts):
        nonlocal max_score
        if index == n:
            max_score = max(max_score, current_score)
            return
            
        # Skip word
        backtrack(index + 1, current_score, char_counts)
        
        # Try to take word
        word = words[index]
        word_counts = {}
        valid = True
        for char in word:
            word_counts[char] = word_counts.get(char, 0) + 1
            if char_counts.get(char, 0) + word_counts[char] > available.count(char):
                valid = False
                break
                
        if valid:
            new_counts = char_counts.copy()
            word_score = 0
            for char, cnt in word_counts.items():
                new_counts[char] = new_counts.get(char, 0) + cnt
                word_score += scores[ord(char) - ord('a')] * cnt
            backtrack(index + 1, current_score + word_score, new_counts)
            
    backtrack(0, 0, {})
    print(max_score)

if __name__ == "__main__":
    solve()

