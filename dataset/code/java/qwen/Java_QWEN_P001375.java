import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        
        int[] countS = new int[26];
        int[] countT = new int[26];
        for(char c : s.toCharArray()) countS[c-'a']++;
        for(char c : t.toCharArray()) countT[c-'a']++;
        
        System.out.println(Arrays.equals(countS, countT) ? "YES" : "NO");
    }
}
