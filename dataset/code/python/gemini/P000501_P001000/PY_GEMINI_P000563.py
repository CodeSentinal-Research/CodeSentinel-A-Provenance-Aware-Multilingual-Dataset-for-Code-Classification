import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        begin_word = tokens[0]
        end_word = tokens[1]
        n = int(tokens[2])
        word_list = set(tokens[3:3+n])
        if end_word not in word_list:
            print(0)
            return
        q = deque([(begin_word, 1)])
        visited = {begin_word}
        while q:
            word, length = q.popleft()
            if word == end_word:
                print(length)
                return
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    nxt = word[:i] + c + word[i+1:]
                    if nxt in word_list and nxt not in visited:
                        visited.add(nxt)
                        q.append((nxt, length + 1))
        print(0)
if __name__ == '__main__':
    main()