Here is the Python code for the problem:

def stickers_to_spell_word():
    n = int(input().strip())
    stickers = [input().strip() for _ in range(n)]
    target = input().strip()

    def dfs(s, i):
        if i == len(s):
            return 0
        res = float('inf')
        for k in range(len(s)):
            if visited[k] or s[i] == s[k]:
                continue
            visited[k] = True
            res = min(res, 1 + dfs(s, i + 1))
            visited[k] = False
        return res

    min_sticker_count = float('inf')
    for k in range(len(stickers)):
        visited = [False] * len(stickers)
        min_sticker_count = min(min_sticker_count, dfs(stickers[k], 0))

    if min_sticker_count == float('inf'):
        print(-1)
    else:
        print(min_sticker_count)

if __name__ == '__main__':
    stickers_to_spell_word()

In the code above, we are using depth-first search (DFS) to solve the problem. We start from the first sticker and try to use it to form the target word. If it's possible, we keep using it to form the rest of the word and keep track of the minimum number of stickers used. If it's not possible, we skip it. After trying all stickers, we print the minimum number of stickers used.