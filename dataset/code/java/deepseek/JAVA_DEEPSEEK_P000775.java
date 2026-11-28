import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        generateStrings(n, "");
    }

    private static void generateStrings(int n, String s) {
        if (s.length() == n) {
            System.out.println(s);
            return;
        }
        generateStrings(n, s + "0");
        if (s.isEmpty() || s.charAt(s.length() - 1) == '0') {
            generateStrings(n, s + "1");
        }
    }
}
