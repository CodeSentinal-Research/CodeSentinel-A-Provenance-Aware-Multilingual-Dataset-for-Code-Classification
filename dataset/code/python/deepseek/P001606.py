Here is the Python code for the problem:

def countSubarrays(arr, n):
    count = 0
 
    prefix = 0
    suffix = 0
 
    zeros = 0
 
    for i in range(n):
 
        if arr[i] == 0:
            prefix += 1
            zeros += 1
 
        elif arr[i] == 1:
            suffix += 1
 
        if arr[i] == 0 and arr[i-1] == 1:
            count += (zeros + 1)
 
    return count
 
def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(countSubarrays(arr, n))
 
if __name__ == "__main__":
    main()

In this code, we are traversing the given array and maintaining two counts, prefix and suffix, for the number of 0s and 1s so far in the array. When we see a 0, we increment prefix and zeros count, when we see a 1, we increment suffix count. If we see a 0 and the previous element is 1, we increment count by the sum of prefix and zeros count (because of this condition, there could be subarrays ending in 1 and 0, which is not counted)