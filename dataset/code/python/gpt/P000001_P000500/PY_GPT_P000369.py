# problem title : Search Empty String
# An empty line represents an empty string in line-oriented input.
n=int(input());a=[input() for _ in range(n)];print(next((i for i,x in enumerate(a) if x==''),-1))
