def dfs(num, target, curr_num, curr_exp, curr_sum, curr_prod, add_oper, add_val):
    if len(num) == 0:
        if curr_sum + curr_prod == target:
            print(curr_exp)
        return

    for i in range(1, len(num) + 1):
        curr_dig = num[:i]
        curr_num_str = num[:i]

        if curr_dig[0] == '0' and len(curr_dig) > 1:
            continue

        curr_num = int(curr_num_str)

        if add_oper == '+':
            dfs(num[i:], target, curr_num + curr_sum, curr_exp + '+' + curr_num_str, curr_sum + curr_num, curr_prod, curr_dig, curr_num)
        elif add_oper == '-':
            dfs(num[i:], target, curr_num - curr_sum, curr_exp + ' - ' + curr_num_str, curr_sum - curr_num, curr_prod, curr_dig, curr_num)
        elif add_oper == '*':
            dfs(num[i:], target, curr_sum + curr_prod, curr_exp + ' * ' + curr_num_str, curr_sum, curr_prod * curr_num, curr_dig, curr_num)

def main():
    input_str = input().split()
    num = input_str[0]
    target = int(input_str[1])
    dfs(num, target, 0, '', 0, 1, '+', num[0])

main()