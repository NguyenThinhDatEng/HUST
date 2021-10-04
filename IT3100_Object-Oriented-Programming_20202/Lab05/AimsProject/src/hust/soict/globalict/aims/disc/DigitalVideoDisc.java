package hust.soict.globalict.aims.disc;

public class DigitalVideoDisc {
	// declare attributes
	private String title;
	private String category;
	private String director;
	private int length;
	private float cost;
	
	// Constructors
	public DigitalVideoDisc(String title) {
		super();
		this.title = title;
	}
	
	public DigitalVideoDisc(String title, String category) {
		super();
		this.title = title;
		this.category = category;
	}
	
	public DigitalVideoDisc(String title, String category, String director) {
		super();
		this.title = title;
		this.category = category;
		this.director = director;
	}
	
	public DigitalVideoDisc(String title, String category, String director, int length, float cost) {
		super();
		this.title = title;
		this.category = category;
		this.director = director;
		this.length = length;
		this.cost = cost;
	}
	
	// setter and getter
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public String getCategory() {
		return category;
	}
	public void setCategory(String category) {
		this.category = category;
	}
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
	public float getCost() {
		return cost;
	}
	public void setCost(float cost) {
		this.cost = cost;
	}
	
	// try to find title which users are entered in system 
	public boolean search(String title)
	{
		title = title.toUpperCase();
		String[] words = this.title.split("\\s");
		for (String word : words) {
			word = word.toUpperCase();
			if (title.indexOf(word) < 0)
			{
				return false;
			}
		}
		return true;
	}
	
	// show information of DigitalVideoDisc
	public void infomation()
	{
		System.out.println( 
				getTitle() +  " - " + 
				getCategory() + " - " +
				getDirector() + " - " +
				getLength() + "': " +
				getCost() + "$");
	}
}
