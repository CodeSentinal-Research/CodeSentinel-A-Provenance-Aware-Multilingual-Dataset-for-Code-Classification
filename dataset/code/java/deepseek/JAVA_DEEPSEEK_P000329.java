import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        String T = scanner.next();
        scanner.close();

        for (int i = 0; i < T.length(); i++) {
            if (i < S.length() && S.charAt(i) != T.charAt(i)) {
                System.out.println(T.charAt(i));
                break;
            }
        }
    }
}
