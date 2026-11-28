Here is the Python code:

def find_missing_number(nums):
    n = len(nums) + 1
    x1 = 1
    x2 = 2

    for i in range(1, n//2):
        x1 = x1 ^ nums[i]
        x2 = x2 ^ i

    for i in range(n//2, n):
        x1 = x1 ^ nums[i]
        x2 = x2 ^ i

    if x1 > x2:
        x1, x2 = x2, x1

    x1 = x1 ^ x2
    return x1

def main():
    nums = [i for i in range(1, 100000)]
    missing_number = find_missing_number(nums)
    print(missing_number)

if __name__ == "__main__":
    main()

This code finds the missing number using XOR in an array. The key idea is to XOR all the numbers in the array with their indices (1 to n), and then XOR the result with the numbers in the array itself (1 to n/2) and again with the indices. The missing number will be the result of the XOR of the final two XORs.