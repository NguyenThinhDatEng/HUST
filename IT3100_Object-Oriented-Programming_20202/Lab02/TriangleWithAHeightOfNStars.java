package com.home.lab02;
import java.util.Scanner;

public class TriangleWithAHeightOfNStars {
	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		System.out.print("height = ");
		//input height
		int h = keyboard.nextInt();
		
		// declare variable odd that is the number of stars in a line
		int odd = 1;
		for (int i = h - 1; i >= 0; i--)
		{
			// insert spaces
			for (int j = 1; j <= i; j++)
			{
				System.out.print("   ");
			}
			// fill *
			for (int j = 1; j <= odd; j++)
			{
				System.out.print(" * ");
			}
			odd += 2;
			System.out.println("");
		}
	}
}
