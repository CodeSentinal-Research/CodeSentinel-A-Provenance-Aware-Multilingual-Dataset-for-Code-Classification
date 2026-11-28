import java.util.*;

public class Main {
    public static List<String> addOperators(String num, int target) {
        List<String> result = new ArrayList<>();
        if (num == null || num.length() == 0) {
            return result;
        }
        helper(num, target, 0, 0, 0, new StringBuilder(), result);
        return result;
    }

    private static void helper(String num, int target, int pos, long prev, long multi, StringBuilder sb, List<String> result) {
        if (pos == num.length()) {
            if (target == prev) {
                result.add(sb.toString());
            }
            return;
        }
        for (int i = pos; i < num.length(); i++) {
            if (num.charAt(pos) == '0' && i != pos) { // Avoid numbers starting with 0
                break;
            }
            long cur = Long.parseLong(num.substring(pos, i + 1));
            int len = sb.length();
            if (pos == 0) {
                helper(num, target, i + 1, cur, cur, sb, result);
            } else {
                sb.append('+').append(cur);
                helper(num, target, i + 1, prev + cur, cur, sb, result);
                sb.setLength(len);
                sb.append('-').append(cur);
                helper(num, target, i + 1, prev - cur, -cur, sb, result);
                sb.setLength(len);
                sb.append('*').append(cur);
                helper(num, target, i + 1, prev - multi + multi * cur, multi * cur, sb, result);
            }
            if (cur == 0) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        List<String> result = addOperators("123", 6);
        for (String s : result) {
            System.out.println(s);
        }
    }
}
