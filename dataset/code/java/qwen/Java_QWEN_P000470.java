import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) { System.out.println(arr[mid]); return; }
            else if(arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        int res = arr[0];
        if(low < n && Math.abs(arr[low] - target) < Math.abs(res - target)) res = arr[low];
        if(high >= 0 && Math.abs(arr[high] - target) < Math.abs(res - target)) res = arr[high];
        System.out.println(res);
    }
}
