Here is the Python code with the main function and input handling:

def max_confusion(s, k):
    max_length = 0
    count = 1

    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            count += 1
        else:
            if count > k:
                max_length = max(max_length, count)
                count = 1
            else:
                max_length = max(max_length, count, s.count(s[i-1]))
            count = 1

    max_length = max(max_length, count)

    return max_length


s = input()
k = int(input())

print(max_confusion(s, k))

In this code, we are iterating through the string, and whenever we find a pair of identical characters, we increase a count. If the count exceeds K, we update the max_length and reset the count. In the end, we update max_length with the final count if it is greater than K.