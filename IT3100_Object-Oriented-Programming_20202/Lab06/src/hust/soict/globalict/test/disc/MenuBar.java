package hust.soict.globalict.test.disc;

public class MenuBar {
	public void tiDoWelcome() {
		System.out.println("\n\t\tTi-Do, Welcome");
		System.out.println("--------------------------------------------");
		System.out.println("1. Search\n" + 
							"2. Create a new Order\n" + 
							"3. Display your orders on screen\n" + 
							"0. Exit");
		System.out.println("--------------------------------------------");
	}
	
	public void orderMenu() {
		System.out.println("\n_________________Order_________________");
		System.out.println(
				"1. Add a item to the order\n" + 
				"2. Add a list of items to the order\n" +
				"3. Remove a item from the order\n" + 
				"4. show a list of the items you have ordered\n" + 
				"0. Exit");
		System.out.println("_______________________________________");
	}
}
