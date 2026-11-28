import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        
        System.out.println(atMostK(s, k) - atMostK(s, k - 1));
    }
    
    static int atMostK(String s, int k) {
        if(k < 0) return 0;
        int maxLen = 0;
        int left = 0;
        Map<Character, Integer> freq = new HashMap<>();
        
        for(int right=0; right<s.length(); right++) {
            freq.put(s.charAt(right), freq.getOrDefault(s.charAt(right), 0) + 1);
            while(freq.size() > k) {
                freq.put(s.charAt(left), freq.get(s.charAt(left)) - 1);
                if(freq.get(s.charAt(left)) == 0) freq.remove(s.charAt(left));
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }
}
