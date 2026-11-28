import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        
        int root = heap[0];
        int count = 0;
        for(int x : heap) {
            if(x > root) count++;
        }
        System.out.println(count);
    }
}
