word = input().strip()
if word.isupper() or word.islower() or (word[0].isupper() and word[1:].islower()):
    print("Yes")
else:
    print("No")
