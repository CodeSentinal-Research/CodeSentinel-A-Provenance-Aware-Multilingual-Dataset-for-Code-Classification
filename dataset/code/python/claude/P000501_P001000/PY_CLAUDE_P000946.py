
state=input().strip()
def can_win(s):
    for i in range(len(s)-1):
        if s[i]==s[i+1]=='+':
            nxt=s[:i]+'--'+s[i+2:]
            if not can_win(nxt): return True
    return False
print('true' if can_win(state) else 'false')
