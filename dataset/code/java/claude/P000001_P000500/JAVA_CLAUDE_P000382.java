import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();sc.nextLine();String[]recs=new String[n];for(int i=0;i<n;i++)recs[i]=sc.nextLine().trim();String q=sc.nextLine().trim();for(String r:recs){String[]f=r.split(" ");if(f.length>0&&f[0].equals(q)){System.out.println(r);return;}}System.out.println("User Not Found");}}
