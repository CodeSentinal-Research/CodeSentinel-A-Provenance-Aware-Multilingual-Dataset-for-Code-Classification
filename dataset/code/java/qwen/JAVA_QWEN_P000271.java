import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        
        if (s1.length() != s2.length()) {
            System.out.println("No");
            return;
        }
        
        String combined = s1 + s1;
        System.out.println(combined.contains(s2) ? "Yes" : "No");
    }
}
