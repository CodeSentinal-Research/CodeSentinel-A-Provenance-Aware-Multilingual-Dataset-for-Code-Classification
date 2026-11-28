# problem title : Search Shortest String
# min by string length returns the first shortest string index on ties.
n=int(input());a=[input() for _ in range(n)];print(min(range(n),key=lambda i:len(a[i])))
