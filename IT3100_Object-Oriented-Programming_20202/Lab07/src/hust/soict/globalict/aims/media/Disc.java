package hust.soict.globalict.aims.media;

public class Disc extends Media{
	
	// Instance member
	private int length;
	private String director;
	
	// constructors
	public Disc() {
		// TODO Auto-generated constructor stub
	}
	
	public Disc(String title) {
		super();
	}
	
	public Disc(String title, String category) {
		super(title, category);
	}
	
	public Disc(String title, String category, String director) {
		super(title, category);
		this.director = director;
	}
	
	public Disc(String title, String category, int length) {
		super(title, category, length);
	}
	
	public Disc(String title, String category, String director, int length, float cost)
	{
		super(title, category, cost);
		this.length = length;
		this.director = director;
	}
	
	//getters
	public int getLength() {
		return length;
	}

	public String getDirector() {
		return director;
	}

	@Override
	public void information() {
		// TODO Auto-generated method stub
		
	}

}
