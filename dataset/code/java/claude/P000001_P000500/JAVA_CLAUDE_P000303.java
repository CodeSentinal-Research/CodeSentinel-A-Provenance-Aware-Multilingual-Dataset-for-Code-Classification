import java.util.*;
public class Solution{
static String s;static Set<String>ws;static List<String>res=new ArrayList<>();
static void bt(int i,String path){
    if(i==s.length()){res.add(path);return;}
    for(int j=i+1;j<=s.length();j++){String w=s.substring(i,j);if(ws.contains(w))bt(j,path.isEmpty()?w:path+" "+w);}
}
public static void main(String[]a){Scanner sc=new Scanner(System.in);s=sc.nextLine().trim();ws=new HashSet<>(Arrays.asList(sc.nextLine().trim().split(" ")));bt(0,"");for(String r:res)System.out.println(r);}}
