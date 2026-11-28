import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] h1 = new int[n];
        int[] h2 = new int[m];
        for(int i=0; i<n; i++) h1[i] = sc.nextInt();
        for(int i=0; i<m; i++) h2[i] = sc.nextInt();
        
        int[] merged = new int[n+m];
        System.arraycopy(h1, 0, merged, 0, n);
        System.arraycopy(h2, 0, merged, n, m);
        
        // Build Max Heap
        for(int i=(n+m)/2-1; i>=0; i--) sink(merged, i, n+m);
        
        for(int x : merged) System.out.print(x + " ");
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
