import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(numTrees(n));
    }
    static long numTrees(int n) {
        if(n <= 1) return 1;
        long res = 0;
        for(int i=1; i<=n; i++) {
            res += numTrees(i-1) * numTrees(n-i);
        }
        return res;
    }
}
