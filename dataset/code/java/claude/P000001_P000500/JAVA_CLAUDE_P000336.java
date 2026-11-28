import java.util.*;
public class Solution{
static boolean palin(char[]s,int l,int r){while(l<r)if(s[l++]!=s[r--])return false;return true;}
static boolean check(String a,String b){char[]ca=a.toCharArray(),cb=b.toCharArray();int i=0,j=a.length()-1;while(i<j&&ca[i]==cb[j]){i++;j--;}return palin(ca,i,j)||palin(cb,i,j);}
public static void main(String[]a){Scanner sc=new Scanner(System.in);String s1=sc.next(),s2=sc.next();System.out.println(check(s1,s2)||check(s2,s1)?"Yes":"No");}}
