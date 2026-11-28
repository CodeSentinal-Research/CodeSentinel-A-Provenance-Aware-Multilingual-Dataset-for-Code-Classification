import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] heap = new int[n];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        
        for(int k=0; k<q; k++) {
            int i = sc.nextInt();
            int val = sc.nextInt();
            heap[i] = val;
            // Restore heap property
            swim(heap, i);
            sink(heap, i, n);
        }
        
        for(int x : heap) System.out.print(x + " ");
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
