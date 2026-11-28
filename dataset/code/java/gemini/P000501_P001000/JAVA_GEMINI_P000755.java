import java.util.*;
public class Solution {
    static void backtrack(String word, int idx, String cur, int count, List<String> res) {
        if (idx == word.length()) {
            res.add(cur + (count > 0 ? String.valueOf(count) : ""));
            return;
        }
        backtrack(word, idx + 1, cur, count + 1, res);
        backtrack(word, idx + 1, cur + (count > 0 ? String.valueOf(count) : "") + word.charAt(idx), 0, res);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            List<String> res = new ArrayList<>();
            backtrack(scanner.next(), 0, "", 0, res);
            Collections.sort(res);
            for (String s : res) System.out.println(s);
        }
    }
}