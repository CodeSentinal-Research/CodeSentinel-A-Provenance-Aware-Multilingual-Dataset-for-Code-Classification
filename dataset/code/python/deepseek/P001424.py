def solve():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))

    freq = {}
    for num in nums:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1

    freq_values = freq.values()

    if len(freq_values) == len(set(freq_values)):
        print('YES')
    else:
        print('NO')


if __name__ == '__main__':
    solve()
This Python code reads the input, creates a frequency dictionary (`freq`), and then checks if all frequencies are unique (by comparing the length of the set of frequencies (`len(set(freq_values))`) with the length of the frequency values (`len(freq_values)`)). If they are equal, it means all frequencies are unique, and it prints 'YES'. Otherwise, it prints 'NO'.