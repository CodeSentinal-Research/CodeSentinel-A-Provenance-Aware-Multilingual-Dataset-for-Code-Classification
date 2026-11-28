import java.util.*;
public class Solution {
    static Set<String> dict = new HashSet<>();
    static List<List<String>> res = new ArrayList<>();
    static void backtrack(String s, int idx, List<String> cur) {
        if (idx == s.length()) {
            res.add(new ArrayList<>(cur));
            return;
        }
        for (int end = idx + 1; end <= s.length(); end++) {
            String w = s.substring(idx, end);
            if (dict.contains(w)) {
                cur.add(w);
                backtrack(s, end, cur);
                cur.remove(cur.size() - 1);
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int m = scanner.nextInt();
            for (int i = 0; i < m; i++) dict.add(scanner.next());
            backtrack(s, 0, new ArrayList<>());
            res.sort((a, b) -> {
                for (int i = 0; i < Math.min(a.size(), b.size()); i++) {
                    if (!a.get(i).equals(b.get(i))) return a.get(i).compareTo(b.get(i));
                }
                return a.size() - b.size();
            });
            for (List<String> part : res) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < part.size(); i++) sb.append(part.get(i)).append(i + 1 == part.size() ? "" : " ");
                System.out.println(sb.toString());
            }
        }
    }
}