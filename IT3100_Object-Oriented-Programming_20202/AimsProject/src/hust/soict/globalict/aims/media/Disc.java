package hust.soict.globalict.aims.media;

public class Disc extends Media{
	
	// Instance member
	private int length;
	private String director;
	
	// constructors
	public Disc() {
		// TODO Auto-generated constructor stub
	}
	
	public Disc(String title, float cost) {
		super(title, cost);
	}
	
	public Disc(String title, String category, String director, float cost, int id) {
		super(title, category, cost, id);
		this.director = director;
	}
	
	public Disc(String title, String category, String director, int length, float cost, int id)
	{
		super(title, category, cost, id);
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
