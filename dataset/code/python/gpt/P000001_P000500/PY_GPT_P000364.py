# problem title : Search Multiple Target Values
# A set makes each of many membership queries constant-time after one scan.
n=int(input());a=set(map(int,input().split()));q=int(input());
for _ in range(q):print("Found" if int(input()) in a else "Not Found")
