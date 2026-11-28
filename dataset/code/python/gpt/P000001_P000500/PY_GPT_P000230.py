# problem title : Common Elements in All Rows of Matrix
# Intersect the set of values from every row to keep only common elements.
r,c=map(int,input().split()); rows=[list(map(int,input().split())) for _ in range(r)]; common=set(rows[0])
for row in rows[1:]: common &= set(row)
print(*sorted(common))
