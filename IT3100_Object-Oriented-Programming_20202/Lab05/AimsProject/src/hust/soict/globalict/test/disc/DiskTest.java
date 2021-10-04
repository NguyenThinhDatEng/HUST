package hust.soict.globalict.test.disc;

import java.util.*;

import hust.soict.globalict.aims.order.*;

import hust.soict.globalict.aims.disc.DigitalVideoDisc;

public class DiskTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<DigitalVideoDisc> discs = new ArrayList<DigitalVideoDisc>();
		ArrayList<Order> oders = new ArrayList<Order>();
		MenuBar menuBar = new MenuBar(); // Show menu
		int choose = 0; // what the customer wants to do
		String decisionUser = "Y"; // user decision return Y/N

		// initialize DigitalVideoDiscs
		DigitalVideoDisc dvd1 = new DigitalVideoDisc("The Lion King");
		dvd1.setCategory("Animation");
		dvd1.setCost(19.95f);
		dvd1.setDirector("Roger Allers");
		dvd1.setLength(87);
		discs.add(dvd1);

		DigitalVideoDisc dvd2 = new DigitalVideoDisc("Star Wars");
		dvd2.setCategory("Science Fiction");
		dvd2.setCost(24.95f);
		dvd2.setDirector("George Lucas");
		dvd2.setLength(124);
		discs.add(dvd2);

		DigitalVideoDisc dvd3 = new DigitalVideoDisc("Aladdin");
		dvd3.setCategory("Animation");
		dvd3.setCost(18.99f);
		dvd3.setDirector("John Musker");
		dvd3.setLength(90);
		discs.add(dvd3);

		DigitalVideoDisc dvd4 = new DigitalVideoDisc("Naruto");
		dvd4.setCategory("Anime");
		dvd4.setCost(55.5f);
		dvd4.setDirector("Kishimoto Masashi");
		dvd4.setLength(5148);
		discs.add(dvd4);

		DigitalVideoDisc dvd5 = new DigitalVideoDisc("Dr.Stone");
		dvd5.setCategory("Anime");
		dvd5.setCost(6.03f);
		dvd5.setDirector("Inagaki Riichiro");
		dvd5.setLength(300);
		discs.add(dvd5);

		DigitalVideoDisc dvd6 = new DigitalVideoDisc("OK");
		dvd6.setCategory("Music");
		dvd6.setCost(10.01f);
		dvd6.setDirector("Binz");
		dvd6.setLength(3);
		discs.add(dvd6);
		
		DigitalVideoDisc dvd7 = new DigitalVideoDisc("The Transporter");
		dvd7.setCategory("Action");
		dvd7.setCost(14.99f);
		dvd7.setDirector("	Corey Yuen, Louis Leterrier");
		dvd7.setLength(92);
		discs.add(dvd7);

		do {
			menuBar.tiDoWelcome();
			if(decisionUser == "Y")
			{
				System.out.print("Type from 0 to 3 in AIMS: ");
			/* if(decisionUser == "Y") */ choose = sc.nextInt();		// if user agree then initialize choose
			}

			switch (choose) {
			// Exit
			case 0: {
				break;
			}
			// search
			case 1: {
				System.out.print("Search: ");
				sc.nextLine();
				String title = sc.nextLine();
				for (DigitalVideoDisc disk : discs) {
					if (disk.search(title)) {
						disk.infomation();
					}
				}
				break;
			}
			// Create a new Order
			case 2: {
				Order order = new Order(); // create a new order
				int selection; // is the user's choice

				menuBar.orderMenu(); // show Menu of Order

				do {
					System.out.print("\nType from 0 to 4 in Order: ");

					selection = sc.nextInt();

					switch (selection) {
					// Exit
					case 0: {
						break;
					}
					// Add a item to the order
					case 1: {
						System.out.println("\nWhat is the name of the item you want to add?");
						sc.nextLine();
						String title = sc.nextLine();
						for (DigitalVideoDisc disk : discs) {
							if (disk.search(title)) {
								order.addDigitalVideoDisc(disk);
							}
						}
						break;
					}
					// Add a list of items to the order
					case 2: {
						String title; // name of an item
						int numberOfItems; // number of items the user requested
						int lengMax = order.MAX_NUMBERS_ORDERS - order.getQtyOrdered(); // The item number limit is 10
						DigitalVideoDisc[] discArray = new DigitalVideoDisc[lengMax];
						decisionUser = "N";		// The user's initial decision is No

						do {
							System.out.println("\nHow many items do you add?");
							numberOfItems = sc.nextInt();
							if (numberOfItems > order.MAX_NUMBERS_ORDERS)
							{
								System.out.println("\nA order can by maximum 10 items");
							}
							else
								if (numberOfItems > lengMax) 
								{
									System.out.println("You can only add up to " + lengMax + " items to this order");
									System.out.println("Do you want to create a new order?[Y/N]");
									sc.nextLine();		// same delete buffer in C
									decisionUser = sc.nextLine();
								}
								else
									break;
						} while (decisionUser.equals("N") || decisionUser.equals("n"));
						
						if (!decisionUser.equals("Y") && !decisionUser.equals("y")) 
						{
							int index = 0;
							
							sc.nextLine();		// same delete buffer in C
							
							do {
								title = sc.nextLine();
								
								for (DigitalVideoDisc disc : discs) {
									if (disc.search(title)) {
										discArray[index++] = disc;
									}
								}
							} while (index < numberOfItems);
							order.addDigitalVideoDisc(discArray);
						}
						
						choose = 2;
						selection = 0;
						decisionUser = "N";
						break;
					}
					// show a list of the items you have ordered
					case 4: {
						order.listOfOrderedItemsOfOrder();
						break;
					}
					}
				} while (selection != 0);
				if (order.getQtyOrdered() > 0)
					oders.add(order);
				break;
			}
			// Display your orders on screen
			case 3: {
				for (Order order : oders) {
					order.listOfOrderedItemsOfOrder();
				}
				break;
			}
			default: {
				System.out.println("You have to enter between 0 and 3");
				break;
			}
			}
		} while (choose != 0);
	}
}
