import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        scanner.close();

        for (int i = 1; i <= s.length() / 2; i++) {
            if (s.length() % i == 0) {
                StringBuilder pattern = new StringBuilder(s.substring(0, i));
                StringBuilder repeatedPattern = new StringBuilder();
                for (int j = 0; j < s.length() / i; j++) {
                    repeatedPattern.append(pattern);
                }
                if (s.equals(repeatedPattern.toString())) {
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }
}
