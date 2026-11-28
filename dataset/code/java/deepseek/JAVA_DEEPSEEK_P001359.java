import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();

        System.out.println(constructSequence(n));
    }

    private static String constructSequence(int n) {
        StringBuilder sb = new StringBuilder();
        sb.append(n);
        sb.append(n - 1);
        for (int i = n - 1; i >= 1; i--) {
            sb.append(i);
            sb.append(i);
        }
        return sb.toString();
    }
}
