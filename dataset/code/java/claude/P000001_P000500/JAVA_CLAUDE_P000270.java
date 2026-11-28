import java.util.*;
public class Solution{public static void main(String[]a){String[]w=new Scanner(System.in).nextLine().trim().split(" ");StringBuilder sb=new StringBuilder();for(int i=0;i<w.length;i++){if(i>0)sb.append(" ");if(w[i].length()>0)sb.append(Character.toUpperCase(w[i].charAt(0))).append(w[i].substring(1).toLowerCase());}System.out.println(sb);}}
