import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n+1];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        int val = sc.nextInt();
        
        heap[n] = val;
        // Swim up
        swim(heap, n);
        
        for(int i=0; i<=n; i++) System.out.print(heap[i] + " ");
    }
    static void swim(int[] h, int i) {
        while(i > 0) {
            int p = (i-1)/2;
            if(h[p] > h[i]) {
                swap(h, p, i);
                i = p;
            } else break;
        }
    }
    static void swap(int[] h, int i, int j) {
        int t = h[i]; h[i] = h[j]; h[j] = t;
    }
}
