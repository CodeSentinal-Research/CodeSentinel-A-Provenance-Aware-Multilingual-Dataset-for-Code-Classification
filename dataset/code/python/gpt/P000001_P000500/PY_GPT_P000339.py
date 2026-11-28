# problem title : Determine if String Halves Are Alike
# Compare the number of vowels in the two equal halves.
s=input();v=set('aeiouAEIOU');m=len(s)//2;print("Yes" if sum(x in v for x in s[:m])==sum(x in v for x in s[m:]) else "No")
