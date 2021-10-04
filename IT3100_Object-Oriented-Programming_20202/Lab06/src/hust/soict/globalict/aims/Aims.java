package hust.soict.globalict.aims;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import hust.soict.globalict.aims.media.Book;
import hust.soict.globalict.aims.media.DigitalVideoDisc;
import hust.soict.globalict.aims.media.Media;
import hust.soict.globalict.aims.order.Order;

public class Aims {
	public static void showMenu() {
		System.out.println("\nOrder Management Application: ");
		System.out.println("--------------------------------");
		System.out.println("1. Create new order");
		System.out.println("2. Add item to the order");
		System.out.println("3. Delete item by id");
		System.out.println("4. Display the items list of order");
		System.out.println("0. Exit");
		System.out.println("--------------------------------");
		System.out.println("Please choose a number: 0-1-2-3-4");
	}
	
	public static void main(String[] args) {
		// declare variable
		int choose;
		int id = 0;
		ArrayList<Media> items = new ArrayList<Media>();
		ArrayList<DigitalVideoDisc> discs = new ArrayList<DigitalVideoDisc>();
		ArrayList<Book> books = new ArrayList<Book>();
		ArrayList<String> authors;
		Scanner scanner = new Scanner(System.in);
		
		// List of discs
		discs.add(new DigitalVideoDisc("The Lion King", "Animation", "Roger Allers", 87, 19.95f, ++id));
		discs.add(new DigitalVideoDisc("Naruto", "Anime", "Kishimoto Masashi", 5148, 55.5f, ++id));
		items.addAll(discs);
		
		// List of books
		authors = new ArrayList<String>(Arrays.asList("Paulo Coelho"));
		books.add(new Book("Nhà Giả Kim", "novel", authors, 2.47f, ++id));
		items.addAll(books);
		
		do
		{	
			showMenu();
			
			choose = scanner.nextInt();
			
			switch(choose) {
			case 0: {
				break;
			}
			case 1:
			{
				Order order = new Order();
				System.out.println("A new order is created");
				showMenu();
				
				do {
					choose = scanner.nextInt();
					switch (choose) {
					case 2: {
						System.out.println("Enter a name item: ");
						scanner.nextLine();
						String nameItem = scanner.nextLine();
						for (Media item : items)
						{
							if (item.search(nameItem))
								order.addMedia(item);
						}
						
						showMenu();
						
						break;
					}
					case 3: {
						if (order.getLength() == 0)
						{
							System.out.println("Your order does not contain any items\n"
												+ "Please add a certain item\n"
													+ "\nPlease choose a number: 0-1-2-3-4");
							break;
						}
						System.out.print("Delete item by id: ");
						int ID = scanner.nextInt();
						for (Media item : items)
						{
							if (item.getId() == ID)
								order.removeMedia(item);
						}
						break;
					}
					case 4: {
						order.listOfOrderedItemsOfOrder();
						
						System.out.println("\nPress any key");
						scanner.nextLine();
						String randomKey = scanner.nextLine();
						showMenu();
						break;
					}
					default: {
						choose = 1;
						break;
					}
					}
				}  while (choose != 1);
				break;
			}
			default: {
				System.out.println("You have to create a new order before");
				break;
			}
			}
		} while (choose != 0);
	}
}
