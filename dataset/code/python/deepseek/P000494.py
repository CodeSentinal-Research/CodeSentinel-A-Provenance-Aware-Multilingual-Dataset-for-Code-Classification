Here is a Python solution for the problem:

def daily_temperatures(temperatures):
    res = [0] * len(temperatures)
    stack = []
    for i, curr in enumerate(temperatures):
        while stack and curr > temperatures[stack[-1]]:
            last = stack.pop()
            res[last] = i - last
        stack.append(i)
    return res

This code uses a stack to keep track of the indices of the temperatures that are currently being checked. It iterates over the temperatures array from left to right. For each temperature, it compares it with the temperature at the top of the stack. If it's warmer, it pops the stack and calculates the number of days until a warmer temperature is found. If the stack is empty or the current temperature is not warmer than the top, it pushes the current index to the stack.

In the end, the result list is returned.

The main function to test the code:

def main():
    temperatures = [73, 74, 75, 71, 69, 72]
    print(daily_temperatures(temperatures))  

if __name__ == "__main__":
    main()

This will print the expected output for the given example.