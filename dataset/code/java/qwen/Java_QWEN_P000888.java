import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long sq = n * n;
        String sN = String.valueOf(n);
        String sSq = String.valueOf(sq);
        System.out.println(sSq.endsWith(sN) ? "true" : "false");
    }
}
