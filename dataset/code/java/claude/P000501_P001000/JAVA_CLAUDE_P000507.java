import java.util.*;
public class Solution{public static void main(String[]a){
    String[]nodes=new Scanner(System.in).nextLine().trim().split(",");int slots=1;
    for(String n:nodes){if(slots==0){System.out.println("false");return;}slots--;if(!n.equals("#"))slots+=2;}
    System.out.println(slots==0?"true":"false");}}
