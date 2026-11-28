import java.util.*;
public class Solution{public static void main(String[]a){
    String s=new Scanner(System.in).next();int opens=0,closes=0;
    for(char c:s.toCharArray()){if(c=='(')opens++;else{if(opens>0)opens--;else closes++;}}
    System.out.println(opens+closes);}}
