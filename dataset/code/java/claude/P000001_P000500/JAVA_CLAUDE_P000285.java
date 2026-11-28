import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);String s1=sc.next(),s2=sc.next();int i=0;for(char c:s2.toCharArray())if(i<s1.length()&&c==s1.charAt(i))i++;System.out.println(i==s1.length()?"Yes":"No");}}
