import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int sum = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
       }
       
        int[] result = subarraySum(arr, n, sum);
        if(result[0] == -1)
            System.out.println("-1");
        else
            System.out.println((result[0]+1) + " " + (result[1]+1));
    }
    
    static int[] subarraySum(int[] arr, int n, int sum) {
        int curr_sum = arr[0], start = 0, i;
        for (i = 1; i <= n; i++) {
            while (curr_sum > sum && start < i - 1) {
                curr_sum = curr_sum - arr[start];
                start++;
            }
            if (curr_sum == sum) {
                int[] res = {start, i - 1};
                return res;
            }
            if (i < n)
                curr_sum = curr_sum + arr[i];
        }
        int[] res = {-1, -1};
        return res;
    }
}
