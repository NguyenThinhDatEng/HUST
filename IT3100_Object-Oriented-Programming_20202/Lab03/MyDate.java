
import java.util.*;

public class MyDate {
	private int day;
	private int month;
	private int year;
	
	public MyDate() {
		super();
	}
	public MyDate(int day, int month, int year) {
		
		if (day > 0 && day < 32)
			this.day = day;
		else
			System.out.println("The day is invalid");
		
		if (month > 0 && month < 13)
			this.month = month;
		else
			System.out.println("The month is invalid");
		
		if (year >= 0)
			this.year = year;
		else
			System.out.println("The year is invalid");
	}
	
	public MyDate(String month_day_year) {
		SetCorresponding(month_day_year);
	}
	
	
	public void accept() {
		System.out.println("Enter a String which represents for a date, e.g. “February 18th 2019”: ");
		Scanner sc = new Scanner(System.in);
		String month_day_year = sc.nextLine();
		SetCorresponding(month_day_year);
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
	
	public void SetCorresponding(String month_day_year) {
		String[] tmp = month_day_year.split("\\s");	// we can use split(" ");
		String numberString = tmp[1];
		
		if (numberString.length() == 3)
			numberString = numberString.charAt(0) + "";
		else
			numberString = numberString.charAt(0)  + "" + numberString.charAt(1);
		
		day = Integer.parseInt(numberString);
		year = Integer.parseInt(tmp[2]);
		String month = tmp[0];
		
		switch (month) {
		case "January": {
				this.month = 1;
				break;
		}
		case "February": {
			this.month = 2;
			break;
		}
		case "March": {
			this.month = 3;
			break;
		}
		case "April": {
			this.month = 4;
			break;
		}
		case "May": {
			this.month = 5;
			break;
		}
		case "June": {
			this.month = 6;
			break;
		}
		case "July": {
			this.month = 7;
			break;
		}
		case "August": {
			this.month = 8;
			break;
		}
		case "September":{
			this.month = 9;
			break;
		}
		case "Octorber": {
			this.month = 10;
			break;
		}
		case "November": {
			this.month = 11;
			break;
		}
		case "December": {
			this.month = 12;
			break;
		}
		default:
			System.out.println("Input is not in the correct format \n e.g. “February 18th 2019”");
			break;
		}
	}
	
	public void print() {
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
