def maxChunksToSorted(arr):
    n = len(arr)
    leftMax = [0] * n
    rightMax = [0] * n
    
    leftMax[0] = arr[0]
    rightMax[n-1] = arr[n-1]
    
    for i in range(1, n):
        leftMax[i] = max(leftMax[i-1], arr[i])
    
    for i in range(n-2, -1, -1):
        rightMax[i] = max(rightMax[i+1], arr[i])
        
    chunks = 0
    
    for i in range(n-1):
        if leftMax[i] <= rightMax[i+1]:
            chunks += 1
            
    return chunks+1

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    print(maxChunksToSorted(arr))

main()