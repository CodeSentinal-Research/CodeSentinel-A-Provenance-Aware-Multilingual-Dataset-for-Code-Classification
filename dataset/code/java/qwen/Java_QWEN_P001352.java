import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(canSplit(s, 0, -1, 0) ? "YES" : "NO");
    }
    
    static boolean canSplit(String s, int idx, long prev, int count) {
        if(idx == s.length()) return count > 1;
        long num = 0;
        for(int i=idx; i<s.length(); i++) {
            num = num * 10 + (s.charAt(i) - '0');
            if(prev != -1 && num >= prev) break;
            if(prev == -1 || prev - num == 1) {
                if(canSplit(s, i+1, num, count+1)) return true;
            }
        }
        return false;
    }
}
