import java.util.*;
public class Solution{public static void main(String[]a){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt(); sc.nextLine();
    String[] vehicles=new String[n];
    for(int i=0;i<n;i++) vehicles[i]=sc.nextLine().trim();
    String mfr=sc.nextLine().trim();
    boolean found=false;
    for(String v:vehicles){
        String[]f=v.split(" ");
        if(f.length>1 && f[1].equals(mfr)){System.out.println(v);found=true;}
    }
    if(!found) System.out.println("No Records Found");
}}
