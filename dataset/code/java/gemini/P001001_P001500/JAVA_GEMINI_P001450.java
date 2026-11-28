import java.util.*;

public class Solution {
    public String rankTeams(String[] votes) {
        int n = votes[0].length();
        Map<Character, int[]> map = new HashMap<>();
        for (char c : votes[0].toCharArray()) map.put(c, new int[n]);

        for (String v : votes) {
            for (int i = 0; i < n; i++) {
                map.get(v.charAt(i))[i]++;
            }
        }

        List<Character> list = new ArrayList<>(map.keySet());
        list.sort((a, b) -> {
            for (int i = 0; i < n; i++) {
                if (map.get(a)[i] != map.get(b)[i]) {
                    return map.get(b)[i] - map.get(a)[i];
                }
            }
            return a - b;
        });

        StringBuilder sb = new StringBuilder();
        for (char c : list) sb.append(c);
        return sb.toString();
    }
}