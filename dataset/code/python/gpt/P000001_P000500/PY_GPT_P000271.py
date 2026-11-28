# problem title : Check if String is Rotation of Another
# Equal-length strings are rotations exactly when one appears inside S1+S1.
a=input(); b=input(); print("Yes" if len(a)==len(b) and b in a+a else "No")
