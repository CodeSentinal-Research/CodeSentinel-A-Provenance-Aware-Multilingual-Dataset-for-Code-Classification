import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        
        int maxLen = 0;
        int vowelCount = 0;
        int left = 0;
        String vowels = "aeiou";
        
        for(int right=0; right<s.length(); right++) {
            if(vowels.indexOf(s.charAt(right)) != -1) vowelCount++;
            while(vowelCount > k) {
                if(vowels.indexOf(s.charAt(left)) != -1) vowelCount--;
                left++;
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        System.out.println(maxLen);
    }
}
