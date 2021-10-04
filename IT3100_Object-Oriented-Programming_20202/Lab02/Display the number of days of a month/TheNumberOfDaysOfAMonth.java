package com.home.lab02;

import java.util.Scanner;

public class TheNumberOfDaysOfAMonth {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		Month month = new Month();
		
		System.out.println("input month: ");
		month.setMonth(sc.next());
		System.out.println("input year: ");
		month.DaysOfMonth(sc.nextInt());
		
	}
}
