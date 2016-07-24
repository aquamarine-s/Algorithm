package math.p1978;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int arr_size = sc.nextInt();
		int arr[] = new int[arr_size];
		int cnt = 0;
		
		for(int i = 0; i < arr_size; i++){
			arr[i] = sc.nextInt();
			if(isPrime(arr[i]))
				cnt++;
		}
		
		System.out.println(cnt);
	}
	
	public static boolean isPrime(int n){
		
		if(n == 1)
			return false;
		else if(n == 2 || n == 3)
			return true;
		else if(n % 2 == 0 || n % 3 == 0)
			return false;
		else 
			return true;
	}
}



