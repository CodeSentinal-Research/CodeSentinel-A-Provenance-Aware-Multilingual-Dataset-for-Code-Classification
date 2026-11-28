
r=int(input())
row=[1]
for i in range(1,r+1): row.append(row[-1]*(r-i+1)//i)
print(*row)
