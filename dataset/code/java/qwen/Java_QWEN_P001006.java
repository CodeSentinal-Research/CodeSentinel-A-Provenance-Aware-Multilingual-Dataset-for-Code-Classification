import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        boolean isMinHeap = true;
        for(int i=0; i<n; i++) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            if(left < n && arr[left] < arr[i]) isMinHeap = false;
            if(right < n && arr[right] < arr[i]) isMinHeap = false;
        }
        System.out.println(isMinHeap ? "YES" : "NO");
    }
}
