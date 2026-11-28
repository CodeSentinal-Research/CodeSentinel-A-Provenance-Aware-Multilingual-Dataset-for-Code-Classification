import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();sc.nextLine();boolean found=false;for(int i=0;i<n;i++){String r=sc.nextLine().trim();if(r.toLowerCase().contains("available")){System.out.println(r);found=true;}}if(!found)System.out.println("No Records Found");}}
