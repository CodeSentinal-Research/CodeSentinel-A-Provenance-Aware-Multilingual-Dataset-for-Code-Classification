def area_of_triangle(coords1, coords2, coords3):
    x1, y1 = coords1
    x2, y2 = coords2
    x3, y3 = coords3
    
    area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2)
    
    return area

def handle_input():
    coords1 = tuple(map(int, input("Enter the coordinates of the first vertex (x, y): ").split()))
    coords2 = tuple(map(int, input("Enter the coordinates of the second vertex (x, y): ").split()))
    coords3 = tuple(map(int, input("Enter the coordinates of the third vertex (x, y): ").split()))
    
    return (coords1, coords2, coords3)

def main():
    coords1, coords2, coords3 = handle_input()
    
    area = area_of_triangle(coords1, coords2, coords3)
    
    print("The area of the triangle is:", area)

if __name__ == "__main__":
    main()