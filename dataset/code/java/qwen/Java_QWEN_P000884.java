import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if(n == 0) { System.out.println(0); return; }
        System.out.println(1 + (n - 1) % 9);
    }
}
