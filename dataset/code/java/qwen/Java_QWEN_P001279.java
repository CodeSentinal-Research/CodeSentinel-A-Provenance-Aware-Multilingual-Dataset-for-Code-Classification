import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        char[] res = new char[n];
        Arrays.fill(res, 'a');
        k -= n;
        
        for(int i=n-1; i>=0; i--) {
            int add = Math.min(25, k);
            res[i] += add;
            k -= add;
        }
        System.out.println(new String(res));
    }
}
