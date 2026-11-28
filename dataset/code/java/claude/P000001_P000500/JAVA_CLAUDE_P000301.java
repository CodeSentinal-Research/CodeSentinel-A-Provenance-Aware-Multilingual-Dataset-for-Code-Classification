import java.util.*;
public class Solution{
static String s;static List<String>res=new ArrayList<>();
static void bt(int i,List<String>parts){
    if(parts.size()==4){if(i==s.length())res.add(String.join(".",parts));return;}
    for(int l=1;l<=3&&i+l<=s.length();l++){
        String seg=s.substring(i,i+l);
        if(seg.charAt(0)=='0'&&l>1)break;
        if(Integer.parseInt(seg)>255)break;
        parts.add(seg);bt(i+l,parts);parts.remove(parts.size()-1);
    }
}
public static void main(String[]a){s=new Scanner(System.in).next();List<String>p=new ArrayList<>();bt(0,p);for(String r:res)System.out.println(r);}}
