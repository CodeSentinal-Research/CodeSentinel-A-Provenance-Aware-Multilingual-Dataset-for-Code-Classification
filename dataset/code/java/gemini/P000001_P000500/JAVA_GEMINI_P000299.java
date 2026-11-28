import java.util.*;

public class Solution {
    private static void backtrack(List<String> res, String current, int open, int close, int max) {
        if (current.length() == max * 2) {
            res.add(current);
            return;
        }
        if (open < max) {
            backtrack(res, current + "(", open + 1, close, max);
        }
        if (close < open) {
            backtrack(res, current + ")", open, close + 1, max);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<String> res = new ArrayList<>();
            backtrack(res, "", 0, 0, n);
            for (String s : res) {
                System.out.println(s);
            }
        }
    }
}