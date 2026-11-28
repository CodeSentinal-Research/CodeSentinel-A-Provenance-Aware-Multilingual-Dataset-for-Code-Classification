Here is the python code that implements the required problem:

from collections import deque

def online_stock_span():
    stock_prices = deque()

    while True:
        price = int(input())
        if price == -1:
            break
        stock_prices.append(price)

        span = 1

        while stock_prices and stock_prices[0] <= price:
            span += 1
            stock_prices.popleft()

        print(span)


def main():
    online_stock_span()


if __name__ == "__main__":
    main()

The code is asking for stock prices as input from the user and for each price, it calculates the maximum number of consecutive days (including today) where the stock price was less than or equal to today's price. The result is then printed to the console. The stock prices are stored in a deque to keep track of the prices, allowing for efficient lookups.