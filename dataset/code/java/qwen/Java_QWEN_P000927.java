import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String num = sc.next();
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        long decimal = Long.parseLong(num, a);
        System.out.println(Long.toString(decimal, b).toUpperCase());
    }
}
