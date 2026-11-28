def threeSum(arr):
    arr.sort()
    triplets = []
    for i in range(len(arr)-2):
        if i > 0 and arr[i] == arr[i-1]:
            continue
        l, r = i+1, len(arr)-1
        while l < r:
            if arr[i] + arr[l] + arr[r] == 0:
                triplets.append([arr[i], arr[l], arr[r]])
                l += 1
                while arr[l] == arr[l-1] and l < r:
                    l += 1
                r -= 1
                while r > 0 and arr[r] == arr[r+1] and l < r:
                    r -= 1
            elif arr[i] + arr[l] + arr[r] < 0:
                l += 1
            else:
                r -= 1
    return triplets

def getInput():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    return n, arr

def main():
    n, arr = getInput()
    result = threeSum(arr)
    for triplet in result:
        print(triplet)

if __name__ == '__main__':
    main()