Here is a Python solution for the given problem:

import math

def euclidean_distance(x1, y1, x2, y2):
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

print(euclidean_distance(1, 1, 4, 4))

In this code, we define a function `euclidean_distance` that takes four parameters: the x and y coordinates of two points. This function calculates the Euclidean distance using the formula `sqrt((x2 - x1)^2 + (y2 - y1)^2)`, which is derived from the Pythagorean theorem.

The function `math.sqrt` is used to calculate the square root of a number. The `**` operator is used to raise a number to a power.

We then test the function by passing the coordinates (1,1) and (4,4) to the function. The result should be 5.0, indicating that the points are 5 units apart in the 2D plane.