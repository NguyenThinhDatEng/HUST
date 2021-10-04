package com.home.lab02;

public class Month {
	private String month;

	public String getMonth() {
		return month;
	}

	public void setMonth(String month) {
		this.month = month;
	}
	
	public void DaysOfMonth(int year){
		switch (month) {
		case "January": {}
		case "Jan": {}
		case "Jan.": {}
		case "1": {
			System.out.println("January has 31 Days");
			break;
		}
		case "Februnary":{}
		case "Feb": {}
		case "Feb.": {}
		case "2": {
			if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
				System.out.println("Februnary has 29 days");
			else
				System.out.println("Februnary has 28 days");
			break;
		}
		case "March": {}
		case "Mar": {}
		case "Mar.": {}
		case "3": {
			System.out.println("March has 31 days");
			break;
		}
		case "April": {}
		case "Apr": {}
		case "Apr.": {}
		case "4": {
			System.out.println("April has 30 days");
			break;
		}
		case "May": {}
		case "5": {
			System.out.println("May has 31 days");
			break;
		}
		case "June": {}
		case "Jun": {}
		case "6": {
			System.out.println("June has 30 days");
			break;
		}
		case "July":{}
		case "Jul":{}
		case "7": {
			System.out.println("July has 31 days");
			break;
		}
		case "August":{}
		case "Aug":{}
		case "Aug.":{}
		case "8": {
			System.out.println("August has 31 days");
			break;
		}
		case "September":{}
		case "Sep":{}
		case "Sep.":{}
		case "9": {
			System.out.println("September has 30 days");
			break;
		}
		case "October": {}
		case "Oct": {}
		case "Oct.": {}
		case "10": {
			System.out.println("October has 31 days");
			break;
		}
		case "November":{}
		case "Nov.": {}
		case "Nov": {}
		case "11": {
			System.out.println("November has 30 days");
			break;
		}
		case "December":{}
		case "Dec": {}
		case "Dec.": {}
		case "12": {
			System.out.println("December has 31 days");
			break;
		}
		default:
			System.out.println("Input month is invalid");
					break;
		}
	}
}
