import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long x1 = scanner.nextLong();
        long y1 = scanner.nextLong();
        long x2 = scanner.nextLong();
        long y2 = scanner.nextLong();
        long x3 = scanner.nextLong();
        long y3 = scanner.nextLong();

        if ((x1 - x2) * (y1 - y3) == (x1 - x3) * (y1 - y2)) {
            System.out.println("Not a Triangle");
        } else if (x1 == x2 && y1 == y2 || x2 == x3 && y2 == y3 || x3 == x1 && y3 == y1) {
            System.out.println("Not a Triangle");
        } else {
            if (x1 == x2 && y1 == y2 || x2 == x3 && y2 == y3 || x3 == x1 && y3 == y1) {
                System.out.println("Isosceles");
            } else if (x1 == x2 && x2 == x3 && y1 == y2 && y2 == y3) {
                System.out.println("Equilateral");
            } else {
                System.out.println("Scalene");
            }
        }
    }
}
