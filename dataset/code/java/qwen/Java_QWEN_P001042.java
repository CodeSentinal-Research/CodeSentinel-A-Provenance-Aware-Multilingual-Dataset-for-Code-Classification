import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        
        // Leaf nodes are from index n/2 to n-1
        for(int i=n/2; i<n; i++) System.out.print(heap[i] + " ");
    }
}
