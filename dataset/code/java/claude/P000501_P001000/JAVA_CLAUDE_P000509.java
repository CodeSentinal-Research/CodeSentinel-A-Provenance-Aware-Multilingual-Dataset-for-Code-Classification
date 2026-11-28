import java.util.*;
public class Solution{public static void main(String[]a){
    String s=new Scanner(System.in).next();StringBuilder stk=new StringBuilder();
    for(char c:s.toCharArray()){
        if(Character.isDigit(c)){if(stk.length()>0&&!Character.isDigit(stk.charAt(stk.length()-1)))stk.deleteCharAt(stk.length()-1);}
        else stk.append(c);}
    System.out.println(stk);}}
