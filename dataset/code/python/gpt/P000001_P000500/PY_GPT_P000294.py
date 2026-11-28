# problem title : Zigzag Conversion
# Simulate the down-and-up row movement used by zigzag conversion.
s=input(); r=int(input())
if r==1 or r>=len(s): print(s)
else:
    rows=['']*r; row=0; step=1
    for ch in s:
        rows[row]+=ch
        if row==0: step=1
        elif row==r-1: step=-1
        row+=step
    print(''.join(rows))
