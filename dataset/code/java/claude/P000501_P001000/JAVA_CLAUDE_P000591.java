import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();Set<Integer>sa=new HashSet<>();for(int i=0;i<n;i++)sa.add(sc.nextInt());
    int m=sc.nextInt();for(int i=0;i<m;i++){int v=sc.nextInt();if(sa.contains(v)){System.out.println(v);return;}}
    System.out.println("null");}}
