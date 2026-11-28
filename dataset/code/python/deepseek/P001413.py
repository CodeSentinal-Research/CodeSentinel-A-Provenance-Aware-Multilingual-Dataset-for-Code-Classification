Here is a Python solution for the problem:

def largest_unique_number():
    n = int(input())
    nums = list(map(int, input().split()))

    unique_nums = [num for num in nums if nums.count(num) == 1]

    if unique_nums:
        return max(unique_nums)
    else:
        return -1

if __name__ == "__main__":
    print(largest_unique_number())

In this code, we first read the number of integers and the integers themselves. We then create a list of unique integers that only appear once in the list. If there are any unique integers, we return the maximum one. If there are no unique integers, we return -1.