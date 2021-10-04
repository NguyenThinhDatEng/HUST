package hust.soict.globalict.aims.order;

import java.util.ArrayList;
import java.util.Collections;

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
	
	public int getId() {
		return id;
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
	public void listOfOrderedItems() {
		if (getLength() == 0)
		{
			System.out.println("No result");
			return;
		}
		luckyItem = getALuckyItem();
		Collections.sort(itemsOrdered);
		System.out.println("\n****************Your Order*****************");
		dateOrder.print();
		System.out.println("Order Items:");
		for (int i = 0; i < itemsOrdered.size(); i++)
		{
			System.out.print(i + 1 + ". ");
			itemsOrdered.get(i).information();
		}
		System.out.println("\nYou are lucky. " + luckyItem.getTitle() + " is a lucky and free item\n" +  "Total cost: " + totalCost() + "$");
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
	
	// add a new item to the order
	public void addMedia(Media media)
	{
		if (itemsOrdered.size() < MAX_NUMBERS_ORDERS  && nbOrderes < MAX_LIMITED_ORDERS)
		{
			for (Media aMedia : itemsOrdered)
				if (aMedia.equals(media)) {
					System.out.println(media.getTitle() + " is not already exists");
					return;
				}
			itemsOrdered.add(media);
			id = media.getId();
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
	
	// remove an item from the order
	public void removeMedia(int id)
	{
		boolean bool = true;
		for (Media aMedia : itemsOrdered) {
			if (aMedia.getId() == id) {
				itemsOrdered.remove(aMedia);
				System.out.println(aMedia.getTitle() + " has been removed");
				bool = false;
				break;
			}
		}
		if (bool) System.out.println(id + " is not found in the current order");
	}
	
}
