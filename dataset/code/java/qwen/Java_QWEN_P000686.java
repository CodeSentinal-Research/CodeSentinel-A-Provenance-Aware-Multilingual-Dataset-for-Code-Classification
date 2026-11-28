import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(reverseStr(s));
    }
    static String reverseStr(String s) {
        if(s.length() <= 1) return s;
        return reverseStr(s.substring(1)) + s.charAt(0);
    }
}
