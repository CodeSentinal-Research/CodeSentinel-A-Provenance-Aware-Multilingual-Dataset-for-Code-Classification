import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            // Odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
                count++;
                l--; r++;
            }
            // Even length
            l = i; r = i + 1;
            while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
                count++;
                l--; r++;
            }
        }
        System.out.println(count);
    }
}
