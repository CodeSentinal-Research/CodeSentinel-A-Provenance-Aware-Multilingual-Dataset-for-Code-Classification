import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt(),d=sc.nextInt();Set<Integer>s=new HashSet<>();int[]arr=new int[n];for(int i=0;i<n;i++){arr[i]=sc.nextInt();s.add(arr[i]);}for(int v:arr)if(d!=0&&s.contains(v+d)){System.out.println("Yes");return;}System.out.println("No");}}
