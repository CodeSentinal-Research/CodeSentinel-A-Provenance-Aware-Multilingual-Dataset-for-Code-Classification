'''
Write a recursive function to generate all permutations of a string.
Input: "abc"
Output: "abc", "acb", "bac", "bca", "cab", "cba"
'''
n='abc'
def GenerateallPermutationOfStr(x):
    if len(x)==1:
        return [x]
    ans=[]
    for i in range(len(x)):
        ch=x[i]
        #print('ch:' ,ch)
        rest=x[:i]+x[i+1:]
        #print('rest',rest)


        for j in GenerateallPermutationOfStr(rest):
            ans.append(ch+j)
    return ans
print(GenerateallPermutationOfStr(n))

'''
i=0
ch=a
rest=bc

ch=b


'''
        
        
        
