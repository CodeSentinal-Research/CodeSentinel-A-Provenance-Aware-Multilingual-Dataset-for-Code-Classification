import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // consume newline
        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();
            if (s.isEmpty()) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);
    }
}
