package com.home.lab02;

import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.Scanner;

public class SortSumAverageOfElements {
	public static void main(String[] args) {
		int sum = 0;		// sum of the all of elements in array
		int [] arr = {1789 , 2035, 1899, 1456, 2013};
		int option = JOptionPane.showConfirmDialog(null, "Do you want to enter data for the array?");
		// Yes = 0; No = 1; Cancel = 2
		if (option == 0) {
			Scanner sc = new Scanner(System.in);
			
			int n;		// length of array
			n = sc.nextInt();		// Initialize n
			
			arr = new int[n];		// declare array
			
			for (int i = 0; i < n; i++)		// Initialize array and calculate sum
			{
				arr[i] = sc.nextInt();
			}
				
		}
		for (int i = 0; i < arr.length; i++)
		{
			sum += arr[i];
		}
		for (int i = 0; i < arr.length - 1; i++)		// sort the array
			for (int j = i + 1; j < arr.length; j++)
				if (arr[j] < arr[i])
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
		System.out.println("Array after sort: ");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println("\nSUM = " + sum);
		System.out.println("AVERAGE = " + (double)sum / arr.length);
	}
}
