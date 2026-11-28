import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        // Stars and bars: C(n+4, 4)
        long res = 1;
        for(int i=1; i<=4; i++) {
            res = res * (n + 5 - i) / i;
        }
        System.out.println(res);
    }
}
