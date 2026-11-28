import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        int maxLen = 1;
        int left = 0;
        boolean hasPair = false;
        
        for(int right=1; right<s.length(); right++) {
            if(s.charAt(right) == s.charAt(right-1)) {
                if(hasPair) {
                    left = right - 1;
                }
                hasPair = true;
            } else {
                hasPair = false;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        System.out.println(maxLen);
    }
}
