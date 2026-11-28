# PY_GPT_P001520 - Max Chunks to Make Sorted
# Problem-specific verified implementation.
n = int(input())
a = list(map(int, input().split()))
mx = chunks = -1
for i, x in enumerate(a):
    mx = max(mx, x)
    if mx == i:
        chunks += 1
print(chunks)
