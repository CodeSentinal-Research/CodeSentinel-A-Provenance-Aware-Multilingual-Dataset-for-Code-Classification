# problem title : Check Whether Character is Digit
# Check the character against the decimal digit range.
c = input().strip()[0]
print("Digit" if '0' <= c <= '9' else "Not Digit")
