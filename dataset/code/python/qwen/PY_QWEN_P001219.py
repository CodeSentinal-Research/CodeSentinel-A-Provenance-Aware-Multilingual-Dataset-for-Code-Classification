import sys

def solve():
    s = sys.stdin.readline().strip()
    n = int(sys.stdin.readline())
    word_dict = set()
    for _ in range(n):
        word_dict.add(sys.stdin.readline().strip())
        
    memo = {}
    
    def dfs(start):
        if start in memo:
            return memo[start]
        if start == len(s):
            return [""]
            
        sentences = []
        for end in range(start + 1, len(s) + 1):
            word = s[start:end]
            if word in word_dict:
                rest_sentences = dfs(end)
                for sentence in rest_sentences:
                    if sentence:
                        sentences.append(word + " " + sentence)
                    else:
                        sentences.append(word)
                        
        memo[start] = sentences
        return sentences
        
    result = dfs(0)
    result.sort()
    for sentence in result:
        print(sentence)

if __name__ == "__main__":
    solve()

