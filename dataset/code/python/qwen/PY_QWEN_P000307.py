s = input().strip()
def is_valid(s):
    count = 0
    for c in s:
        if c == '(': count += 1
        elif c == ')': count -= 1
        if count < 0: return False
    return count == 0

q = {s}
while True:
    valid = list(filter(is_valid, q))
    if valid:
        for v in sorted(set(valid)):
            print(v)
        break
    next_q = set()
    for item in q:
        for i in range(len(item)):
            if item[i] in '()':
                next_q.add(item[:i] + item[i+1:])
    q = next_q
