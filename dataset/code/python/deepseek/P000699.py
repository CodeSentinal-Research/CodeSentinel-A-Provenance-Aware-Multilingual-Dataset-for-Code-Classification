def reverse_array(nums):
    if len(nums) == 0:
        return []
    else:
        return [nums[-1]] + reverse_array(nums[:-1])

def main():
    nums = list(map(int, input().split()))[1:]
    print(reverse_array(nums))

if __name__ == "__main__":
    main()