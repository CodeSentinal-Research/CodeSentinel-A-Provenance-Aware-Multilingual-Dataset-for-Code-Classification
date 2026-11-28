# problem title : Basic Calculator II
# Process multiplication and division immediately, leaving addition/subtraction for the final sum.
s=input().replace(' ',''); nums=[]; num=0; op='+'
for i,ch in enumerate(s+'+'):
    if ch.isdigit(): num=num*10+int(ch)
    else:
        if op=='+': nums.append(num)
        elif op=='-': nums.append(-num)
        elif op=='*': nums[-1]*=num
        else: nums[-1]=int(nums[-1]/num)
        op=ch; num=0
print(sum(nums))
