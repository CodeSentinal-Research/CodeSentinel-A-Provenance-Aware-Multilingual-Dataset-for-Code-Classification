import java.util.*;
public class Solution{public static void main(String[]a){char[]s=new Scanner(System.in).next().toCharArray();String vow="aeiouAEIOU";int i=0,j=s.length-1;while(i<j){while(i<j&&vow.indexOf(s[i])<0)i++;while(i<j&&vow.indexOf(s[j])<0)j--;if(i<j){char t=s[i];s[i]=s[j];s[j]=t;i++;j--;}}System.out.println(new String(s));}}
