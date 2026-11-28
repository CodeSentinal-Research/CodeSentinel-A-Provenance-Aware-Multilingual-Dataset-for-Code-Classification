Here's the Python code for the problem:

def recoverBinaryTree(s: str):
    children = [2*i+1 for i in range(int(len(s)/2))]
    parent = {i:[s[2*i+1]] for i in range(int(len(s)/2))}
    for i in range(len(s)//2):
        if s[2*i+2] != -1:
            parent[s[2*i+1]].append(s[2*i+2])
        else:
            children[s[2*i+1]] = s[2*i+2]
    for i in range(len(s)//2):
        if s[2*i+2] == -1:
            if len(parent[s[2*i+1]]) == 1:
                children[s[2*i+1]] = parent[s[2*i+1]][0]
                parent[s[2*i+1]].remove(children[s[2*i+1]])
            else:
                parent[s[2*i+1]].remove(s[2_i+2])
    return children[0]

def solve():
    N = int(input())
    s = input().split()
    for i in range(N):
        s[i] = int(s[i])
    root = recoverBinaryTree(s)
    print(root)

if __name__ == "__main__":
    solve()
This code first declares a function `recoverBinaryTree` that reconstructs the binary tree from the given string representation. The string representation is converted into a list of integers. A dictionary is then built where each key is a parent node and its value is a list of children nodes. The parent-child relationships are then restored.

The function `solve` reads the input, calls `recoverBinaryTree`, and prints the reconstructed tree.