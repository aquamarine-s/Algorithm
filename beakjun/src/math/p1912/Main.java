package math.p1912;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int arr_size = sc.nextInt();
		int arr[] = new int[arr_size];
		
		int max_sum = 0;
		int temp_sum = 0;
		
		for(int i = 0 ; i < arr_size; i++){			
			arr[i] = sc.nextInt();
		}
		
		
		
		
		
		max_sum = arr[0];
		temp_sum = arr[0];
		
		for(int i = 1 ; i < arr_size; i++){
			
			if(temp_sum + arr[i] > max_sum){
				//누적값에 다음 것을 더했는데 그게 더 크면 max를 교체 
				 temp_sum += arr[i];
				 max_sum = temp_sum;
			}		
			else{ // 누적값에 다음 것으 더했는데 결과가 더 작다(더한 값은 음수다)
				if(arr[i] < 0) // 다음 것이 음수 이면 temp 값을 초기화
					temp_sum = 0;
				else
					temp_sum += arr[i];
			}
				
		}
		
		System.out.println(max_sum);
	}
}
