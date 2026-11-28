import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();String[]words=new String[n];for(int i=0;i<n;i++)words[i]=sc.next();String s=sc.next();int cnt=0;for(String w:words)if(s.startsWith(w))cnt++;System.out.println(cnt);}}
