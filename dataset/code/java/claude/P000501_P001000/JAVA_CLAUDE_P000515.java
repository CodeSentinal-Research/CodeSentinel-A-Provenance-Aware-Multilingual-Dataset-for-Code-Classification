import java.util.*;
public class Solution{public static void main(String[]a){
    String s=new Scanner(System.in).nextLine();int d=0,mx=0;
    for(char c:s.toCharArray()){if(c=='('){d++;mx=Math.max(mx,d);}else if(c==')')d--;}
    System.out.println(mx);}}
