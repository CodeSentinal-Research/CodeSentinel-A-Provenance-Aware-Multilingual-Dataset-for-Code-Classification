def find_most_frequent(nums, key):
    counts = {}
    for num in nums:
        if num == key:
            if key in counts:
                counts[key] += 1
            else:
                counts[key] = 1
        elif num in counts:
            counts[num] += 1
        else:
            counts[num] = 1
    max_count = max(counts.values())
    for num, count in counts.items():
        if count == max_count:
            return num

N = int(input().strip())
nums = list(map(int, input().strip().split()))
key = int(input().strip())
print(find_most_frequent(nums, key))