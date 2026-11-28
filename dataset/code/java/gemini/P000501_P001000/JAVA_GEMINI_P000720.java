import java.util.*;
public class Solution {
    static void addOps(String num, long target, int idx, String curExpr, long curVal, long prevOp, List<String> res) {
        if (idx == num.length()) {
            if (curVal == target) res.add(curExpr);
            return;
        }
        for (int i = idx; i < num.length(); i++) {
            if (i > idx && num.charAt(idx) == '0') break;
            String part = num.substring(idx, i + 1);
            long v = Long.parseLong(part);
            if (idx == 0) {
                addOps(num, target, i + 1, part, v, v, res);
            } else {
                addOps(num, target, i + 1, curExpr + "+" + part, curVal + v, v, res);
                addOps(num, target, i + 1, curExpr + "-" + part, curVal - v, -v, res);
                addOps(num, target, i + 1, curExpr + "*" + part, curVal - prevOp + prevOp * v, prevOp * v, res);
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String num = scanner.next();
            long target = scanner.nextLong();
            List<String> res = new ArrayList<>();
            addOps(num, target, 0, "", 0, 0, res);
            Collections.sort(res);
            for (String s : res) System.out.println(s);
        }
    }
}