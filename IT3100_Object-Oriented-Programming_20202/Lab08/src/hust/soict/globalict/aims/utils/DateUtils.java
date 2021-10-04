package hust.soict.globalict.aims.utils;

import java.util.ArrayList;

public class DateUtils {
	
	public static String compareTwoDates(MyDate firstDate, MyDate secondDate) {
		String s1 = "first date > second date";
		String s2 = "second date > first date";
		String s3 = "same date";
		if (firstDate.getYear() > secondDate.getYear())
			return s1;
		if (firstDate.getYear() < secondDate.getYear())
			return s2;
		if (firstDate.getMonth() > secondDate.getMonth())
			return s1;
		if (firstDate.getMonth() < secondDate.getMonth())
			return s2;
		if (firstDate.getDay() > secondDate.getDay())
			return s1;
		if (firstDate.getDay() < secondDate.getDay())
			return s2;
		return s3;
	}
	
	public static void sortingANumberOfDates(ArrayList<MyDate> dates) 
	{
		for (int i = 0; i < dates.size() - 1; i++)
		{
			for (int j = i + 1; j < dates.size(); j++) 
			{
				if (compareTwoDates(dates.get(i), dates.get(j)) == "first date > second date") 
				{
					MyDate tmp = dates.get(i);
					dates.set(i, dates.get(j));
					dates.set(j, tmp);
				}
			}
		}
	}
}
