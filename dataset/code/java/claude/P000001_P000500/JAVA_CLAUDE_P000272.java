import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();String p=sc.next();for(int i=1;i<n;i++){String w=sc.next();while(!w.startsWith(p))p=p.substring(0,p.length()-1);}System.out.println(p);}}
