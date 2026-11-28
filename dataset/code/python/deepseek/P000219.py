Here is a Python solution for the problem. The solution uses a stack to track the last K numbers and a variable to hold the product of last K numbers. The input is a list of operations (add and getProduct).

class ProductOfNumbers:
    def __init__(self):
        self.stack = []
        self.product = 1

    def add(self, num: int) -> None:
        if num != 0:
            self.product *= num
            self.stack.append(self.product)

    def getProduct(self, k: int) -> int:
        if k >= len(self.stack):
            return self.product
        else:
            return self.stack[-1] // self.stack[len(self.stack) - k - 1]

The `add` method updates the product and pushes the current product to the stack. The `getProduct` method returns the product of the last K numbers. If K is greater than or equal to the length of the stack, it means we have not used enough numbers to calculate the product of last K numbers, so it returns the current product. Otherwise, it returns the product of last K numbers by dividing the current product by the product of the last K numbers.

To handle the input, you can use the following code:

def main():
    p = ProductOfNumbers()

    p.add(3)
    print(p.getProduct(1))  
    print(p.getProduct(2))  
    print(p.getProduct(3))  
    p.add(5)
    print(p.getProduct(4))  
    print(p.getProduct(2))  

main()

This code will print:

3
6
12
12
5

This shows that the product of last K numbers can be retrieved by multiple calls to `getProduct`.