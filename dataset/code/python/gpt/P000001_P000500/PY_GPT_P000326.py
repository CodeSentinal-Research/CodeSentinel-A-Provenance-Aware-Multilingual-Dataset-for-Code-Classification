# problem title : Number of Segments in a String
# A segment starts after whitespace when the previous character was whitespace.
s=input(); print(sum(ch!=' ' and (i==0 or s[i-1]==' ') for i,ch in enumerate(s)))
