import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        int target = sc.nextInt();
        
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) { System.out.println("true"); return; }
            if(arr[low] == arr[mid] && arr[mid] == arr[high]) { low++; high--; }
            else if(arr[low] <= arr[mid]) {
                if(arr[low] <= target && target < arr[mid]) high = mid - 1;
                else low = mid + 1;
            } else {
                if(arr[mid] < target && target <= arr[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        System.out.println("false");
    }
}
