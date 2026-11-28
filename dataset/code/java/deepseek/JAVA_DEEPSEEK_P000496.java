import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(br.readLine());
        String[] arrStr = br.readLine().split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(arrStr[i]);
        }
        pw.println(sumSubarrayMins(arr));
        pw.flush();
    }

    public static int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int mod = (int)1e9+7;
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        long res = 0;
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            while (!s1.isEmpty() && arr[s1.peek()] > arr[i]) {
                s1.pop();
            }
            dp[i] = s1.isEmpty() ? i + 1 : i - s1.peek();
            s1.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s2.isEmpty() && arr[s2.peek()] >= arr[i]) {
                s2.pop();
            }
            res = (res + (long)dp[i] * (s2.isEmpty() ? n - i : s2.peek() - i) * arr[i]) % mod;
            s2.push(i);
        }
        return (int)res;
    }
}
