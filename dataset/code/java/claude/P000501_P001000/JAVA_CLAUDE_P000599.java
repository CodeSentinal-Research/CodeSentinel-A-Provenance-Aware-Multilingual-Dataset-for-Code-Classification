import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];Map<Integer,Integer>cnt=new LinkedHashMap<>();
    for(int i=0;i<n;i++){arr[i]=sc.nextInt();cnt.merge(arr[i],1,Integer::sum);}
    StringJoiner sj=new StringJoiner(" ");for(int v:arr)if(cnt.get(v)==1)sj.add(String.valueOf(v));
    System.out.println(sj.toString().isEmpty()?"":sj);}}
