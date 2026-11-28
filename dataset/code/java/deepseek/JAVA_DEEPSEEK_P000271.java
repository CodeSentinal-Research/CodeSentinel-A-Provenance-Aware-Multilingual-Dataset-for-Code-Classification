import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s1 = scanner.next();
        String s2 = scanner.next();
        scanner.close();

        if (s1.length() != s2.length()) {
            System.out.println("No");
            return;
        }

        String s1s1 = s1 + s1;
        if (s1s1.contains(s2)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
