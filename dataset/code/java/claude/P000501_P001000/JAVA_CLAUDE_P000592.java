import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();List<Integer>lst=new ArrayList<>();for(int i=0;i<n;i++)lst.add(sc.nextInt());int val=sc.nextInt();
    lst.removeIf(v->v==val);StringJoiner sj=new StringJoiner(" ");for(int v:lst)sj.add(String.valueOf(v));System.out.println(sj);}}
