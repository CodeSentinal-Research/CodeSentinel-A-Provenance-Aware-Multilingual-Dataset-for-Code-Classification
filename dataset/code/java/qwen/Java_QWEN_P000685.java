import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(isPalin(s, 0, s.length() - 1) ? "true" : "false");
    }
    static boolean isPalin(String s, int l, int r) {
        if(l >= r) return true;
        if(s.charAt(l) != s.charAt(r)) return false;
        return isPalin(s, l + 1, r - 1);
    }
}
