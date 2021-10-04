package com.home.lab04;

import java.util.*;

public class DateTest {
	public static void main(String[] args) {
		
		MyDate date = new MyDate("January 4th 2019");
		MyDate date01 = new MyDate("4", "May", "2021");
		MyDate date02 = new MyDate();
		MyDate date03 = new MyDate();
		DateUtils dateUtil = new DateUtils();
		ArrayList<MyDate> dates = new ArrayList<MyDate>(Arrays.asList(date, date01));
		
		date.print();
		date01.print();
		
		date02.setDay(22);
		date02.setMonth(12);
		date02.setYear(2020);
		date02.print();
		
		date03.accept();
		date03.print();
		
		System.out.println(dateUtil.compareTwoDates(date02, date));
		
		dates.add(date02);
		dates.add(date03);
		
		DateUtils.sortingANumberOfDates(dates);
		
		for (MyDate myDate : dates) {
			myDate.print();
		}
	}
}