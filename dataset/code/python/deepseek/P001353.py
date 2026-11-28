Here is a Python code for the problem:

def restore_array(num_str, k):
    nums = [0] * (k + 2)
    nums[0] = 0
    for i in range(1, k + 1):
        nums[i] = int(num_str[i - 1]) + nums[i - 1] * 10
    return nums

def main():
    num_str = input()
    k = int(input())
    nums = restore_array(num_str, k)
    cnt = 0
    for i in range(k):
        if nums[i] != nums[i + 1]:
            cnt += 1
    print(cnt)

if __name__ == "__main__":
    main()

This program takes the numeric string and the integer K as input, and then computes the numbers in the array. It then counts the number of ways to split the string into integers in the range [1, K], with no leading zeros.