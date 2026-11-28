Here's the Python code for the problem:

def containsNearbyDuplicate(nums, k):
    num_dict = {}
    for i, num in enumerate(nums):
        if num in num_dict and i - num_dict[num] <= k:
            return True
        num_dict[num] = i
    return False

def main():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print('YES' if containsNearbyDuplicate(nums, k) else 'NO')

if __name__ == '__main__':
    main()

Explanation:
This code uses a dictionary to store the indices of the numbers in the input array. For each number in the array, it checks if the number is already in the dictionary and if the distance between the current index and the index stored in the dictionary for the number is less than or equal to K. If it finds such a pair, it returns True, otherwise it returns False.