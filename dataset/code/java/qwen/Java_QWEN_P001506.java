import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        
        int minLen = Integer.MAX_VALUE;
        int start = 0;
        int left = 0, right = 0;
        int formed = 0;
        Map<Character, Integer> need = new HashMap<>();
        Map<Character, Integer> window = new HashMap<>();
        
        for(char c : t.toCharArray()) need.put(c, need.getOrDefault(c, 0) + 1);
        
        while(right < s.length()) {
            char c = s.charAt(right);
            window.put(c, window.getOrDefault(c, 0) + 1);
            if(need.containsKey(c) && window.get(c).intValue() == need.get(c).intValue()) formed++;
            
            while(left <= right && formed == need.size()) {
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char d = s.charAt(left);
                window.put(d, window.get(d) - 1);
                if(need.containsKey(d) && window.get(d).intValue() < need.get(d).intValue()) formed--;
                left++;
            }
            right++;
        }
        
        System.out.println(minLen == Integer.MAX_VALUE ? "" : s.substring(start, start + minLen));
    }
}
