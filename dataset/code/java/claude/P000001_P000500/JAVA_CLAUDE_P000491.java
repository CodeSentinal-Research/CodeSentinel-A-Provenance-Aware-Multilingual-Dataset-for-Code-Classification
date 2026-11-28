import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int m=sc.nextInt();int[]target=new int[m];for(int i=0;i<m;i++)target[i]=sc.nextInt();int n=sc.nextInt();int cur=1;for(int t:target){while(cur<t){System.out.println("Push");System.out.println("Pop");cur++;}System.out.println("Push");cur++;}}}
