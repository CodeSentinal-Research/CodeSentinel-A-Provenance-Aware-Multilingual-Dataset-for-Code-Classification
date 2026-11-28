import java.util.*;
public class Solution{public static void main(String[]a){
    String s=new Scanner(System.in).next();int cnt=0,opens=0;
    for(char c:s.toCharArray()){if(c=='[')opens++;else{if(opens>0)opens--;else cnt++;}}
    System.out.println((cnt+1)/2);}}
