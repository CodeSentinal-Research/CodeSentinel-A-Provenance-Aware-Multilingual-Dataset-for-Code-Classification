import java.util.*;
public class Solution {
    static Set<String> dict = new HashSet<>();
    static Map<Integer, List<String>> memo = new HashMap<>();
    static List<String> backtrack(String s, int idx) {
        if (memo.containsKey(idx)) return memo.get(idx);
        if (idx == s.length()) return Collections.singletonList("");
        List<String> res = new ArrayList<>();
        for (int end = idx + 1; end <= s.length(); end++) {
            String w = s.substring(idx, end);
            if (dict.contains(w)) {
                List<String> sub = backtrack(s, end);
                for (String sent : sub) {
                    res.add((w + (sent.isEmpty() ? "" : " ") + sent));
                }
            }
        }
        memo.put(idx, res);
        return res;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int m = scanner.nextInt();
            for (int i = 0; i < m; i++) dict.add(scanner.next());
            List<String> res = backtrack(s, 0);
            Collections.sort(res);
            for (String sent : res) System.out.println(sent);
        }
    }
}