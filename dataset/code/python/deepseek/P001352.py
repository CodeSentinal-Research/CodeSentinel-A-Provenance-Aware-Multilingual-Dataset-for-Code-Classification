def solve():
    str_num = input().strip()
    if str_num[0] == '0':
        print('NO')
        return
    str_num = list(str_num)
    str_num.sort()
    str_num.reverse()
    i = 0
    while i < len(str_num)-1:
        if str_num[i] != '9' and str_num[i] != str_num[i+1]:
            break
        i += 1
    if i == len(str_num)-1:
        print('NO')
        return
    print('YES')

def main():
    solve()

if __name__ == '__main__':
    main()