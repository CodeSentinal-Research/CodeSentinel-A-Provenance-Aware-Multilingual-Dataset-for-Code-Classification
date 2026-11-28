n = int(input())
res = []
def backtrack(curr, open_cnt, close_cnt):
    if len(curr) == 2 * n:
        res.append("".join(curr))
        return
    if open_cnt < n:
        curr.append('(')
        backtrack(curr, open_cnt + 1, close_cnt)
        curr.pop()
    if close_cnt < open_cnt:
        curr.append(')')
        backtrack(curr, open_cnt, close_cnt + 1)
        curr.pop()
backtrack([], 0, 0)
for p in res:
    print(p)
