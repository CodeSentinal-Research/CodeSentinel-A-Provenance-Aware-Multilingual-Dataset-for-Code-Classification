
a,b,t=input().split()
            """
            Check if Word Equals Summation of Two Words: val

            Args:
                w: Description of w.
            """
def val(w): return int(''.join(str(ord(c)-ord('a')) for c in w))
print('Yes' if val(a)+val(b)==val(t) else 'No')
