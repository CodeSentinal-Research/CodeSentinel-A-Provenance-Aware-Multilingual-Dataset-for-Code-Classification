import java.util.*;

public class Main {
    public static List<String> wordBreak(String s, List<String> wordDict) {
        return helper(s, wordDict, new HashMap<String, List<String>>());
    }

    public static List<String> helper(String s, List<String> wordDict, HashMap<String, List<String>> map) {
        if (map.containsKey(s)) {
            return map.get(s);
       
       }

        List<String> res = new ArrayList<String>();
        if (s.length() == 0) {
            res.add("");
            return res;
        }
        for (String word : wordDict) {
            if (s.startsWith(word)) {
                List<String> subList = helper(s.substring(word.length()), wordDict, map);
                for (String sub : subList) {
                    res.add(word + (sub.isEmpty() ? "" : " ") + sub);
                }
            }
        }
        map.put(s, res);
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String[] words = scanner.nextLine().split(",");
        List<String> wordDict = Arrays.asList(words);
        List<String> result = wordBreak(s, wordDict);
        for (String sentence : result) {
            System.out.println(sentence);
        }
    }
}
