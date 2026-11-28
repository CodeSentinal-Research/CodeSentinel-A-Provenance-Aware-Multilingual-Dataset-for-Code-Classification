import java.util.*;
public class Solution{public static void main(String[]a){String w=new Scanner(System.in).next();boolean ok=w.equals(w.toUpperCase())||w.equals(w.toLowerCase())||(Character.isUpperCase(w.charAt(0))&&w.substring(1).equals(w.substring(1).toLowerCase()));System.out.println(ok?"Yes":"No");}}
