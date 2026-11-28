import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    n1 = int(input_data[0])
    l1 = list(map(int, input_data[1:n1+1]))
    n2 = int(input_data[n1+1])
    l2 = list(map(int, input_data[n1+2:n1+2+n2]))
    num1 = int("".join(map(str, l1[::-1])))
    num2 = int("".join(map(str, l2[::-1])))
    s = str(num1 + num2)[::-1]
    print(" ".join(s))
solve()
