import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        String t = scanner.next();
        System.out.println(isOneEditDistance(s, t) ? "Yes" : "No");
    }

    private static boolean isOneEditDistance(String s, String t) {
        if (s.equals(t)) return false;
        int lenS = s.length();
        int lenT = t.length();
        if (Math.abs(lenS - lenT) > 1) return false;
        int i = 0, j = 0;
        int editCount = 0;
        while (i < lenS && j < lenT) {
            if (s.charAt(i) != t.charAt(j)) {
                if (editCount == 1) return false;
                if (lenS < lenT) {
                    j++;
                } else if (lenT < lenS) {
                    i++;
                } else {
                    i++;
                    j++;
                }
                editCount++;
            } else {
                i++;
                j++;
            }
        }
        if (i < lenS || j < lenT) editCount++;
        return editCount == 1;
    }
}
