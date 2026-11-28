# problem title : Count and Say Sequence
# Build each term by counting consecutive digits from the previous term.
n=int(input()); term="1"
for _ in range(1,n):
    out=[]; i=0
    while i<len(term):
        j=i
        while j<len(term) and term[j]==term[i]: j+=1
        out.append(str(j-i)+term[i]); i=j
    term=''.join(out)
print(term)
