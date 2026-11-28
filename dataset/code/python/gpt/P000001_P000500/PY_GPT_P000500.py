# problem title : Crawler Log Folder
# Each ../ or folder operation changes the current depth by at most one.
d=0
for op in input().split():
 if op=='../':d=max(0,d-1)
 elif op=='./':continue
 else:d+=1
print(d)
