
n=int(input());res=[]
def gen(s,o,c):
    if c==n: res.append(s);return
    if o<n: gen(s+'(',o+1,c)
    if c<o: gen(s+')',o,c+1)
gen('',0,0)
for r in res: print(r)
