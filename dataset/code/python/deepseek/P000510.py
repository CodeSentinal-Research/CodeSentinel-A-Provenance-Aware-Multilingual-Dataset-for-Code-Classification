def finalPricesWithSpecialDiscount(prices):
    n = len(prices)
    stack = []

    for i in range(n):
        while stack and prices[i] <= prices[stack[-1]]:
            j = stack.pop()
            if i - j > 1:
                prices[j] -= prices[i]
        stack.append(i)

    while stack:
        j = stack.pop()
        if stack:
            prices[j] -= prices[stack[-1]]

    return prices

def main():
    prices = list(map(int, input("Enter prices: ").split()))
    print(finalPricesWithSpecialDiscount(prices))

if __name__ == "__main__":
    main()