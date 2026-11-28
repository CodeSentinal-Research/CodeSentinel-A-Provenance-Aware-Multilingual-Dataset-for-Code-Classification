# problem title : Calculate Distance Between Two Points
# Apply the Euclidean distance formula in two dimensions.
import math
x1, y1, x2, y2 = map(float, input().split())
print(math.hypot(x2 - x1, y2 - y1))
