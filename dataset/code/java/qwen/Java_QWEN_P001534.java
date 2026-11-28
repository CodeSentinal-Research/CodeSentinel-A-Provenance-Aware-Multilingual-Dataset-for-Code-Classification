import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        int maxLen = 0;
        int left = 0;
        Map<Character, Integer> freq = new HashMap<>();
        
        for(int right=0; right<s.length(); right++) {
            freq.put(s.charAt(right), freq.getOrDefault(s.charAt(right), 0) + 1);
            while(freq.size() > 2) {
                freq.put(s.charAt(left), freq.get(s.charAt(left)) - 1);
                if(freq.get(s.charAt(left)) == 0) freq.remove(s.charAt(left));
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        System.out.println(maxLen);
    }
}
