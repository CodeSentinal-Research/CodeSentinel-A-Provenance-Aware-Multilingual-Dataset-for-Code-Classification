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
        }
        
        // Check Max Heap
        boolean valid = true;
        for(int i=0; i<n; i++) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n && heap[l] > heap[i]) valid = false;
            if(r < n && heap[r] > heap[i]) valid = false;
        }
        System.out.println(valid ? "VALID" : "INVALID");
    }
}
