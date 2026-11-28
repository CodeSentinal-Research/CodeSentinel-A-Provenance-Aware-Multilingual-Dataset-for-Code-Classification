import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int r = scanner.nextInt();
        int n = scanner.nextInt();

        int sum = (a * (1 - (int)Math.pow(r, n))) / (1 - r);
        System.out.println(sum);
    }
}
