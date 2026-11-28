import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();
Set<Integer>common=null;
for(int i=0;i<r;i++){Set<Integer>s=new HashSet<>();for(int j=0;j<c;j++)s.add(sc.nextInt());if(common==null)common=s;else common.retainAll(s);}
List<Integer>res=new ArrayList<>(common);Collections.sort(res);
StringJoiner sj=new StringJoiner(" ");for(int v:res)sj.add(String.valueOf(v));
System.out.println(sj);}}
