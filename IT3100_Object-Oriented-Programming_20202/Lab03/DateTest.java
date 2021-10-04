
public class DateTest {
	public static void main(String[] args) {
		
		MyDate date = new MyDate("January 4th 2019");
		date.print();
		
		date = new MyDate(100, 2, 10);
		date.print();
		
		date.accept();
		date.print();
		
		date.setDay(22);
		date.setMonth(12);
		date.setYear(2020);
		date.print();
		
	}
}
