import java.util.*;
public class Solution{
static boolean valid(String s){int c=0;for(char x:s.toCharArray()){if(x=='(')c++;else if(x==')')if(--c<0)return false;}return c==0;}
public static void main(String[]a){
    String s=new Scanner(System.in).next();
    Set<String>vis=new HashSet<>();Queue<String>q=new LinkedList<>();q.add(s);vis.add(s);
    List<String>res=new ArrayList<>();boolean found=false;
    while(!q.isEmpty()){
        String cur=q.poll();
        if(valid(cur)){res.add(cur);found=true;}
        if(found)continue;
        for(int i=0;i<cur.length();i++){
            if(cur.charAt(i)!='('&&cur.charAt(i)!=')')continue;
            String nxt=cur.substring(0,i)+cur.substring(i+1);
            if(!vis.contains(nxt)){vis.add(nxt);q.add(nxt);}
        }
    }
    for(String r:res)System.out.println(r);}}
