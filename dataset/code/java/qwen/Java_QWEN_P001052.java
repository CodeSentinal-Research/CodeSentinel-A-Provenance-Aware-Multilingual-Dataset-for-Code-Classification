import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        boolean isMaxHeap = true;
        for(int i=0; i<n; i++) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n && arr[l] > arr[i]) isMaxHeap = false;
            if(r < n && arr[r] > arr[i]) isMaxHeap = false;
        }
        System.out.println(isMaxHeap ? "YES" : "NO");
    }
}
