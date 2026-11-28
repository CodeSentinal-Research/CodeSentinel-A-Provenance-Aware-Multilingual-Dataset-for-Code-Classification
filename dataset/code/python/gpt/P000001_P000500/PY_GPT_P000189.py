# problem title : Maximum Circular Subarray Sum
# Circular maximum is max(normal maximum, total minus minimum subarray).
n = int(input()); a = list(map(int, input().split()))[:n]
def kadane(values, choose_max=True):
    cur = best = values[0]
    for x in values[1:]:
        cur = (max if choose_max else min)(x, cur + x)
        best = (max if choose_max else min)(best, cur)
    return best
normal = kadane(a); total = sum(a); minimum = kadane(a, False)
print(normal if normal < 0 else max(normal, total - minimum))
