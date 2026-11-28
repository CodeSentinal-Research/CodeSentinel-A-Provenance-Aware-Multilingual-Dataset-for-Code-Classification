
parts=input().split();s=parts[0];rows=int(parts[1])
if rows==1: print(s);exit()
arrs=[[] for _ in range(rows)];row=0;down=True
for c in s:
    arrs[row].append(c)
    if row==rows-1: down=False
    elif row==0: down=True
    row+=1 if down else -1
print(''.join(''.join(r) for r in arrs))
