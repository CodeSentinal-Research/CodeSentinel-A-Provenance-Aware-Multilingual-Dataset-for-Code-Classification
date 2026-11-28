import java.util.*;
public class Solution {
    static void genSubseq(String s, int idx, String cur, List<String> res) {
        if (idx == s.length()) {
            res.add(cur);
            return;
        }
        genSubseq(s, idx + 1, cur, res);
        genSubseq(s, idx + 1, cur + s.charAt(idx), res);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            List<String> res = new ArrayList<>();
            genSubseq(s, 0, "", res);
            Collections.sort(res);
            for (String str : res) System.out.println(str);
        }
    }
}