import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        generateBinaryStrings(n, "");
    }

    private static void generateBinaryStrings(int n, String str) {
        if (str.length() == n) {
            System.out.println(str);
            return;
        }
        generateBinaryStrings(n, str + "0");
        if (str.length() == 0 || str.charAt(str.length() - 1) == '0') {
            generateBinaryStrings(n, str + "1");
        }
    }
}
