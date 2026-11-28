import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        System.out.println(kthSymbol(n, k));
    }
    static int kthSymbol(int n, int k) {
        if(n == 1) return 0;
        int half = 1 << (n - 2);
        if(k <= half) return kthSymbol(n - 1, k);
        else return 1 - kthSymbol(n - 1, k - half);
    }
}
