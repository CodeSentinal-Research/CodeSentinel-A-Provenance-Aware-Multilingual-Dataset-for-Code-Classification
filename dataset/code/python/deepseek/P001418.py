def countConsistentStrings(allowed, words):
    count = 0
    for word in words:
        if set(word).issubset(set(allowed)):
            count += 1
    return count

allowed = input().split()[1]
N = int(input().split()[0])

words = [input() for _ in range(N)]

print(countConsistentStrings(allowed, words))