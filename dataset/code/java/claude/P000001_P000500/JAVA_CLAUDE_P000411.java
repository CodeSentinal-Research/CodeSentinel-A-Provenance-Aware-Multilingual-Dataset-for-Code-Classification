import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();sc.nextLine();String[]recs=new String[n];for(int i=0;i<n;i++)recs[i]=sc.nextLine();String kw=sc.nextLine().trim();boolean found=false;for(String r:recs)if(r.contains(kw)){System.out.println(r);found=true;}if(!found)System.out.println("No Records Found");}}
