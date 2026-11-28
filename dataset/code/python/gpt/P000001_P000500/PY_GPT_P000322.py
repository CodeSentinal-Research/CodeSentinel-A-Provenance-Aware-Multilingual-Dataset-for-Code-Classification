# problem title : Detect Capital
# Valid capitalization is all upper, all lower, or only the first letter upper.
w=input(); print("Yes" if w.isupper() or w.islower() or w.istitle() else "No")
