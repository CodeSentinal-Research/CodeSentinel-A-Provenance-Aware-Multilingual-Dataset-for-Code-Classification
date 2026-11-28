import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();StringBuilder sb=new StringBuilder();for(int i=0;i<n;i++){int c=0;for(int j=i+1;j<n;j++)if(arr[j]<arr[i])c++;if(i>0)sb.append(' ');sb.append(c);}System.out.println(sb);}}
