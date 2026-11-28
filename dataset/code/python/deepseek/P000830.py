def minEatingSpeed(piles, h):
    def canEat(mid):
        return sum((p + mid - 1) // mid for p in piles) <= h

    left, right = 1, max(piles)
    while left < right:
        mid = (left + right) // 2
        if canEat(mid):
            right = mid
        else:
            left = mid + 1
    return left

def main():
    n = int(input().strip())
    piles = list(map(int, input().strip().split()))
    h = int(input().strip())
    print(minEatingSpeed(piles, h))

if __name__ == "__main__":
    main()
This Python code defines a function `minEatingSpeed` that uses binary search to find the minimum eating speed such that Koko can finish all the bananas in a given time. The binary search is done in the main function, where the user is prompted to input the number of piles, the piles themselves, and the target time for eating (hours). The function `canEat` is a helper function that checks whether Koko can finish all the bananas in a given time. The binary search loop is a modified binary search that continues until the left pointer is larger than the right pointer. The middle point of the current range is calculated, and if Koko can finish all the bananas in the current range, the right pointer is moved to the middle point. Otherwise, the left pointer is moved to the middle point plus one. The final result is returned from the main function.