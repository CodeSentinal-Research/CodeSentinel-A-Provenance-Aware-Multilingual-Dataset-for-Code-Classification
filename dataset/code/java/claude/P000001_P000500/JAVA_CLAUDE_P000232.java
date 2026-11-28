import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt();
int[]a=new int[r*c];for(int i=0;i<r*c;i++)a[i]=sc.nextInt();
Arrays.sort(a);System.out.println(a[(r*c)/2]);}}
