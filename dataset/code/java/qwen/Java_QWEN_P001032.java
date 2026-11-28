import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        int newVal = sc.nextInt();
        
        heap[0] = newVal;
        // Sink down for Min Heap
        sinkMin(heap, 0, n);
        
        for(int x : heap) System.out.print(x + " ");
    }
    static void sinkMin(int[] h, int i, int n) {
        while(true) {
            int smallest = i;
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n && h[l] < h[smallest]) smallest = l;
            if(r < n && h[r] < h[smallest]) smallest = r;
            if(smallest == i) break;
            swap(h, i, smallest);
            i = smallest;
        }
    }
    static void swap(int[] h, int i, int j) {
        int t = h[i]; h[i] = h[j]; h[j] = t;
    }
}
