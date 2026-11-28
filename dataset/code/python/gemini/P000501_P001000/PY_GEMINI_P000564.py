import sys
from collections import defaultdict, deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        begin_word = tokens[0]
        end_word = tokens[1]
        n = int(tokens[2])
        word_list = set(tokens[3:3+n])
        if end_word not in word_list:
            return
        res = []
        layer = {begin_word: [[begin_word]]}
        while layer:
            new_layer = defaultdict(list)
            for word in layer:
                if word == end_word:
                    for path in layer[word]:
                        print(" ".join(path))
                    return
                for i in range(len(word)):
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        nxt = word[:i] + c + word[i+1:]
                        if nxt in word_list:
                            new_layer[nxt] += [p + [nxt] for p in layer[word]]
            word_list -= set(new_layer.keys())
            layer = new_layer
if __name__ == '__main__':
    main()