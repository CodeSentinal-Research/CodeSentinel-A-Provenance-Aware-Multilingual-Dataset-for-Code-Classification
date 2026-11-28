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

        System.out.println((x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1));
    }
}
