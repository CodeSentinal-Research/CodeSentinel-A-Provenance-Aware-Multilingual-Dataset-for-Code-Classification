import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        int i = sc.nextInt();
        int newVal = sc.nextInt();
        
        heap[i] = newVal;
        // Swim up for Max Heap
        while(i > 0) {
            int p = (i-1)/2;
            if(heap[p] < heap[i]) {
                swap(heap, p, i);
                i = p;
            } else break;
        }
        
        for(int x : heap) System.out.print(x + " ");
    }
    static void swap(int[] h, int i, int j) {
        int t = h[i]; h[i] = h[j]; h[j] = t;
    }
}
