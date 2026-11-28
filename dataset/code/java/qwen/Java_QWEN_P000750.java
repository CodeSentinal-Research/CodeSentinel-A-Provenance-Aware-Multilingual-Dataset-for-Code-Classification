import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        lexOrder(1, n);
    }
    static void lexOrder(int curr, int n) {
        if(curr > n) return;
        System.out.print(curr + " ");
        for(int i=0; i<=9; i++) {
            int next = curr * 10 + i;
            if(next > n) break;
            lexOrder(next, n);
        }
    }
}
