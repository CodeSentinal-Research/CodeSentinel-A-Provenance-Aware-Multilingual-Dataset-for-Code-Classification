import java.util.*;

public class Solution {
    // Sorts the input array into ordered sequence.
    public String frequencySort(String s) {
        Map<Character, Integer> count = new HashMap<>();
        for (char c : s.toCharArray()) count.put(c, count.getOrDefault(c, 0) + 1);

        List<Character> list = new ArrayList<>(count.keySet());
        list.sort((a, b) -> count.get(b) - count.get(a));

        StringBuilder sb = new StringBuilder();
        for (char c : list) {
            int freq = count.get(c);
            for (int i = 0; i < freq; i++) sb.append(c);
        }
        return sb.toString();
    }
}