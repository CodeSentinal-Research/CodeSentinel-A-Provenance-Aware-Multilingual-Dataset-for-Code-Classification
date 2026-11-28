import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Set<String> res = new TreeSet<>();
        int[] count = new int[256];
        int left = 0, right = 0, extra = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
                else extra++;
            }
        }
        removeInvalid(s, 0, new StringBuilder(), left, extra, 0, res);
        for (String str : res) System.out.println(str);
    }
    static void removeInvalid(String s, int idx, StringBuilder curr, int leftRem, int rightRem, int openCount, Set<String> res) {
        if (idx == s.length()) {
            if (leftRem == 0 && rightRem == 0) res.add(curr.toString());
            return;
        }
        char c = s.charAt(idx);
        if (c != '(' && c != ')') {
            curr.append(c);
            removeInvalid(s, idx + 1, curr, leftRem, rightRem, openCount, res);
            curr.deleteCharAt(curr.length() - 1);
        } else {
            if (c == '(') {
                if (leftRem > 0) removeInvalid(s, idx + 1, curr, leftRem - 1, rightRem, openCount, res);
                curr.append(c);
                removeInvalid(s, idx + 1, curr, leftRem, rightRem, openCount + 1, res);
                curr.deleteCharAt(curr.length() - 1);
            } else if (c == ')') {
                if (rightRem > 0) removeInvalid(s, idx + 1, curr, leftRem, rightRem - 1, openCount, res);
                if (openCount > 0) {
                    curr.append(c);
                    removeInvalid(s, idx + 1, curr, leftRem, rightRem, openCount - 1, res);
                    curr.deleteCharAt(curr.length() - 1);
                }
            }
        }
    }
}
