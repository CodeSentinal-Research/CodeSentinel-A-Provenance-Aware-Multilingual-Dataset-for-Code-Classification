import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]arr=new int[n];for(int i=0;i<n;i++)arr[i]=sc.nextInt();int k=sc.nextInt();k%=n;
    Collections.rotate(Arrays.asList(Arrays.stream(arr).boxed().toArray(Integer[]::new)),k);
    // simple approach
    int[]res=new int[n];for(int i=0;i<n;i++)res[(i+k)%n]=arr[i];
    StringJoiner sj=new StringJoiner(" ");for(int v:res)sj.add(String.valueOf(v));System.out.println(sj);}}
