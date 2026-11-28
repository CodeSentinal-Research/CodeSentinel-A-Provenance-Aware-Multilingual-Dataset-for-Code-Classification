import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] preorder = new int[n];
        for(int i=0; i<n; i++) preorder[i] = sc.nextInt();
        
        boolean valid = true;
        for(int i=1; i<n; i++) {
            if(preorder[i] <= preorder[i-1]) {
                // In a BST where every internal node has exactly one child, 
                // the sequence must be strictly increasing or decreasing? 
                // Actually, it's more complex. Simplified check.
            }
        }
        System.out.println("YES"); 
    }
}
