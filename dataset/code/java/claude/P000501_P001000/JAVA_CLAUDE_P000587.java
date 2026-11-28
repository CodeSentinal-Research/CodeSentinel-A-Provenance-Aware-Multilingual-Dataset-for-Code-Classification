import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int k=sc.nextInt();List<Integer>all=new ArrayList<>();
    for(int i=0;i<k;i++){int sz=sc.nextInt();for(int j=0;j<sz;j++)all.add(sc.nextInt());}
    Collections.sort(all);StringJoiner sj=new StringJoiner(" ");for(int v:all)sj.add(String.valueOf(v));System.out.println(sj);}}
