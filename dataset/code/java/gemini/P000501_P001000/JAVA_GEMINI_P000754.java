import java.util.*;
public class Solution {
    static void casePerm(String s, int idx, String cur, List<String> res) {
        if (idx == s.length()) {
            res.add(cur);
            return;
        }
        char ch = s.charAt(idx);
        if (Character.isLetter(ch)) {
            casePerm(s, idx + 1, cur + Character.toLowerCase(ch), res);
            casePerm(s, idx + 1, cur + Character.toUpperCase(ch), res);
        } else {
            casePerm(s, idx + 1, cur + ch, res);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            List<String> res = new ArrayList<>();
            casePerm(s, 0, "", res);
            Collections.sort(res);
            for (String p : res) System.out.println(p);
        }
    }
}