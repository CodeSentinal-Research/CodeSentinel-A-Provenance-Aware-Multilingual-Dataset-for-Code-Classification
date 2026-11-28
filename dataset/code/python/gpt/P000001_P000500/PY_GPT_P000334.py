# problem title : Shortest Way to Form String
# Greedily consume the longest possible subsequence of source on each pass over target.
src=input(); target=input();
if not src: print(-1)
else:
    pos={}
    for i,ch in enumerate(src):pos.setdefault(ch,[]).append(i)
    import bisect
    count=1; cur=-1; i=0
    while i<len(target):
        arr=pos.get(target[i],[]); k=bisect.bisect_right(arr,cur)
        if k==len(arr): count+=1;cur=-1;k=bisect.bisect_right(arr,cur)
        if k==len(arr):count=-1;break
        cur=arr[k];i+=1
    print(count)
