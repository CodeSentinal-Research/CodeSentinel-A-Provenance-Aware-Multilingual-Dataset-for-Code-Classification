
n=int(input())
records=[input().strip() for _ in range(n)]
query=input().strip()
for r in records:
    fields=r.split()
    if len(fields)>0 and fields[0]==query:
        print(r);exit()
print('Vehicle Not Found')
