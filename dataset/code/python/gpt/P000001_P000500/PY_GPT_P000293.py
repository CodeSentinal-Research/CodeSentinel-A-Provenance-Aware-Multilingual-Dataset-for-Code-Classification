# problem title : Encode and Decode Strings
# Length-prefix encoding makes delimiters safe even when strings contain separators.
import json
n=int(input()); items=[input() for _ in range(n)]; encoded=''.join(f"{len(x)}#{x}" for x in items)
print(encoded)
i=0; dec=[]
while i<len(encoded):
    j=encoded.index('#',i); k=int(encoded[i:j]); dec.append(encoded[j+1:j+1+k]); i=j+1+k
print(*dec,sep='\n')
