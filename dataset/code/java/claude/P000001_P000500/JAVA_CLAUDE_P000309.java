import java.util.*;
public class Solution{public static void main(String[]a){
    Scanner sc=new Scanner(System.in);String s1=sc.next(),s2=sc.next();
    int m=s1.length(),n=s2.length();int[]pos=new int[m+n];
    for(int i=m-1;i>=0;i--)for(int j=n-1;j>=0;j--){
        int mul=(s1.charAt(i)-'0')*(s2.charAt(j)-'0'),p1=i+j,p2=i+j+1,tot=mul+pos[p2];
        pos[p2]=tot%10;pos[p1]+=tot/10;
    }
    StringBuilder sb=new StringBuilder();boolean lead=true;
    for(int x:pos){if(lead&&x==0)continue;lead=false;sb.append(x);}
    System.out.println(sb.length()==0?"0":sb);}}
