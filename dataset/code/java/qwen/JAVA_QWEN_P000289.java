import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        
        int[] counts = new int[26];
        int maxCount = 0;
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            counts[s.charAt(right) - 'A']++;
            maxCount = Math.max(maxCount, counts[s.charAt(right) - 'A']);
            
            if (right - left + 1 - maxCount > k) {
                counts[s.charAt(left) - 'A']--;
                left++;
            }
            
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        System.out.println(maxLen);
    }
}
