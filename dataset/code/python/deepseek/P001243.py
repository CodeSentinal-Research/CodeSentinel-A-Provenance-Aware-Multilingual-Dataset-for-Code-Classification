def can_make_change(payments):
    for payment in payments:
        if payment % 5 != 0:
            return "NO"
    return "YES"

def main():
    N = int(input().strip())
    payments = [int(input().strip()) for _ in range(N)]
    print(can_make_change(payments))

main()