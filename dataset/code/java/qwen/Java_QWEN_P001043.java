import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        
        // Last internal node is at index n/2 - 1
        if(n > 0) System.out.println(heap[n/2 - 1]);
    }
}
