import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] merged=new int[2*n];
        for(int i=0;i<2*n;i++) merged[i]=sc.nextInt();
        Arrays.sort(merged);
        double med=(merged[n-1]+merged[n])/2.0;
        System.out.println(med==(int)med?(int)med:med);
    }
}
