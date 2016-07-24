package sort.p2866;

import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int r, c;
		StringBuilder arr[];
		char arr2[][];
		int count = 0;
		
		r = sc.nextInt();
		c = sc.nextInt();
		sc.nextLine();
		
		
		arr = new StringBuilder[c];
		arr2 = new char[r][c];
		
		for(int i = 0 ; i < r; i++){
			arr2[i] = sc.nextLine().toCharArray();
			//System.out.println(arr2[i]);
			
/*			for(int j = 0 ; j < c; j++){
				System.out.print(arr2[i][j]);
			}
			System.out.println();
*/		}
		
		for(int i = 0 ; i < c; i++){
			arr[i] = new StringBuilder();
		}
		
		for(int i = 0 ; i < r; i++){
			for(int j = 0 ; j < c; j++){
				arr[j].append(arr2[i][j]);
			}
		}
		System.out.println("---생성된 문자열----");
		for(int i = 0 ; i < c; i++){
			System.out.println(arr[i].toString());
		}
		System.out.println("----------------");
		
		for(int i = 0 ; i < c; i++){
			if(isDuplicate(arr, count))
				break;
			else
				count++;
		}
		System.out.println(count);
		
	}

	public static boolean isDuplicate(StringBuilder[] sb, int count){
		int arr_count = sb.length; // 배열 갯수
		int string_count = sb[0].length(); // 문자 길이
		
		for(int i = 0 ; i < arr_count ; i++){
			
			String temp = sb[i].substring(count+1, string_count);
			System.out.println("검사할 문자열 : " + temp);
			
			for(int j = i+1; j < arr_count; j++){
				
				if(temp.equals(sb[j].substring(count+1, string_count))){
					System.out.println("ture");
					return true;
				}
			}
		}
		System.out.println("false");
		return false;
	}
}
