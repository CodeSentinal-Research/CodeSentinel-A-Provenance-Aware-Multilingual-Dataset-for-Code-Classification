import java.util.*;
public class Main {
    static int count;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        int target = sc.nextInt();
        count = 0;
        subSumCount(arr, 0, 0, target);
        System.out.println(count);
    }
    static void subSumCount(int[] arr, int i, int sum, int target) {
        if(i == arr.length) {
            if(sum == target) count++;
            return;
        }
        subSumCount(arr, i + 1, sum, target);
        subSumCount(arr, i + 1, sum + arr[i], target);
    }
}
