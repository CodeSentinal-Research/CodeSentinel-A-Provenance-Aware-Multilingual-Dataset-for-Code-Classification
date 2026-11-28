import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        
        if(s1.length() > s2.length()) {
            System.out.println("NO");
            return;
        }
        
        int[] s1Count = new int[26];
        int[] s2Count = new int[26];
        for(char c : s1.toCharArray()) s1Count[c-'a']++;
        
        int left = 0;
        for(int right=0; right<s2.length(); right++) {
            s2Count[s2.charAt(right)-'a']++;
            if(right >= s1.length()) {
                s2Count[s2.charAt(left)-'a']--;
                left++;
            }
            if(Arrays.equals(s1Count, s2Count)) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}
