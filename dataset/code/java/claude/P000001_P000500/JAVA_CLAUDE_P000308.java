import java.util.*;
public class Solution{
static List<Integer>ways(String s){
    List<Integer>res=new ArrayList<>();
    for(int i=0;i<s.length();i++){
        char c=s.charAt(i);
        if(c!='+'&&c!='-'&&c!='*')continue;
        for(int l:ways(s.substring(0,i)))for(int r:ways(s.substring(i+1))){
            if(c=='+')res.add(l+r);else if(c=='-')res.add(l-r);else res.add(l*r);
        }
    }
    if(res.isEmpty())res.add(Integer.parseInt(s));
    return res;
}
public static void main(String[]a){String e=new Scanner(System.in).next();List<Integer>v=ways(e);Collections.sort(v);StringJoiner sj=new StringJoiner(" ");for(int x:v)sj.add(String.valueOf(x));System.out.println(sj);}}
