import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String f = sc.next();
        String s = sc.next();
        String t = sc.next();
        
        long fv = getVal(f);
        long sv = getVal(s);
        long tv = getVal(t);
        
        System.out.println(fv + sv == tv ? "Yes" : "No");
    }
    static long getVal(String w) {
        long val = 0;
        for (char c : w.toCharArray()) {
            val = val * 10 + (c - 'a');
        }
        return val;
    }
}
