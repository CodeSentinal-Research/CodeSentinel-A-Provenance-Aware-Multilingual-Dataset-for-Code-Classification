num1 = input().strip()
num2 = input().strip()
if num1 == '0' or num2 == '0':
    print('0')
else:
    res = [0] * (len(num1) + len(num2))
    for i in range(len(num1)-1, -1, -1):
        for j in range(len(num2)-1, -1, -1):
            mul = int(num1[i]) * int(num2[j])
            p1, p2 = i + j, i + j + 1
            summ = mul + res[p2]
            res[p2] = summ % 10
            res[p1] += summ // 10
    print("".join(map(str, res)).lstrip('0'))
