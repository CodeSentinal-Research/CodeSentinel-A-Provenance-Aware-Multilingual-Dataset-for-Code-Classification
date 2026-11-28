import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt(),n=sc.nextInt();
        int total=m+n;
        int[] merged=new int[total];
        for(int i=0;i<total;i++) merged[i]=sc.nextInt();
        Arrays.sort(merged);
        if(total%2==1) System.out.println(merged[total/2]);
        else{double med=(merged[total/2-1]+merged[total/2])/2.0;System.out.println(med==(int)med?(int)(med):med);}
    }
}
