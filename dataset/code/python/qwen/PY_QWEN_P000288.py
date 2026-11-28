s = input().strip()
def is_pal(l, r, skipped):
    while l < r:
        if s[l] != s[r]:
            if skipped: return False
            return is_pal(l+1, r, True) or is_pal(l, r-1, True)
        l += 1
        r -= 1
    return True
print("Yes" if is_pal(0, len(s)-1, False) else "No")
