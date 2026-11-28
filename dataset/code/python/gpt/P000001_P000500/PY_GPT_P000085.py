# problem title : Grade Calculation
# Apply grade thresholds from highest to lowest.
marks = int(input())
if marks >= 90: grade = 'A'
elif marks >= 80: grade = 'B'
elif marks >= 70: grade = 'C'
elif marks >= 60: grade = 'D'
else: grade = 'F'
print(grade)
