import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String answerKey = sc.next();
        int k = sc.nextInt();
        
        int maxT = getMax(answerKey, k, 'T');
        int maxF = getMax(answerKey, k, 'F');
        System.out.println(Math.max(maxT, maxF));
    }
    
    static int getMax(String s, int k, char target) {
        int left = 0, maxLen = 0;
        int changes = 0;
        for(int right=0; right<s.length(); right++) {
            if(s.charAt(right) != target) changes++;
            while(changes > k) {
                if(s.charAt(left) != target) changes--;
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }
}
