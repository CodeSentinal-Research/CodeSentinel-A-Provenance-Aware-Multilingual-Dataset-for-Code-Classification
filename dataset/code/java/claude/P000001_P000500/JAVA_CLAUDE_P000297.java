import java.util.*;
public class Solution{public static void main(String[]a){String s=new Scanner(System.in).next();Map<Character,Integer>m=Map.of('I',1,'V',5,'X',10,'L',50,'C',100,'D',500,'M',1000);int res=0;for(int i=0;i<s.length();i++){int v=m.get(s.charAt(i));if(i+1<s.length()&&v<m.get(s.charAt(i+1)))res-=v;else res+=v;}System.out.println(res);}}
