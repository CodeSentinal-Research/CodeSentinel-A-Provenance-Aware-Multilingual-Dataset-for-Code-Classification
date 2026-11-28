import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        if (Math.abs(s.length() - t.length()) > 1) {
            System.out.println("No"); return;
        }
        if (s.length() == t.length()) {
            int diff = 0;
            for (int i = 0; i < s.length(); i++) if (s.charAt(i) != t.charAt(i)) diff++;
            System.out.println(diff == 1 ? "Yes" : "No");
        } else {
            String longer = s.length() > t.length() ? s : t;
            String shorter = s.length() > t.length() ? t : s;
            int i = 0, j = 0;
            while (i < shorter.length() && shorter.charAt(i) == longer.charAt(j)) {
                i++; j++;
            }
            j++;
            while (i < shorter.length() && shorter.charAt(i) == longer.charAt(j)) {
                i++; j++;
            }
            System.out.println(i == shorter.length() ? "Yes" : "No");
        }
    }
}
