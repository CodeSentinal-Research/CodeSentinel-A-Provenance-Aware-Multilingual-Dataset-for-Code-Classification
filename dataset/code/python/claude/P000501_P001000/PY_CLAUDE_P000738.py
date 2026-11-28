
n=int(input())
count=[0]
def bt(i,used):
    if i>n: count[0]+=1;return
    for num in range(1,n+1):
        if num not in used and (i%num==0 or num%i==0):
            used.add(num);bt(i+1,used);used.remove(num)
bt(1,set())
print(count[0])
