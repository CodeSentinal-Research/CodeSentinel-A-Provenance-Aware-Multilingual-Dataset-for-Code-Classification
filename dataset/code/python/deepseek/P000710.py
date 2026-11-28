def generate_permutations(nums, index=0):
    if index == len(nums):
        print(nums)
    for i in range(index, len(nums)):
        nums[index], nums[i] = nums[i], nums[index]
        generate_permutations(nums, index + 1)
        nums[index], nums[i] = nums[i], nums[index]

def main():
    nums = list(map(int, input("Enter array elements separated by space: ").strip().split()))
    generate_permutations(nums)

if __name__ == "__main__":
    main()