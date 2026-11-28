def print_pascal_triangle(n):
    for i in range(n):
        for j in range(i+1):
            if j == 0 or j == i:
                print("1", end=" ")
            else:
                print("0", end=" ")
        print("")

print_pascal_triangle(5)