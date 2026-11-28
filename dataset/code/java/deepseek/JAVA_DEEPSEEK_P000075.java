import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double r = scanner.nextDouble();
        double h = scanner.nextDouble();
        double volume = Math.PI * Math.pow(r, 2) * h;
        System.out.printf("%.2f", volume);
    }
}
