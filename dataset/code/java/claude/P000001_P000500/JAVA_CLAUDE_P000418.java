import java.util.*;
public class Solution{public static void main(String[]a){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt(); sc.nextLine();
    String[]recs=new String[n];
    for(int i=0;i<n;i++) recs[i]=sc.nextLine().trim();
    String cutoff=sc.nextLine().trim();
    boolean found=false;
    for(String r:recs){
        String[]f=r.split(" ");
        String date=f[f.length-1];
        if(date.compareTo(cutoff)<0){System.out.println(r);found=true;}
    }
    if(!found) System.out.println("No Employees Found");
}}
