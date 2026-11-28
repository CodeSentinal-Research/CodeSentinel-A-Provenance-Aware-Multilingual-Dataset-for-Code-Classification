import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        boolean upper = true, lower = true, mixed = false;
        for (char c : s.toCharArray()) {
            if (Character.isUpperCase(c)) lower = false;
            else if (Character.isLowerCase(c)) upper = false;
        }
        System.out.println(upper || lower || (s.length() == 1) ? "Yes" : "No");
    }
}
