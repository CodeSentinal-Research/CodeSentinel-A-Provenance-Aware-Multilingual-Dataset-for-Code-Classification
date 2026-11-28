import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        
        int maxLen = 0;
        int left = 0;
        Map<Character, Integer> freq = new HashMap<>();
        
        for(int right=0; right<s.length(); right++) {
            freq.put(s.charAt(right), freq.getOrDefault(s.charAt(right), 0) + 1);
            while((right - left + 1) - getMaxFreq(freq) > k) {
                freq.put(s.charAt(left), freq.get(s.charAt(left)) - 1);
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        System.out.println(maxLen);
    }
    
    static int getMaxFreq(Map<Character, Integer> freq) {
        int max = 0;
        for(int v : freq.values()) max = Math.max(max, v);
        return max;
    }
}
