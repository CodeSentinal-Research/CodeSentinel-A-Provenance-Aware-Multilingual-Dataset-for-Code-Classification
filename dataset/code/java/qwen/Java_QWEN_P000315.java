import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int res = 0;
        for (char c : s.toCharArray()) {
            res = res * 26 + (c - 'A' + 1);
        }
        System.out.println(res);
    }
}
