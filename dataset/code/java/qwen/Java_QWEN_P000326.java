import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        if (s.isEmpty()) {
            System.out.println(0); return;
        }
        String[] parts = s.trim().split("\\s+");
        System.out.println(parts.length);
    }
}
