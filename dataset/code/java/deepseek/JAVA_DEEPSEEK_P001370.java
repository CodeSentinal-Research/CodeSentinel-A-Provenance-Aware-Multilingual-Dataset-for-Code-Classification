import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String num = scanner.next();
        int k = scanner.nextInt();
        System.out.println(maximumNumber(num, k));
    }

    private static String maximumNumber(String num, int k) {
        int n = num.length();
        StringBuilder sb = new StringBuilder(num);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (sb.charAt(j) < sb.charAt(j + 1)) {
                    sb.setCharAt(j, sb.charAt(j + 1));
                    sb.setCharAt(j + 1, sb.charAt(j));
                }
            }
        }
        return sb.toString();
    }
}
