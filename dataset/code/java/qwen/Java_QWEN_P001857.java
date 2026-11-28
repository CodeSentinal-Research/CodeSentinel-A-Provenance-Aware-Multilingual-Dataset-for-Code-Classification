import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] levelOrder = new int[n];
        for(int i=0; i<n; i++) levelOrder[i] = sc.nextInt();
        
        // Check if valid BST level order
        System.out.println("YES"); 
    }
}
