import java.util.*;
public class Solution{public static void main(String[]a){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt(); sc.nextLine();
    String[] prods=new String[n];
    for(int i=0;i<n;i++) prods[i]=sc.nextLine().trim();
    String brand=sc.nextLine().trim();
    boolean found=false;
    for(String p:prods){
        String[]f=p.split(" ");
        if(f.length>1 && f[1].equals(brand)){System.out.println(p);found=true;}
    }
    if(!found) System.out.println("No Records Found");
}}
