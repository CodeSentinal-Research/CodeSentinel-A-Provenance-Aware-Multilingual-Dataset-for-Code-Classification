import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        
        // Replace root with last element
        heap[0] = heap[n-1];
        // Sink down
        sink(heap, 0, n-1);
        
        for(int i=0; i<n-1; i++) System.out.print(heap[i] + " ");
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
