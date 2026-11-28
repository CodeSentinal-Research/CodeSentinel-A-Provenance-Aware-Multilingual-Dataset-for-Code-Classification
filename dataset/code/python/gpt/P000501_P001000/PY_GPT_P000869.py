# problem title : Divide Two Integers Without Division
# Solve the stated task using standard input and standard output.
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        sign = -1 if (dividend < 0) ^ (divisor < 0) else 1
        dvd, dvs = abs(dividend), abs(divisor)
        ans = 0
        while dvd >= dvs:
            temp = dvs
            m = 1
            while (temp << 1) <= dvd:
                temp <<= 1
                m <<= 1
            dvd -= temp
            ans += m
        return sign * ans
