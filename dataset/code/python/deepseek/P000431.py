def count_occurrences():
    N = int(input().strip())
    target = int(input().strip())
    nums = list(map(int, input().strip().split()))
    count = 0
    for num in nums:
        if num == target:
            count += 1
    print(count)

if __name__ == "__main__":
    count_occurrences()