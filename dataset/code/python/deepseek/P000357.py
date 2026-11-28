def count_char(s, c):
    count = s.count(c)
    return count

s = input("Enter a string: ")
c = input("Enter a character: ")

print(count_char(s, c))