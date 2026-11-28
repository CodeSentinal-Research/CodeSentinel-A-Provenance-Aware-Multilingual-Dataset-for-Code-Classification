import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(countAndSay(n));
    }

    public static String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        StringBuilder result = new StringBuilder();
        String prev = countAndSay(n - 1);
        int count = 1;
        for (int i = 1; i < prev.length(); i++) {
            if (prev.charAt(i) == prev.charAt(i - 1)) {
                count++;
            } else {
                result.append(count).append(prev.charAt(i - 1));
                count = 1;
            }
        }
        result.append(count).append(prev.charAt(prev.length() - 1));
        return result.toString();
    }
}
