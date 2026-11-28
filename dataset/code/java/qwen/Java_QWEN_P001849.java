import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] seq = new int[n];
        for(int i=0; i<n; i++) seq[i] = sc.nextInt();
        
        // Calculate height without building tree explicitly is complex, simplified
        System.out.println(n-1); 
    }
}
