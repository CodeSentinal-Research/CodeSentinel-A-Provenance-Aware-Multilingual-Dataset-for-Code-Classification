import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        double root1, root2;

        // calculate the roots
        double determinant = b * b - 4 * a * c;
        double sqrtval = Math.sqrt(Math.abs(determinant));

        if (determinant > 0) {
            root1 = (-b + sqrtval) / (2 * a);
            root2 = (-b - sqrtval) / (2 * a);
            System.out.format("root1 = %.2f and root2 = %.2f", root1, root2);
        } else if (determinant == 0) {
            root1 = root2 = -b / (2 * a);
            System.out.format("root1 = root2 = %.2f;", root1);
        } else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrtval / (2 * a);
            System.out.format("root1 = %.2f+%.2fi and root2 = %.2f-%.2fi", realPart, imaginaryPart, realPart, imaginaryPart);
        }
    }
}
