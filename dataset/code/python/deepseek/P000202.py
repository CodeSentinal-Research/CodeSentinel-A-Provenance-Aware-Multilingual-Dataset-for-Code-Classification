def longestConsecutive():
    n = int(input())
    numbers = set(int(input()) for _ in range(n))
    longest = 0

    for num in numbers:
        if num - 1 not in numbers:
            curr = num
            curr_streak = 1

            while curr + 1 in numbers:
                curr += 1
                curr_streak += 1

            longest = max(longest, curr_streak)

    return longest

if __name__ == "__main__":
    print(longestConsecutive())