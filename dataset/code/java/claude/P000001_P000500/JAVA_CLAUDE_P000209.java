import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[][] A=new int[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) A[i][j]=sc.nextInt();
        for(int layer=0;layer<n/2;layer++){
            int first=layer,last=n-1-layer;
            for(int i=first;i<last;i++){
                int off=i-first,top=A[first][i];
                A[first][i]=A[last-off][first];
                A[last-off][first]=A[last][last-off];
                A[last][last-off]=A[first+off][last];
                A[first+off][last]=top;
            }
        }
        for(int i=0;i<n;i++){for(int j=0;j<n;j++) System.out.print(A[i][j]+(j<n-1?" ":"\n"));}
    }
}
