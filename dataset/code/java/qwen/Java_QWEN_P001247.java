import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        int[] B = new int[n];
        for(int i=0; i<n; i++) A[i] = sc.nextInt();
        for(int i=0; i<n; i++) B[i] = sc.nextInt();
        
        Integer[] indices = new Integer[n];
        for(int i=0; i<n; i++) indices[i] = i;
        Arrays.sort(indices, (i, j) -> A[i] - A[j]);
        
        Arrays.sort(B);
        
        int[] res = new int[n];
        int j = 0;
        for(int i=0; i<n; i++) {
            if(A[indices[i]] > B[j]) {
                res[indices[i]] = B[j++];
            }
        }
        for(int i=0; i<n; i++) {
            if(res[indices[i]] == 0) {
                res[indices[i]] = B[j++];
            }
        }
        
        for(int x : res) System.out.print(x + " ");
    }
}
