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
				//�������� ���� ���� ���ߴµ� �װ� �� ũ�� max�� ��ü 
				 temp_sum += arr[i];
				 max_sum = temp_sum;
			}		
			else{ // �������� ���� ���� ���ߴµ� ����� �� �۴�(���� ���� ������)
				if(arr[i] < 0) // ���� ���� ���� �̸� temp ���� �ʱ�ȭ
					temp_sum = 0;
				else
					temp_sum += arr[i];
			}
				
		}
		
		System.out.println(max_sum);
	}
}
