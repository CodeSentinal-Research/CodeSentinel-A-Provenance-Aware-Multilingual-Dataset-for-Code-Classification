def is_duck_number(s: str) -> bool:
    s = s.strip()
    if s.startswith('0'):
        return False
    return '0' in s

if __name__ == '__main__':
    s = input().strip()
    print("YES" if is_duck_number(s) else "NO")