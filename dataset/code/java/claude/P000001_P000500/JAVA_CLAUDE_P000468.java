import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int m=sc.nextInt(),n=sc.nextInt(),k=sc.nextInt();int[]c=new int[m+n];for(int i=0;i<m+n;i++)c[i]=sc.nextInt();Arrays.sort(c);System.out.println(c[k-1]);}}
