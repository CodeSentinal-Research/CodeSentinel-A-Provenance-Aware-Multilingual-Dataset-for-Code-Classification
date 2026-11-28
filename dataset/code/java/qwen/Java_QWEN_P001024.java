import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        int i = sc.nextInt();
        
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        System.out.print((left < n ? heap[left] : -1) + " ");
        System.out.println(right < n ? heap[right] : -1);
    }
}
