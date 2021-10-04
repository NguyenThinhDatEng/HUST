package com.home.lab04;

import java.lang.*;
import java.util.*;

public class Order {
	// constant
	public static final int MAX_NUMBERS_ORDERS = 10;
	public static final int MAX_LIMITED_ORDERS = 5;
	
	// classifier member
	private static int nbOrderes = 0;
	
	// Instance member
	private DigitalVideoDisc itemsOrdered[] = new DigitalVideoDisc[MAX_NUMBERS_ORDERS];
	private int qtyOrdered = 0;
	private MyDate dateOrder = new MyDate(10, 4, 2021);
	private DigitalVideoDisc luckyItem;
	
	//Constructor
	public Order() {
		if (nbOrderes < MAX_LIMITED_ORDERS) {
			nbOrderes++;
		}
		else
			System.out.println("the order quantity has reached its limit");
	}
	
	// getter and setter
	public int getQtyOrdered() {
		return qtyOrdered;
	}

	public void setQtyOrdered(int qtyOrdered) {
		this.qtyOrdered = qtyOrdered;
	}
	
	public DigitalVideoDisc getALuckyItem()
	{
		int luckyNumber = 0;
		do
		{
			double randomDouble = Math.random();
			randomDouble = randomDouble * 10;
			luckyNumber = (int) randomDouble;
		} while (luckyNumber >= qtyOrdered);
		return itemsOrdered[luckyNumber];
	}
	
	// display the list of ordered items of users on screen
	public void listOfOrderedItemsOfOrder() {
		luckyItem = getALuckyItem();
		System.out.println("*********************Your Order**************************");
		dateOrder.print();
		System.out.println("Order Items:");
		for (int i = 0; i < qtyOrdered; i++)
			System.out.println(i + 1 + ". DVD - " + 
					itemsOrdered[i].getTitle() +  " - " + 
					itemsOrdered[i].getCategory() + " - " +
					itemsOrdered[i].getDirector() + " - " +
					itemsOrdered[i].getLength() + ": " +
					itemsOrdered[i].getCost() + "$");
		System.out.println("You are lucky. " + luckyItem.getTitle() + " is a lucky and free item\n" +  "Total cost: " + totalCost() + "$");
		System.out.println("*********************************************************");
	}

	// add an disc to the order
	public void addDigitalVideoDisc(DigitalVideoDisc disc) {
		if (qtyOrdered < MAX_NUMBERS_ORDERS  && nbOrderes < MAX_LIMITED_ORDERS)
		{
			itemsOrdered[qtyOrdered] = disc;
			qtyOrdered++;
			System.out.println(disc.getTitle() + " has been added");
		}
		else
		{
			if (qtyOrdered >= MAX_NUMBERS_ORDERS)
				System.out.println("The item quantity has reached its limit");
			else
				System.out.println("the order quantity has reached its limit");
		}
	}
	
	// add 2 discs to the order
	public void addDigitalVideoDisc(DigitalVideoDisc dvd1, DigitalVideoDisc dvd2) {
		if (qtyOrdered == MAX_NUMBERS_ORDERS)
		{
			System.out.println("Both first dvd and second dvd cannot added to the current order because of full orders items");
			return;
		}
		else {
			addDigitalVideoDisc(dvd1);
			addDigitalVideoDisc(dvd2);
		}
	}
	
	// add a list of dvd to the order
	public void addDigitalVideoDisc(DigitalVideoDisc[] dvdList) {
		int n = 0;
		for (int i = 0; i < dvdList.length; i++)
			if (dvdList[i] != null)
				n++;
			else
				break;
		 if (qtyOrdered > MAX_NUMBERS_ORDERS - n)
			System.out.println("The list of items cannot added to the current order because of full orders items");
		 for (int i = 0; i < n; i++)
			 addDigitalVideoDisc(dvdList[i]);
	}
	
	// remove an item from an order
	public void removeDigitalVideoDisc(DigitalVideoDisc disc) {
		int index = -1;
		for (int i = 0; i < qtyOrdered; i++) {
			if (itemsOrdered[i].equals(disc)) {
				index = i;
				break;
			}
		}
		if (index >= 0)
		{
			for (int i = index; i < qtyOrdered; i++) {
				itemsOrdered[i] = itemsOrdered[i + 1];
			}
			qtyOrdered--;
			System.out.println(disc.getTitle() + " has been removed");
		}
	}
	
	// caculate total cost of an order which users have to pay
	public float totalCost() {
		float cost = 0;
		luckyItem.setCost(0);
		for (int i = 0; i < qtyOrdered; i++)
		{
			cost += itemsOrdered[i].getCost();
		}
		return cost;
	}
}
