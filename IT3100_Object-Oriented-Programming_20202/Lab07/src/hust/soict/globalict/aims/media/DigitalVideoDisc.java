package hust.soict.globalict.aims.media;

public class DigitalVideoDisc extends Disc implements Playable{
	// Constructors
	public DigitalVideoDisc() {
		
	}
	
	public DigitalVideoDisc(String title) {
		super();
	}
	
	public DigitalVideoDisc(String title, String category) {
		super(title, category);
	}
	
	public DigitalVideoDisc(String title, String category, String director) {
		super(title, category, director);
	}
	
	public DigitalVideoDisc(String title, String category, String director, int length, float cost) {
		super(title, category, director, length, cost);
	}
	
	// show information of DigitalVideoDisc
	public void information()
	{
		System.out.println( "DVD - " + 
					getTitle() +  " - " + 
					getCategory() + " - " +
					getCost() + "$ - " + 
					getDirector() + " - " +
					getLength() + "'");
	}

	@Override
	public void play() {
		// TODO Auto-generated method stub
		System.out.println("Playing DVD: " + this.getTitle());
		System.out.println("DVD length: " + this.getLength());
	}
}
