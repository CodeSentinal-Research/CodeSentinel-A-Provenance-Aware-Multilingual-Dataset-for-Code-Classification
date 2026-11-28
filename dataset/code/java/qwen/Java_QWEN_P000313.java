import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        try {
            Double.parseDouble(s);
            System.out.println("Valid");
        } catch (Exception e) {
            System.out.println("Invalid");
        }
    }
}
