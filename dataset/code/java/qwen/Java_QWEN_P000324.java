import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String doubled = s + s;
        if (doubled.substring(1, doubled.length() - 1).contains(s)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
