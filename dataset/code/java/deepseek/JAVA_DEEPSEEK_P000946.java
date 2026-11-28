import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String state = scanner.next();
        System.out.println(canWin(state));
    }

    public static boolean canWin(String s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.startsWith("++", i)) {
                if (!canWin(s.substring(0, i) + "--" + s.substring(i + 2))) {
                    return true;
                }
            }
        }
        return false;
    }
}