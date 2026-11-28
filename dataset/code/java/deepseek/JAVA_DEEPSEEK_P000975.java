import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x1 = scanner.nextInt();
        int y1 = scanner.nextInt();
        int x2 = scanner.nextInt();
        int y2 = scanner.nextInt();

        double midX = (double)(x1 + x2) / 2;
        double midY = (double)(y1 + y2) / 2;

        System.out.printf("%.0f %.0f", midX, midY);
    }
}
