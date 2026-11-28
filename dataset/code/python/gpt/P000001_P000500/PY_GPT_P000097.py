# problem title : Check Duck Number
# A duck number contains zero after its first digit.
s = input().strip()
print("Duck" if '0' in s[1:] else "Not Duck")
