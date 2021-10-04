package hust.soict.globalict.aims.media;

public class DigitalVideoDisc extends Media{
	private String director;
	private int length;
	// Constructors
	public DigitalVideoDisc(String title) {
		super();
	}
	
	public DigitalVideoDisc(String title, String category) {
		super(title, category);
	}
	
	public DigitalVideoDisc(String title, String category, String director) {
		super(title, category);
		this.director = director;
	}
	
	public DigitalVideoDisc(String title, String category, String director, int length, float cost) {
		super(title, category, cost);
		this.director = director;
		this.length = length;
	}
	
	public DigitalVideoDisc(String title, String category, String director, int length, float cost, int id) {
		super(title, category, cost, id);
		this.director = director;
		this.length = length;
	}
	
	// setter and getter
	public String getDirector() {
		return director;
	}
	public void setDirector(String director) {
		this.director = director;
	}
	public int getLength() {
		return length;
	}
	public void setLength(int length) {
		this.length = length;
	}
	
	// show information of DigitalVideoDisc
	public void information()
	{
		System.out.println( 
		"ID: " + 	getId() + " - " +
					getTitle() +  " - " + 
					getCategory() + " - " +
					getDirector() + " - " +
					getLength() + "': " +
					getCost() + "$");
	}
}
