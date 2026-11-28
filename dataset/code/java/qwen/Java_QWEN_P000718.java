import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        grayCode(n, 0, 0);
    }
    static void grayCode(int n, int idx, int num) {
        if(idx == n) {
            System.out.println(num);
            return;
        }
        grayCode(n, idx + 1, num);
        grayCode(n, idx + 1, num ^ (1 << idx));
    }
}
