package com.home.lab04;

public class ConvertDayMonthYear {
	public int MonthToInteger(String sMonth)
	{
		int month = 0;
		switch (sMonth) {
			case "January": {
				month = 1;
				break;
			}
			case "February": {
				month = 2;
				break;
			}
			case "March": {
				month = 3;
				break;
			}
			case "April": {
				month = 4;
				break;
			}
			case "May": {
				month = 5;
				break;
			}
			case "June": {
				month = 6;
				break;
			}
			case "July": {
				month = 7;
				break;
			}
			case "August": {
				month = 8;
				break;
			}
			case "September":{
				month = 9;
				break;
			}
			case "Octorber": {
				month = 10;
				break;
			}
			case "November": {
				month = 11;
				break;
			}
			case "December": {
				month = 12;
				break;
			}
		}
		return month;
	}
	
	public String MonthToString(int nMonth) {
		String sMonth = "";
		switch (nMonth) {
		case 1: {
			sMonth = "January";
			break;
		}
		case 2: {
			sMonth = "February";
			break;
		}
		case 3: {
			sMonth = "March";
			break;
		}
		case 4: {
			sMonth = "April";
			break;
		}
		case 5: {
			sMonth = "May";
			break;
		}
		case 6: {
			sMonth = "June";
			break;
		}
		case 7: {
			sMonth = "July";
			break;
		}
		case 8: {
			sMonth = "August";
			break;
		}
		case 9:{
			sMonth = "September";
			break;
		}
		case 10: {
			sMonth = "Octorber";
			break;
		}
		case 11: {
			sMonth = "November";
			break;
		}
		case 12: {
			sMonth = "December";
			break;
			}
		}
		return sMonth;
	}
}
