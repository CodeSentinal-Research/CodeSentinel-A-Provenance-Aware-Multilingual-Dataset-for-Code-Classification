import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        char C = scanner.next().charAt(0);

        int count = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == C) {
                count++;
           }
        }
        System.out.println(count);
    }
}
