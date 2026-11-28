# problem title : Expression Add Operators
# Solve the stated task using standard input and standard output.
import sys
def add_ops(num, target, idx, cur_expr, cur_val, prev_op, res):
    if idx == len(num):
        if cur_val == target:
            res.append(cur_expr)
        return
    for i in range(idx, len(num)):
        if i > idx and num[idx] == '0': break
        part = num[idx:i+1]
        v = int(part)
        if idx == 0:
            add_ops(num, target, i + 1, part, v, v, res)
        else:
            add_ops(num, target, i + 1, cur_expr + "+" + part, cur_val + v, v, res)
            add_ops(num, target, i + 1, cur_expr + "-" + part, cur_val - v, -v, res)
            add_ops(num, target, i + 1, cur_expr + "*" + part, cur_val - prev_op + prev_op * v, prev_op * v, res)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        num = tokens[0]
        target = int(tokens[1])
        res = []
        add_ops(num, target, 0, "", 0, 0, res)
        for expr in sorted(res):
            print(expr)
if __name__ == '__main__':
    main()
