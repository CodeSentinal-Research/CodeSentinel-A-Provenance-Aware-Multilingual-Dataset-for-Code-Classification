import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        List<String> res = new ArrayList<>();
        restore(s, 0, "", 0, res);
        for (String ip : res) System.out.println(ip);
    }
    static void restore(String s, int idx, String curr, int dots, List<String> res) {
        if (dots == 4 && idx == s.length()) {
            res.add(curr.substring(1));
            return;
        }
        if (dots > 4 || idx >= s.length()) return;
        for (int i = 1; i <= 3; i++) {
            if (idx + i > s.length()) break;
            String part = s.substring(idx, idx + i);
            if ((part.length() > 1 && part.startsWith("0")) || Integer.parseInt(part) > 255) continue;
            restore(s, idx + i, curr + "." + part, dots + 1, res);
        }
    }
}
