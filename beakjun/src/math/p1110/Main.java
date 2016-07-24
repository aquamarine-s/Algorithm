package math.p1110;

import java.util.Scanner;

public class Main {
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		plus(n, n, 1);
		//System.out.println(plus2(n,n,0));
	}
	
	static public void plus(int n, int orgin, int cnt){
		int n10,n1,new_n;
		
		n10 = n / 10;
		n1  = n % 10;
		
		new_n = (n10+n1)%10;
		
		int new_int = n1*10 + new_n;
		//System.out.println("새로 만들어진 숫자 : " + new_int);
		
		
		int tmp = ((n / 10 + n % 10)%10) + (10 * (n%10));
		
		if(tmp==orgin)
			System.out.println(cnt);
		else{
			cnt++;
			plus(tmp, orgin, cnt);	
		}
	}
	
	static public int plus2(int first, int number, int cnt){
		int tmp;
		cnt++;
		tmp = ((number / 10 + number % 10)%10) + (10 * (number%10));
		if (tmp != first) 
			plus2(first, tmp, cnt);
		return cnt;			
	}
}


