import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n];
        for(int i=0; i<n; i++) heap[i] = sc.nextInt();
        int i = sc.nextInt();
        
        // Level is floor(log2(i+1))
        int level = (int)(Math.log(i+1) / Math.log(2));
        System.out.println(level);
    }
}
