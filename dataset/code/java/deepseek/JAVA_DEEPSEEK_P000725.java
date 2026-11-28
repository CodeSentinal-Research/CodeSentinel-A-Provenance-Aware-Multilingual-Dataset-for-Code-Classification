import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        System.out.println(splitString(s));
    }

    public static boolean splitString(String s) {
        for (int i = 1; i <= s.length() / 2; i++) {
            if (s.length() % i != 0) continue;
            String part = s.substring(0, i);
            if (checkPart(part, s.length() / i)) return true;
        }
        return false;
    }

    public static boolean checkPart(String part, int multiplier) {
        long prev = Long.parseLong(part);
        for (int i = 1; i < multiplier; i++) {
            long cur = prev - 1;
            if (cur <= Integer.MIN_VALUE || cur > Integer.MAX_VALUE || !String.valueOf(cur).equals(part)) return false;
            prev = cur;
        }
        return true;
    }
}
