import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        genSub(s, 0, "");
    }
    static void genSub(String s, int i, String curr) {
        if(i == s.length()) {
            System.out.println(curr);
            return;
        }
        genSub(s, i + 1, curr);
        genSub(s, i + 1, curr + s.charAt(i));
    }
}
