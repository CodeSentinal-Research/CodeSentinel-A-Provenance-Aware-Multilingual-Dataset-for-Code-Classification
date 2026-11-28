# problem title : Check Whether Character is Special Symbol
# A special symbol here is any printable character that is neither letter nor digit.
c = input().strip()[0]
print("Special Symbol" if not c.isalnum() else "Not Special Symbol")
