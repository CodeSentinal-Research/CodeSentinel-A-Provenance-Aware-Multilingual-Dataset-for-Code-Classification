s = input().strip()
zeros = s.count('0')
ones = len(s) - zeros
max_score = -1
curr_zeros = 0
curr_ones = ones
for i in range(len(s) - 1):
    if s[i] == '0':
        curr_zeros += 1
    else:
        curr_ones -= 1
    max_score = max(max_score, curr_zeros + curr_ones)
print(max_score)
