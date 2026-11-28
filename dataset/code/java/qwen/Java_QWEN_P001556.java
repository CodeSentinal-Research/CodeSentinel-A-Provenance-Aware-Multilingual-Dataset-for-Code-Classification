import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.next();
        String pattern = sc.next();
        
        int[] pCount = new int[26];
        int[] tCount = new int[26];
        for(char c : pattern.toCharArray()) pCount[c-'a']++;
        
        int count = 0;
        int left = 0;
        for(int right=0; right<text.length(); right++) {
            tCount[text.charAt(right)-'a']++;
            if(right >= pattern.length()) {
                tCount[text.charAt(left)-'a']--;
                left++;
            }
            if(Arrays.equals(pCount, tCount)) count++;
        }
        System.out.println(count);
    }
}
