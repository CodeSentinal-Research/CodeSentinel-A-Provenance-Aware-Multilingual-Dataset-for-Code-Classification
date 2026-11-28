u = int(input())
bill = 0
if u <= 100:
    bill = u * 5
elif u <= 200:
    bill = 100 * 5 + (u - 100) * 10
else:
    bill = 100 * 5 + 100 * 10 + (u - 200) * 15
print(bill)
