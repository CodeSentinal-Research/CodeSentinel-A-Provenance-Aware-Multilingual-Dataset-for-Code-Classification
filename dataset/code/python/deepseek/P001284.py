Here is the Python code for the problem:

def minDominoRotations(top, bottom):
    N = len(top)
    def check(x):
        top_rotations = bottom_rotations = 0
        for i in range(N):
            if top[i] != x and bottom[i] != x:
                return -1
            elif top[i] != x:
                top_rotations += 1
            elif bottom[i] != x:
                bottom_rotations += 1
        return min(top_rotations, bottom_rotations)

    result = check(top[0])
    if result != -1 or top[0] == bottom[0]:
        return result
    else:
        result = check(bottom[0])
        if result != -1 or top[0] == bottom[0]:
            return result
    return -1


print(minDominoRotations([1,2,3,4,5],[1,2,3,4,5]))
print(minDominoRotations([1,1,1,1,1],[1,2,3,4,5]))
print(minDominoRotations([2,2,2,2,1],[1,1,2,2,2]))
print(minDominoRotations([1,2,3,4,5],[5,4,3,2,1]))

This code first checks if it is possible to rotate the first element of the array (either in the top row or the bottom row) to make all elements equal. If this is not possible, it checks if rotating the first element in the other row is possible. If it is, it returns the number of rotations. If not, it returns -1.

The time complexity of this code is O(n) as it only loops through the array once.