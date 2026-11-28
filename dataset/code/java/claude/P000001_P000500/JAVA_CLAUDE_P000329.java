import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);String s=sc.next(),t=sc.next();int diff=0;for(char c:s.toCharArray())diff^=c;for(char c:t.toCharArray())diff^=c;System.out.println((char)diff);}}
