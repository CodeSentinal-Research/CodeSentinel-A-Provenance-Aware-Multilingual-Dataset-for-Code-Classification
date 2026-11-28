
n=int(input());MOD=10**9+7
even=pow(5,(n+1)//2,MOD);odd=pow(4,n//2,MOD)
print(even*odd%MOD)
