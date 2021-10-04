package hust.soict.globalict.aims;

import java.util.Scanner;

import hust.soict.globalict.aims.media.Book;
import hust.soict.globalict.aims.media.CompactDisc;
import hust.soict.globalict.aims.media.DigitalVideoDisc;
import hust.soict.globalict.aims.media.MemoryDaemon;
import hust.soict.globalict.aims.media.Track;
import hust.soict.globalict.aims.order.Order;

public class Aims {
	public static void showMenu() {
		System.out.println("\nOrder Management Application: ");
		System.out.println("--------------------------------");
		System.out.println( "1. Create new order\n" + 
							"2. Add item to the order\n" + 
							"3. Delete item by id\n" +
							"4. Display the items list of order\n" +
							"0. Exit");
		System.out.println("--------------------------------");
		System.out.println("Please choose a number: 0-1-2-3-4");
	}
	
	public static void showType() {
		System.out.println("\nThere are currently three types of media");
		System.out.println("_______________________________");
		System.out.println( 
							"1. Book\n" + 
					"2. Compact Disc (CD)\n" + 
				 "3. Digital Video Disc (DVD)\n" +
							"0. Exit");
		System.out.println("_______________________________");
		System.out.println("Please choose a number: 0-1-2-3");
	}
	
	public static void main(String[] args) {
		System.out.println("Main thread start");
		
		// declare variable
		Scanner scanner = new Scanner(System.in);
		int choose = 0;
		String title;
		String category;
		float cost;
		int id = 1;
		String director;
		MemoryDaemon memory = new MemoryDaemon();
		Thread thread = new Thread(memory);
		thread.setDaemon(true);
		
		System.out.println("Daemon thread start");
		thread.start();	
		
		boolean creatNewOrder = false;
		do
		{	
			if (creatNewOrder == false) {
				showMenu();
				choose = scanner.nextInt();
				creatNewOrder = true;
			}
			switch(choose) {
			case 0:
					break;
			case 1:
			{
				Order order = new Order();
				System.out.println("A new order is created");
				showMenu();
				do {
					choose = scanner.nextInt();
					switch (choose) {
					case 0: break;
					case 2:
							int typeItem;
							do {
								showType();
								typeItem = scanner.nextInt();
								switch (typeItem) {
								case 0 :
										break;
								case 1 :
										scanner.nextLine();
										System.out.print("Title: ");
										title = scanner.nextLine();
										
										System.out.print("Category: ");
										category = scanner.nextLine();
										
										System.out.print("Cost($): ");
										cost = scanner.nextFloat();
										
										Book book = new Book(title, category, cost, id++);
										scanner.nextLine();
										String nameAuthor;
										System.out.println("Authors: (Press 'q' to quit)");
										do {
											nameAuthor = scanner.nextLine();
											if (!nameAuthor.equals("q")) book.addAuthor(nameAuthor);
										} while (!nameAuthor.equals("q"));
								
										order.addMedia(book);
										break;
								case 2:
										scanner.nextLine();
										System.out.print("Title: ");
										title = scanner.nextLine();
										
										System.out.print("Category: ");
										category = scanner.nextLine();
										
										System.out.print("Director: ");
										director = scanner.nextLine();
										
										System.out.print("Artist: ");
										String artirst = scanner.nextLine();
										
										System.out.print("Cost($): ");
										cost = scanner.nextFloat();
										
										CompactDisc CD = new CompactDisc(title, category, director, cost, id++, artirst);
										
										System.out.println("List of tracks: (Enter Length = 0 to quit)");
										Track track;
										String titleTrack;
										int lengthTrack;
										do {
											scanner.nextLine();
											System.out.print("Title: ");
											titleTrack = scanner.nextLine();
												
											System.out.print("Length: ");
											lengthTrack = scanner.nextInt();
											
											track = new Track(titleTrack, lengthTrack);	
											if (lengthTrack != 0) CD.addTrack(track);
										} while (lengthTrack != 0);
										
										order.addMedia(CD);
										break;
								case 3:
										int length;
									
										scanner.nextLine();
										System.out.print("Title: ");
										title = scanner.nextLine();
										
										System.out.print("Category: ");
										category = scanner.nextLine();
										
										System.out.print("Director: ");
										director = scanner.nextLine();
										
										System.out.print("Length: ");
										length = scanner.nextInt();
										
										System.out.print("Cost($): ");
										cost = scanner.nextFloat();
										
										order.addMedia(new DigitalVideoDisc(title, category, director, length, cost, id++));
										break;
								}
								if (order.getLength() == order.MAX_NUMBERS_ORDERS) 
									System.out.println("The item quantity has reached its limit");
								
							} while(typeItem != 0 && order.getLength() < order.MAX_NUMBERS_ORDERS);
							showMenu();
							break;
					case 3: 
							if (order.getLength() == 0)
								System.out.println("Your order does not contain any items\n"
													+ "Please add a certain item\n");
							else
							{
								System.out.println("ID: ");
								int ID = scanner.nextInt();
								
							}
							break;
					case 4: 
							order.listOfOrderedItems();
							System.out.println("\nPress any key");
							scanner.nextLine();
							String randomKey = scanner.nextLine();
							showMenu();
							break;
					default:
							choose = 1;
							creatNewOrder = true;
							break;
					}
				}  while (choose > 1);
				break;
			}
			default:
					do {
						System.out.println("You have to create a new order before");
						System.out.println("Please press 1 to continue...");
						choose = scanner.nextInt();
						if (choose == 1) creatNewOrder = true;
						/*
						 * else creatNewOrder = false;
						 */
					} while (choose > 1);
					break;
			}
		} while (choose != 0);
		System.out.println("you have exited");
		System.out.println("\n\tMain thread end");
	}
}