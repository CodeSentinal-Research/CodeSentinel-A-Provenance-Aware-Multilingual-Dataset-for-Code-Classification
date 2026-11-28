import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    parents = list(map(int, input_data[1:1+n]))
    
    # Check if it forms a complete binary tree structure
    # In a complete binary tree array representation, parent of i is (i-1)//2
    # Here input gives parent index for each node.
    # Root should have parent -1 or itself? Usually -1.
    # Let's assume standard array heap indexing: parent of i is (i-1)//2.
    # If the input parents match this, it's a complete binary heap structure.
    
    is_valid = True
    for i in range(n):
        expected_parent = (i - 1) // 2 if i > 0 else -1
        if parents[i] != expected_parent:
            # Note: Problem might imply arbitrary parent pointers forming a tree.
            # But "complete binary heap structure" implies specific shape.
            # If input is just parent indices, we check if it matches heap shape.
            pass 
            
    # Simpler interpretation: Just check if the tree described is a complete binary tree.
    # A tree is complete if its BFS traversal has no gaps.
    # Given parent array, we can build children lists and BFS.
    
    children = [[] for _ in range(n)]
    root = -1
    for i in range(n):
        p = parents[i]
        if p == -1:
            root = i
        else:
            if 0 <= p < n:
                children[p].append(i)
                
    if root == -1:
        print("NO")
        return
        
    # BFS to check completeness
    from collections import deque
    q = deque([root])
    encountered_none = False
    count = 0
    while q:
        node = q.popleft()
        count += 1
        for child in children[node]:
            if encountered_none:
                print("NO")
                return
            q.append(child)
        # Pad with None if less than 2 children? 
        # Standard completeness check: once a node with <2 children is found, all subsequent must be leaves.
        if len(children[node]) < 2:
            encountered_none = True
            
    if count == n:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    solve()

