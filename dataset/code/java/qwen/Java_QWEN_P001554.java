import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        int maxLen = 0;
        int left = 0;
        Map<Character, Integer> map = new HashMap<>();
        
        for(int right=0; right<s.length(); right++) {
            char c = s.charAt(right);
            if(map.containsKey(c)) {
                left = Math.max(left, map.get(c) + 1);
            }
            map.put(c, right);
            maxLen = Math.max(maxLen, right - left + 1);
        }
        System.out.println(maxLen);
    }
}
