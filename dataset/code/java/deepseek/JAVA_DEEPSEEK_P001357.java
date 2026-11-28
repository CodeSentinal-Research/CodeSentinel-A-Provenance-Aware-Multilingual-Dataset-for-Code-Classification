import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String num = scanner.next();
        System.out.println(isAdditive(num));
    }

    public static boolean isAdditive(String num) {
        for (int i = 0; i < num.length(); i++) {
            for (int j = i + 1; j < num.length(); j++) {
                if (num.charAt(i) == '0' && num.length() > 1) continue;
                String a = num.substring(0, i + 1);
                String b = num.substring(i + 1, j + 1);
                if (isValid(a, b, num)) return true;
                String c = num.substring(j + 1);
                if (isValid(b, c, num)) return true;
            }
        }
        return false;
    }

    public static boolean isValid(String a, String b, String num) {
        if (a.equals("0") && b.length() > 1) return false;
        long sum = Long.parseLong(a + b);
        if (sum > Long.parseLong(num.substring(0, a.length() + b.length()))) return false;
        while (b.length() < num.length()) {
            a = b;
            b = sum + a;
            sum = Long.parseLong(a + b);
            if (sum > Long.parseLong(num.substring(0, a.length() + b.length()))) return false;
        }
        return true;
    }
}
