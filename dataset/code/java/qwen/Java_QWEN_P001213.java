import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        System.out.println(isScramble(s1, s2) ? "YES" : "NO");
    }
    
    static Map<String, Boolean> memo = new HashMap<>();
    static boolean isScramble(String s1, String s2) {
        if(s1.equals(s2)) return true;
        String key = s1 + "#" + s2;
        if(memo.containsKey(key)) return memo.get(key);
        
        int[] count = new int[26];
        for(int i=0; i<s1.length(); i++) {
            count[s1.charAt(i)-'a']++;
            count[s2.charAt(i)-'a']--;
        }
        for(int c : count) if(c != 0) { memo.put(key, false); return false; }
        
        for(int i=1; i<s1.length(); i++) {
            if((isScramble(s1.substring(0,i), s2.substring(0,i)) && isScramble(s1.substring(i), s2.substring(i))) ||
               (isScramble(s1.substring(0,i), s2.substring(s2.length()-i)) && isScramble(s1.substring(i), s2.substring(0,s2.length()-i)))) {
                memo.put(key, true);
                return true;
            }
        }
        memo.put(key, false);
        return false;
    }
}
