# problem title : Student Attendance Record II
# DP state tracks consecutive late count and whether an absence has been used.
MOD=10**9+7;n=int(input());dp={(0,0):1}
for _ in range(n):
    nd={}
    for (a,l),v in dp.items():
        nd[(a,0)]=(nd.get((a,0),0)+v)%MOD
        if a==0:nd[(1,0)]=(nd.get((1,0),0)+v)%MOD
        if l<2:nd[(a,l+1)]=(nd.get((a,l+1),0)+v)%MOD
    dp=nd
print(sum(dp.values())%MOD)
