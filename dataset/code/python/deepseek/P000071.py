def find_triangle_type(a, b, c):
    if a == b and b == c:
        return "Equilateral"
    elif a == b or a == c or b == c:
        return "Isosceles"
    else:
        return "Scalene"

def main():
    a = int(input("Enter side a: "))
    b = int(input("Enter side b: "))
    c = int(input("Enter side c: "))

    if not (1 <= a <= 1000) or not (1 <= b <= 1000) or not (1 <= c <= 1000):
        print("Invalid input. Sides must be in the range 1 to 1000.")
        return

    print(find_triangle_type(a, b, c))

if __name__ == "__main__":
    main()