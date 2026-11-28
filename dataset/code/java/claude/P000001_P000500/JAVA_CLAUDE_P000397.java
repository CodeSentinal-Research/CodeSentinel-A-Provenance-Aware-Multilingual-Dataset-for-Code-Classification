import java.util.*;
public class Solution{public static void main(String[]a){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt(); sc.nextLine();
    String[] orders=new String[n];
    for(int i=0;i<n;i++) orders[i]=sc.nextLine().trim();
    String status=sc.nextLine().trim();
    boolean found=false;
    for(String o:orders){
        String[]f=o.split(" ");
        if(f.length>1 && f[1].equals(status)){System.out.println(o);found=true;}
    }
    if(!found) System.out.println("No Orders Found");
}}
