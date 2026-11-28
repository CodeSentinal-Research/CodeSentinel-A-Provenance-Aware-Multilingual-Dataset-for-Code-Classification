import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String domain = scanner.nextLine();
        for (int i = 0; i < n; i++) {
            String email = scanner.nextLine();
            if (email.endsWith("@" + domain)) {
                System.out.println(email);
           }
        }
    }
}
