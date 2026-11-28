Here is the python code for the problem:

def findClosestElements(arr, k, x):
    arr = sorted([(abs(i - x), i) for i in arr], key = lambda z: z[0])
    return [arr[i][1] for i in range(len(arr[:k]))]

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    k = int(input())
    x = int(input())
    result = findClosestElements(arr, k, x)
    print(result)

if __name__ == "__main__":
    main()

This code takes the input for n, arr, k, and x. It first sorts the array based on the difference between the element and x. It then returns the k elements with the smallest difference.