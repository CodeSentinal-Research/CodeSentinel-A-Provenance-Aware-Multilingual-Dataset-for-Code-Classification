def buildArray(m, n):
    target = []
    for i in range(m, n - 1, -1):
        target.append('Push')
        if i % 2 == 0:
            target.append('Pop')
    target.append('Push')
    return target

def main():
    m = int(input("Enter the start value of target array: "))
    n = int(input("Enter the end value of target array: "))
    result = buildArray(m, n)
    print(result)

main()