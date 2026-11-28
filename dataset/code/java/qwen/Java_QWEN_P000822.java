import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        int k = sc.nextInt();
        int x = sc.nextInt();
        
        int low = 0, high = n - k;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(x - arr[mid] > arr[mid + k] - x) low = mid + 1;
            else high = mid;
        }
        for(int i=low; i<low+k; i++) System.out.print(arr[i] + " ");
    }
}
