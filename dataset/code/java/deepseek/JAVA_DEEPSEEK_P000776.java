import java.util.*;

public class Main {
    public static void main(String[] args) {
        String s = new Scanner(System.in).next();
        int m = new Scanner(System.in).nextInt();
        String[] dictionary = new String[m];
        for (int i = 0; i < m; i++) {
            dictionary[i] = new Scanner(System.in).next();
        }

        List<List<String>> partitions = partition(s, dictionary);
        for (List<String> partition : partitions) {
            System.out.println(String.join(" ", partition));
        }
    }

    public static List<List<String>> partition(String s, String[] dict) {
        List<List<String>> res = new ArrayList<>();
        if (s == null || s.length() == 0) {
            return res;
        }
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (String word : dict) {
                if (word.length() <= i && dp[i - word.length()] && s.startsWith(word, i - word.length())) {
                    dp[i] = true;
                    break;
                }
            }
        }
        if (!dp[s.length()]) {
            return res;
        }
        dfs(s, s.length(), dict, new ArrayList<>(), res);
        return res;
    }

    private static void dfs(String s, int end, String[] dict, List<String> currList, List<List<String>> res) {
        if (end == 0) {
            res.add(new ArrayList<>(currList));
            return;
        }
        for (String word : dict) {
            if (end >= word.length() && s.startsWith(word, end - word.length()) && currList.indexOf(word) == -1) {
                currList.add(0, word);
                dfs(s, end - word.length(), dict, currList, res);
                currList.remove(0);
            }
        }
    }
}
