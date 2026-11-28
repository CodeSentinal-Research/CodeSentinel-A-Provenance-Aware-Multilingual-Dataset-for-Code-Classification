import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int sz=sc.nextInt();List<Integer>lst=new ArrayList<>();for(int i=0;i<sz;i++)lst.add(sc.nextInt());int n=sc.nextInt();
    lst.remove(sz-n);StringJoiner sj=new StringJoiner(" ");for(int v:lst)sj.add(String.valueOf(v));System.out.println(sj);}}
