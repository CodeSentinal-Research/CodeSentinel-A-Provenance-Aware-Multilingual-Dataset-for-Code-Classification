import java.util.*;
public class Solution{public static void main(String[]a){
    String s=new Scanner(System.in).next();
    Deque<String>strStk=new ArrayDeque<>();
    Deque<Integer>numStk=new ArrayDeque<>();
    StringBuilder cur=new StringBuilder();int num=0;
    for(char c:s.toCharArray()){
        if(Character.isDigit(c))num=num*10+(c-'0');
        else if(c=='['){strStk.push(cur.toString());numStk.push(num);cur=new StringBuilder();num=0;}
        else if(c==']'){int n=numStk.pop();String prev=strStk.pop();StringBuilder sb=new StringBuilder(prev);for(int i=0;i<n;i++)sb.append(cur);cur=sb;}
        else cur.append(c);
    }
    System.out.println(cur);
}}
