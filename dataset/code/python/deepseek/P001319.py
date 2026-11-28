def findWords(board, words):
    def dfs(node, word):
        if node.refcount == 0:
            return word
        for i, char in enumerate(word):
            if char == '@':
                for n in node.neighbors[char[0]].values():
                    if n.refcount > 0:
                        yield from dfs(n, word[:(i + 1)])
        return
    class Trie:
        def __init__(self):
            self.root = {}
    root = Trie()
    for row in board:
        node = root
        for cell in row:
            node = node.root[cell] = node.root.get(cell, {})
        node['#'] = '#'
    res = set()
    for i, char in enumerate(words):
        if char in root:
            for node in dfs(root[char], ''):
                res.add(node)
    return sorted(list(res))

def main():
    board = [['o','a','a','n'],['e','t','a','e'],['i','h','k','r'],['i','f','l','v']]
    words = ['ohdfk','olaehf','khdf','hfkh']
    print(findWords(board, words))

if __name__ == '__main__':
    main()