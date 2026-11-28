import java.util.*;
public class Solution {
    public Map<Character,Integer> countChars(String s) {
        Map<Character,Integer> map = new TreeMap<>();
        for (char c : s.toCharArray()) map.merge(c, 1, Integer::sum);
        return map;
    }
    public static void main(String[] args) {
        String s = new Scanner(System.in).next();
        new Solution().countChars(s).forEach((k,v)->System.out.println(k+": "+v));
    }
}
