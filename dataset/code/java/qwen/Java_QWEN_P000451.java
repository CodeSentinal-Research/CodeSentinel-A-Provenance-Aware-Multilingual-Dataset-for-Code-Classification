import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int target = sc.nextInt();
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        if(target < arr[0]) { System.out.println("0"); return; }
        int low = 0, high = 1;
        while(high < n && arr[high] < target) {
            low = high;
            high *= 2;
        }
        if(high >= n) high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == target) { System.out.println(mid); return; }
            else if(arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        System.out.println("-1");
    }
}
