
word,abbr=input().split()
i=j=0
while i<len(word) and j<len(abbr):
    if abbr[j].isdigit():
        if abbr[j]=='0': print('No');exit()
        num=0
        while j<len(abbr) and abbr[j].isdigit(): num=num*10+int(abbr[j]);j+=1
        i+=num
    else:
        if word[i]!=abbr[j]: print('No');exit()
        i+=1;j+=1
print('Yes' if i==len(word) and j==len(abbr) else 'No')
