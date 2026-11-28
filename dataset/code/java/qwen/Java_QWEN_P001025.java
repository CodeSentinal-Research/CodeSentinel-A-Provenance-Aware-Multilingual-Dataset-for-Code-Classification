import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        
        // Internal nodes = N - Leaves
        long leaves = (n + 1) / 2;
        System.out.println(n - leaves);
    }
}
