import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double P = scanner.nextDouble();
        double R = scanner.nextDouble();
        double T = scanner.nextDouble();

        double compoundInterest = P * Math.pow(1.0 + R / 100.0, T) - P;

        System.out.printf("%.2f", compoundInterest);
    }
}
