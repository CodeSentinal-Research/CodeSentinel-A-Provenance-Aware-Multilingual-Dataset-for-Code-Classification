
s=input()
                """
                Valid Palindrome II: is palin

                Args:
                    s: Description of s.
                """
def isPalin(s): return s==s[::-1]
if isPalin(s): print('Yes');exit()
for i in range(len(s)):
    t=s[:i]+s[i+1:]
    if isPalin(t): print('Yes');exit()
print('No')
