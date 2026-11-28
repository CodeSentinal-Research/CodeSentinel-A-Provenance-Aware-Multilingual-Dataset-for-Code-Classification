Here is the Python code for the problem:

def isWordExist(N, M, board, word):
    def search(i, j, k):
        if k == len(word):
            return True
        if i < 0 or j < 0 or i >= N or j >= M:
            return False
        if board[i][j] != word[k]:
            return False
        board[i][j] = '.'  
        if any([search(i + 1, j, k + 1), search(i - 1, j, k + 1), search(i, j + 1, k + 1), search(i, j - 1, k + 1)]):
            return True
        board[i][j] = word[k]  
        return False

    for i in range(N):
        for j in range(M):
            if search(i, j, 0):
                return True
    return False

if __name__ == '__main__':
    N = 3
    M = 3
    board = [['A','B','C'], ['D','E','F'], ['G','H','I']]
    word = 'ABEH'
    print(isWordExist(N, M, board, word))  

This code first defines the `isWordExist` function that takes in a 2D board matrix and a word to be searched. It then calls the helper function `search` which is a recursive function that tries to find the word in the board.

In the main function, it tests the `isWordExist` function with a sample input.