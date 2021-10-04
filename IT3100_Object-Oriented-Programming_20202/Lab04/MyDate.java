package com.home.lab04;
import java.util.*;

public class MyDate {
	
	private static int nbDay = 0;
	// declare attributes
	private int id = nbDay;
	private int day;
	private int month;
	private int year;
	// initialize convert object used to convert between integer type and string type of day, month, year
	private ConvertDayMonthYear convert = new ConvertDayMonthYear();
	
	// constructor
	public MyDate() {
		nbDay++;
	}
	
	public MyDate(String month_day_year) {
		setCorresponding(month_day_year);
		nbDay++;
	}
	
	public MyDate(String sDay, String sMonth, String sYear) {
		String month_day_year = sMonth + " " + sDay + " " + sYear;
		setCorresponding(month_day_year);
		nbDay++;
	}

	public MyDate(int day, int month, int year) {
			setDay(day);
			setMonth(month);
			setYear(year);
			nbDay++;
	}
	
	// setter and getter
	
	public int getId() {
		return id;
	}
	
	public int getDay() {
		return day;
	}

	public void setDay(int day) {
		if (day > 0 && day < 32)
			this.day = day;
		else
			System.out.println("The day is invalid");
	}
	public int getMonth() {
		return month;
	}
	public void setMonth(int month) {
		if (month > 0 && month < 13)
			this.month = month;
		else
			System.out.println("The month is invalid");
	}
	public int getYear() {
		return year;
	}
	public void setYear(int year) {
		if (year >= 0)
			this.year = year;
		else
			System.out.println("The year is invalid");
	}
	
	// require user to enter a string according in the format: Month day year
		public void accept() {
			System.out.println("Enter a String which represents for a date, e.g. “February 18th 2019”");
			Scanner sc = new Scanner(System.in);
			String month_day_year = sc.nextLine();
			setCorresponding(month_day_year);
		}
	
	// convert corresponding from String to Integer type of day, month, year
	public void setCorresponding(String month_day_year) {
		String[] tmp = month_day_year.split("\\s");	// we can use split(" ");
		String numberString = "";
		
		if (tmp[1].length() > 2)
		{
			numberString = tmp[1].substring(0, tmp[1].length() - 2);
		}
		else
		{
			numberString = tmp[1].substring(0);
		}
		
		day = Integer.parseInt(numberString);
		month = convert.MonthToInteger(tmp[0]);
		year = Integer.parseInt(tmp[2]);
	}
	
	// Format: Month Day Year E.g. January 18th 2020
	public void print() {
		String sDay = Integer.toString(day);
		String sMonth = convert.MonthToString(month);
		switch(day) {
			case 1: {
				sDay += "st";
				break;
			}
			case 2: {
				sDay += "nd";
				break;
			}
			case 3: {
				sDay += "rd";
				break;
			}
			default: {
				sDay += "th";
			}
		}
		System.out.print("Date " + id + ": ");
		System.out.println(sMonth + " " + sDay + " " + Integer.toString(year));
	}
	
	// Format: Day Month Year E.g. 01 01 1010
	public void show() {
		
		String date = "Date: ";
		if (day < 10) date += "0" + day + " ";
		else
			date += day + " ";
		if (month < 10) date += "0" + month + " ";
		else
			date += month + " ";
		date += year;
		System.out.println(date);
	}
	
}
