import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        long MOD = 1000000007;
        long res = 0;
        Stack<int[]> stack = new Stack<>();
        for(int i=0; i<n; i++) {
            int count = 1;
            while(!stack.isEmpty() && stack.peek()[0] >= arr[i]) {
                int[] top = stack.pop();
                count += top[1];
                res = (res - (long)top[0] * top[1] % MOD + MOD) % MOD;
            }
            stack.push(new int[]{arr[i], count});
            res = (res + (long)arr[i] * count % MOD) % MOD;
        }
        System.out.println(res);
    }
}
