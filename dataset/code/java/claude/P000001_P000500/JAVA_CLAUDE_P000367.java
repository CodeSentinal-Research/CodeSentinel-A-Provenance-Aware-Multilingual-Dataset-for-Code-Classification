import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();sc.nextLine();int mi=0,ml=Integer.MAX_VALUE;for(int i=0;i<n;i++){String w=sc.nextLine().trim();if(w.length()<ml){ml=w.length();mi=i;}}System.out.println(mi);}}
