import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        
        if (s1.length() != s2.length()) {
            System.out.println("No");
            return;
        }
        
        int[] counts = new int[26];
        for (char c : s1.toCharArray()) {
            counts[c - 'a']++;
        }
        
        int left = 0;
        for (int right = 0; right < s2.length(); right++) {
            counts[s2.charAt(right) - 'a']--;
            
            if (right >= s1.length()) {
                counts[s2.charAt(left) - 'a']++;
                left++;
            }
            
            boolean allZero = true;
            for (int count : counts) {
                if (count != 0) {
                    allZero = false;
                    break;
                }
            }
            
            if (allZero) {
                System.out.println("Yes");
                return;
            }
        }
        
        System.out.println("No");
    }
}
