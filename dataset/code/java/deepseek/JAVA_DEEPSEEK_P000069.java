import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double radius = scanner.nextDouble();
        double perimeter = 2 * Math.PI * radius;
        System.out.printf("%.2f", perimeter);
    }
}
