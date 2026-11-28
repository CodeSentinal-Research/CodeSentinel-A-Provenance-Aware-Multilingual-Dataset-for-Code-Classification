import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();Set<Integer>s=new HashSet<>();for(int i=0;i<n;i++)s.add(sc.nextInt());int q=sc.nextInt();while(q-->0)System.out.println(s.contains(sc.nextInt())?"Found":"Not Found");}}
