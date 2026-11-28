
s,t=input().split()
diff=0
for c in s+t: diff^=ord(c)

print(chr(diff) if diff else '')
