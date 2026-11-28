import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int a = 0, l = 0;
        for (char c : s.toCharArray()) {
            if (c == 'A') a++;
            if (c == 'L') l++;
            else l = 0;
            if (a > 1 || l > 2) {
                System.out.println("No"); return;
            }
        }
        System.out.println("Yes");
    }
}
