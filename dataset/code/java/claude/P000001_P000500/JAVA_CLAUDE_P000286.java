import java.util.*;
public class Solution{public static void main(String[]a){char[]s=new Scanner(System.in).next().toCharArray();int i=0,j=s.length-1;while(i<j){while(i<j&&!Character.isLetter(s[i]))i++;while(i<j&&!Character.isLetter(s[j]))j--;if(i<j){char t=s[i];s[i]=s[j];s[j]=t;i++;j--;}}System.out.println(new String(s));}}
