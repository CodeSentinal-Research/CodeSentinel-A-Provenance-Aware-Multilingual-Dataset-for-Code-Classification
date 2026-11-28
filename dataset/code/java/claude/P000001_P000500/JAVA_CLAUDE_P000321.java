import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);int n=sc.nextInt();sc.nextLine();String[]rows={"qwertyuiop","asdfghjkl","zxcvbnm"};while(n-->0){String w=sc.nextLine().trim();for(String r:rows){boolean ok=true;for(char c:w.toLowerCase().toCharArray())if(r.indexOf(c)<0){ok=false;break;}if(ok){System.out.println(w);break;}}}}};
