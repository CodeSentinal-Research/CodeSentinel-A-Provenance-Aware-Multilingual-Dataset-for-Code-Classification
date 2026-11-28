
w=input().strip()
ok=w==w.upper() or w==w.lower() or (w[0].isupper() and w[1:]==w[1:].lower())
print('Yes' if ok else 'No')
