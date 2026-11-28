Here is the Python code for the problem:

def addOperators(self, num, target):
    def helper(num, prev, curr, res, product, add, delt):
        if not num:
            if prev == curr and curr == target:
                res.append(expression)
            return
        for i in range(1, len(num)+1):
            if i == 1 or not num.startswith('0'):
                curr = int(num[:i])
                if prev == 0:
                    helper(num[i:], curr, curr, res, curr, curr, curr)
                else:
                    helper(num[i:], prev - curr + product, curr, res, product, curr, curr - prev + delt)

    res = []
    self.helper(num, 0, 0, res, 0, 0, 0)
    return res

This function `addOperators` is a method of a class instance. It's a backtracking algorithm which generates all possible combinations of the digits in the string `num` and operators '+' and '-' and multiplies the current result with the previous results.

The function `addOperators` is called with the given parameters. It starts from the first digit and recursively calls itself for the rest of the string. If the number has started with '0', it prevents the '0' from being used as a leading operator.

The time complexity is O(3^n / n!), which is due to the fact that there are 3 operators (+, -, *) and there are n digits in num. The space complexity is also O(3^n / n!), as we keep a tree of all possible combinations.