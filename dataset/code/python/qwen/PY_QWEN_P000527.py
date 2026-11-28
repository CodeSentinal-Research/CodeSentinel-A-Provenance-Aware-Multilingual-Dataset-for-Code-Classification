s = input().strip()
def parse(it):
    c = next(it)
    if c == 't': return True
    if c == 'f': return False
    if c == '!':
        next(it); next(it)
        res = not parse(it)
        next(it)
        return res
    if c in '&|':
        next(it)
        vals = []
        while True:
            nxt = next(it)
            if nxt == ')': break
            if nxt == ',': continue
            vals.append(parse(iter(nxt + "".join(iter(it, lambda: next(it, None), None)))))
            break
        return all(vals) if c == '&' else any(vals)
print("true" if parse(iter(s)) else "false")
