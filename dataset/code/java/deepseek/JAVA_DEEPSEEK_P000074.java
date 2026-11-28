import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double radius = scanner.nextDouble();
        double volume = (4.0/3.0) * Math.PI * Math.pow(radius, 3);
        System.out.printf("%.2f", volume);
    }
}
