import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        
        int[] freq = new int[26];
        for(char c : s.toCharArray()) freq[c-'a']++;
        
        int oddCount = 0;
        for(int f : freq) {
            if(f % 2 != 0) oddCount++;
        }
        
        System.out.println(oddCount <= k ? "YES" : "NO");
    }
}
