package string.p2684;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] reader=new String[2];
        try {
			reader=br.readLine().split(" ");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int for_min1 = Integer.parseInt(reader[0].replaceAll("6", "5"));
		int for_min2 = Integer.parseInt(reader[1].replaceAll("6", "5"));
		
		int for_max1 = Integer.parseInt(reader[0].replaceAll("5", "6"));
		int for_max2 = Integer.parseInt(reader[1].replaceAll("5", "6"));
		
		System.out.println((for_min1 + for_min2) + " " + (for_max1 + for_max2));
		
	}
}
