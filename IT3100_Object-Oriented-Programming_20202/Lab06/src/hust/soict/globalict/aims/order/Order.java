package hust.soict.globalict.aims.order;

import java.util.ArrayList;

import hust.soict.globalict.aims.media.Media;
import hust.soict.globalict.aims.utils.MyDate;

public class Order {
	// constant
	public static final int MAX_NUMBERS_ORDERS = 10;
	public static final int MAX_LIMITED_ORDERS = 5;
	
	// classifier member
	private static int nbOrderes = 0;
	
	// instance member
	private MyDate dateOrder = new MyDate(10, 4, 2021);
	private Media luckyItem;
	private ArrayList<Media> itemsOrdered = new ArrayList<Media>();
	private int id;
	
	//Constructor
	public Order() {
		if (nbOrderes < MAX_LIMITED_ORDERS) {
			nbOrderes++;
		}
		else
			System.out.println("the order quantity has reached its limit");
	}
	
	// get the length of order
	public int getLength() {
		return itemsOrdered.size();
	}
	
	// pick out a lucky item
	public Media getALuckyItem()
	{
		int luckyNumber = 0;
		do
		{
			double randomDouble = Math.random();
			randomDouble = randomDouble * 10;
			luckyNumber = (int) randomDouble;
		} while (luckyNumber >= itemsOrdered.size());
		return itemsOrdered.get(luckyNumber);
	}
	
	// display the list of ordered items of users on screen
	public void listOfOrderedItemsOfOrder() {
		if (getLength() == 0)
		{
			System.out.println("No result");
			return;
		}
		luckyItem = getALuckyItem();
		System.out.println("****************Your Order*****************");
		dateOrder.print();
		System.out.println("Order Items:");
		for (int i = 0; i < itemsOrdered.size(); i++)
			System.out.println(i + 1 + ". DVD - " +
			"id: " +	itemsOrdered.get(i).getId() + " - " +
						itemsOrdered.get(i).getTitle() +  " - " + 
						itemsOrdered.get(i).getCategory() + " - " +
						//itemsOrdered.get(i).getDirector() + " - " +
						//itemsOrdered.get(i).getLength() + "': " +
						itemsOrdered.get(i).getCost() + "$");
		System.out.println("You are lucky. " + luckyItem.getTitle() + " is a lucky and free item\n" +  "Total cost: " + totalCost() + "$");
	}

	// calculate total cost of an order which users have to pay
	public float totalCost() {
		float cost = 0;
		for (int i = 0; i < itemsOrdered.size(); i++)
		{
			cost += itemsOrdered.get(i).getCost();
		}
		return cost - luckyItem.getCost();
	}
	
	public void addMedia(Media media)
	{
		if (itemsOrdered.size() < MAX_NUMBERS_ORDERS  && nbOrderes < MAX_LIMITED_ORDERS)
		{
			itemsOrdered.add(media);
			System.out.println(media.getTitle() + " has been added");
		}
		else
		{
			if (itemsOrdered.size() >= MAX_NUMBERS_ORDERS)
				System.out.println("The item quantity has reached its limit");
			else
				System.out.println("the order quantity has reached its limit");
		}
	}
	
	public void removeMedia(Media media)
	{
		if (itemsOrdered.contains(media)) {
			itemsOrdered.remove(media);
			System.out.println(media.getTitle() + " has been removed");
		}
		else
			System.out.println(media.getTitle() + " is not already exists");
	}
}
