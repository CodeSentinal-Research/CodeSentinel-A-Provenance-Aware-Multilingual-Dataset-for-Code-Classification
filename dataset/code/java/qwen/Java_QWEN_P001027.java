import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        
        int level = 0;
        int count = 1;
        int idx = 0;
        while(idx < n) {
            for(int i=0; i<count && idx < n; i++) {
                System.out.print(heap[idx++] + " ");
            }
            System.out.println();
            count *= 2;
        }
    }
}
