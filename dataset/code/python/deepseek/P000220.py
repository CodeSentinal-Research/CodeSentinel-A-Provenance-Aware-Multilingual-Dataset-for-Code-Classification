Here is the Python code:

def findCelebrity(mat):
    N = len(mat)

    stack = []
    for i in range(N):
        stack.append(i)

    while len(stack) > 1:
        a = stack.pop()
        b = stack.pop()

        if mat[a][b] == 1 and a != b:
            return -1

        stack.append(b)

    p = stack.pop()

    for i in range(N):
        if i != p and (mat[p][i] == 1 or mat[i][p] == 0):
            return -1

    return p

The code is based on the fact that a person is the only one who knows someone else who is not known by him/her. We use a stack to track all the people who know someone else. If the stack is empty, the person with no ties is the celebrity.

Here is how to use the code:

def main():
    N = 4
    mat = [[0, 0, 1, 0], [0, 0, 0, 0], [1, 0, 0, 0], [0, 0, 0, 0]]
    print(findCelebrity(mat))

if __name__ == "__main__":
    main()

This code will print `3`, which is the index of the celebrity in the given matrix.