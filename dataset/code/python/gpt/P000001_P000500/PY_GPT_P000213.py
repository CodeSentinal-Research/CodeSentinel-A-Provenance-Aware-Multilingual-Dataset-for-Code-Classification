# problem title : Third Maximum Number
# Use a set so repeated values do not count as separate maximums.
n=int(input()); a=list(map(int,input().split())); u=sorted(set(a),reverse=True); print(u[2] if len(u)>=3 else u[0])
