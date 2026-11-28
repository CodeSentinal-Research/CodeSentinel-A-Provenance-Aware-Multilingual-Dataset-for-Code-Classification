# problem title : Maximum Score After Splitting a String
# For every split, score is zeros on the left plus ones on the right.
s=input(); ones=s.count('1'); left0=best=0
for i in range(len(s)-1):
    left0+=s[i]=='0'; ones-=s[i]=='1'; best=max(best,left0+ones)
print(best)
