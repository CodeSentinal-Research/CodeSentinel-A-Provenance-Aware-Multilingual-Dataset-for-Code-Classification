# problem title : Repeated Substring Pattern
# If S is a repeated pattern, it appears inside (S+S) after removing the first and last character.
s=input(); print("Yes" if s in (s+s)[1:-1] else "No")
