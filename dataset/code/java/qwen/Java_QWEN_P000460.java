import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        int peak = 0;
        int low = 0, high = n - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] > arr[mid + 1]) high = mid;
            else low = mid + 1;
        }
        peak = low;
        
        low = 0; high = peak;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) { System.out.println(mid); return; }
            else if(arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        
        low = peak; high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) { System.out.println(mid); return; }
            else if(arr[mid] > target) low = mid + 1;
            else high = mid - 1;
        }
        System.out.println("-1");
    }
}
