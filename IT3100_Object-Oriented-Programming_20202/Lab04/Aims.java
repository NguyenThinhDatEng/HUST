package com.home.lab04;

public class Aims {
	public static void main(String[] args) {
		// users create new oders 
		Order anOrder = new Order();
		Order order01 = new Order();
		
		// disc array used to save a list of dvds
		DigitalVideoDisc[] disc = new DigitalVideoDisc[Order.MAX_NUMBERS_ORDERS];
		
		// Create a new dvd object and set the fields
		DigitalVideoDisc dvd1 = new DigitalVideoDisc("The Lion King");
		dvd1.setCategory("Animation");
		dvd1.setCost(19.95f);
		dvd1.setDirector("Roger Allers");
		dvd1.setLength(87);
		
		// add the dvd to the order
		anOrder.addDigitalVideoDisc(dvd1);
		
		DigitalVideoDisc dvd2 = new DigitalVideoDisc("Star Wars");
		dvd2.setCategory("Science Fiction");
		dvd2.setCost(24.95f);
		dvd2.setDirector("George Lucas");
		dvd2.setLength(124);
		anOrder.addDigitalVideoDisc(dvd2);
		
		DigitalVideoDisc dvd3 = new DigitalVideoDisc("Aladdin");
		dvd3.setCategory("Animation");
		dvd3.setCost(18.99f);
		dvd3.setDirector("John Musker");
		dvd3.setLength(90);
		anOrder.addDigitalVideoDisc(dvd3);
		
		// remove dvd
		// anOrder.removeDigitalVideoDisc(dvd1);
		
		DigitalVideoDisc dvd4 = new DigitalVideoDisc("Naruto");
		dvd4.setCategory("Anime");
		dvd4.setCost(55.5f);
		dvd4.setDirector("Kishimoto Masashi");
		dvd4.setLength(5148);
		
		// add the dvd to the disc array
		disc[0] = dvd4;
		
		DigitalVideoDisc dvd5 = new DigitalVideoDisc("Dr.Stone");
		dvd5.setCategory("Anime");
		dvd5.setCost(6.03f);
		dvd5.setDirector("Inagaki Riichiro");
		dvd5.setLength(300);
		disc[1] = dvd5;
		
		// add list of dvds to the order of user01
		order01.addDigitalVideoDisc(disc);
		
		// display the information of orders on screen
		anOrder.listOfOrderedItemsOfOrder();
		order01.listOfOrderedItemsOfOrder();
	}
}
