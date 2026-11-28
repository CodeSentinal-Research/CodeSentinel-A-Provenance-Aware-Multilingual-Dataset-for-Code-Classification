
n=int(input());a=list(map(int,input().split()))

class Trie:
    def __init__(self): self.ch=[None,None]
def insert(root,num):
    node=root
    for i in range(31,-1,-1):
        b=(num>>i)&1
        if not node.ch[b]: node.ch[b]=Trie()
        node=node.ch[b]
def query(root,num):
    node=root;xor=0
    for i in range(31,-1,-1):
        b=(num>>i)&1
        want=1-b
        if node.ch[want]: xor|=(1<<i);node=node.ch[want]
        elif node.ch[b]: node=node.ch[b]
        else: break
    return xor
root=Trie()
for v in a: insert(root,v)
print(max(query(root,v) for v in a))
