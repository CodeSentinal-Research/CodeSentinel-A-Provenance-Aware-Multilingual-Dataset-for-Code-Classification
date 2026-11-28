import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        int i = sc.nextInt();
        
        // Swap with last, remove, then heapify
        heap[i] = heap[n-1];
        // Sink or Swim
        sink(heap, i, n-1);
        swim(heap, i);
        
        for(int j=0; j<n-1; j++) System.out.print(heap[j] + " ");
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
    static void swim(int[] h, int i) {
        while(i > 0) {
            int p = (i-1)/2;
            if(h[p] < h[i]) {
                swap(h, p, i);
                i = p;
            } else break;
        }
    }
    static void swap(int[] h, int i, int j) {
        int t = h[i]; h[i] = h[j]; h[j] = t;
    }
}
