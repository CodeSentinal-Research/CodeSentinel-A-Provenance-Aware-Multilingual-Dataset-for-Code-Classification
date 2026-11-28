import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String num = scanner.next();
        int k = scanner.nextInt();
        System.out.println(removeKDigits(num, k));
    }

    public static String removeKDigits(String num, int k) {
        if (k >= num.length()) {
            return "0";
        }

        StringBuilder sb = new StringBuilder(num);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < sb.length() - 1; j++) {
                if (sb.charAt(j) > sb.charAt(j + 1)) {
                    sb.deleteCharAt(j);
                    break;
                }
            }
        }

        while (sb.length() > 1 && sb.charAt(0) == '0') {
            sb.deleteCharAt(0);
        }

        return sb.toString();
    }
}
