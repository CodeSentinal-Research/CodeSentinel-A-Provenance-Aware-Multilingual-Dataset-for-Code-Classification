# problem title : Search Longest String
# max by string length returns the first longest string index on ties.
n=int(input());a=[input() for _ in range(n)];print(max(range(n),key=lambda i:len(a[i])))
