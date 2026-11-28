import java.util.*;
public class Solution{public static void main(String[]a){int n=new Scanner(System.in).nextInt();int[]v={1000,900,500,400,100,90,50,40,10,9,5,4,1};String[]s={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};StringBuilder sb=new StringBuilder();for(int i=0;i<13;i++)while(n>=v[i]){sb.append(s[i]);n-=v[i];}System.out.println(sb);}}
