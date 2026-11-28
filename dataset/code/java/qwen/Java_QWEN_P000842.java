import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int index = sc.nextInt();
        int maxSum = sc.nextInt();
        
        int low = 1, high = maxSum;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long leftSum = getSum(mid - 1, Math.min(mid - 1, index));
            long rightSum = getSum(mid - 1, Math.min(mid - 1, n - 1 - index));
            if(leftSum + mid + rightSum <= maxSum) low = mid + 1;
            else high = mid - 1;
        }
        System.out.println(high);
    }
    static long getSum(int peak, int len) {
        if(len == 0) return 0;
        if(len >= peak) {
            return (long)peak * (peak + 1) / 2 + (len - peak);
        } else {
            return (long)peak * (peak + 1) / 2 - (long)(peak - len) * (peak - len + 1) / 2;
        }
    }
}
