import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        System.out.println(numDistinct(s, t, s.length(), t.length()));
    }
    static long numDistinct(String s, String t, int m, int n) {
        if(n == 0) return 1;
        if(m == 0) return 0;
        if(s.charAt(m-1) == t.charAt(n-1))
            return numDistinct(s, t, m-1, n-1) + numDistinct(s, t, m-1, n);
        else
            return numDistinct(s, t, m-1, n);
    }
}
