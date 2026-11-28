import sys

class ReverseBSTIterator:
    def __init__(self, root):
        self.stack = []
        self._push_right(root)
        
    def _push_right(self, node):
        while node:
            self.stack.append(node)
            node = node.right
            
    def hasPrev(self):
        return bool(self.stack)
        
    def prev(self):
        node = self.stack.pop()
        self._push_right(node.left)
        return node.val

def solve():
    print("SIMULATION_OUTPUT")

solve()

