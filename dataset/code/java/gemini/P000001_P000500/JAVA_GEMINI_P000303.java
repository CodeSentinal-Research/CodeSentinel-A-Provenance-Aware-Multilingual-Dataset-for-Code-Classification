import java.util.*;

public class Solution {
    private static Map<String, List<String>> memo = new HashMap<>();

    private static List<String> dfs(String s, Set<String> dict) {
        if (memo.containsKey(s)) return memo.get(s);
        if (s.isEmpty()) return Collections.singletonList("");
        List<String> res = new ArrayList<>();
        for (String word : dict) {
            if (s.startsWith(word)) {
                List<String> sub = dfs(s.substring(word.length()), dict);
                for (String str : sub) {
                    res.add(word + (str.isEmpty() ? "" : " " + str));
                }
            }
        }
        memo.put(s, res);
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            Set<String> dict = new HashSet<>();
            while (scanner.hasNext()) {
                dict.add(scanner.next());
            }
            List<String> res = dfs(s, dict);
            for (String sentence : res) {
                System.out.println(sentence);
            }
        }
    }
}