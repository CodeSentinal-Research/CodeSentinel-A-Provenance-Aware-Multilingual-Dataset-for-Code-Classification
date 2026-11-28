# problem title : Find the Smallest Positive Missing Number
# Store positive values, then scan upward for the first missing integer.
n = int(input()); a = set(map(int, input().split()))
answer = 1
while answer in a: answer += 1
print(answer)
