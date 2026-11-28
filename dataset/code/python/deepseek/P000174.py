Here is the Python code:

def find_min_diff():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    
    arr.sort()
    
    min_diff = float('inf')
    
    for i in range(1, n):
        diff = abs(arr[i] - arr[i-1])
        min_diff = min(min_diff, diff)
    
    return min_diff

if __name__ == "__main__":
    print(find_min_diff())

This program first reads the number of elements in the array and the array itself. Then it sorts the array in ascending order. After that, it iterates through the sorted array and calculates the absolute difference between each pair of adjacent elements. It keeps track of the minimum difference found so far and finally returns the minimum difference.