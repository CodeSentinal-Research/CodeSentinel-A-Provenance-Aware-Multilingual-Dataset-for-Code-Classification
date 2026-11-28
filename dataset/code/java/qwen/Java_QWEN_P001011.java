import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        // Heap Sort
        for(int i=n/2-1; i>=0; i--) sink(arr, i, n);
        
        for(int i=n-1; i>0; i--) {
            swap(arr, 0, i);
            sink(arr, 0, i);
        }
        
        for(int x : arr) System.out.print(x + " ");
    }
    static void sink(int[] h, int i, int n) {
        while(true) {
            int largest = i;
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n && h[l] > h[largest]) largest = l;
            if(r < n && h[r] > h[largest]) largest = r;
            if(largest == i) break;
            swap(h, i, largest);
            i = largest;
        }
    }
    static void swap(int[] h, int i, int j) {
        int t = h[i]; h[i] = h[j]; h[j] = t;
    }
}
