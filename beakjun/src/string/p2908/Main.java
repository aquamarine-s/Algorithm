package string.p2908;

import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	public static void main(String args[]){
		
		Scanner sc = new Scanner(System.in);
		StringTokenizer stok = new StringTokenizer(sc.nextLine(), " ");
		
		StringBuilder str1 = new StringBuilder(stok.nextToken());
		StringBuilder str2 = new StringBuilder(stok.nextToken());
		
		str1 = str1.reverse();
		str2 = str2.reverse();
		
		int n1 = Integer.parseInt(str1.toString());
		int n2 = Integer.parseInt(str2.toString());

		if(n1 > n2)
			System.out.println(n1);
		else
			System.out.println(n2);
		
	}
}
