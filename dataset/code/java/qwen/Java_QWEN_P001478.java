import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] A = new int[n][2];
        int[][] B = new int[m][2];
        for(int i=0; i<n; i++) { A[i][0] = sc.nextInt(); A[i][1] = sc.nextInt(); }
        for(int i=0; i<m; i++) { B[i][0] = sc.nextInt(); B[i][1] = sc.nextInt(); }
        
        List<int[]> res = new ArrayList<>();
        int i = 0, j = 0;
        while(i < n && j < m) {
            int start = Math.max(A[i][0], B[j][0]);
            int end = Math.min(A[i][1], B[j][1]);
            if(start <= end) {
                res.add(new int[]{start, end});
            }
            if(A[i][1] < B[j][1]) i++;
            else j++;
        }
        
        for(int[] interval : res) {
            System.out.println("[" + interval[0] + "," + interval[1] + "]");
        }
    }
}
