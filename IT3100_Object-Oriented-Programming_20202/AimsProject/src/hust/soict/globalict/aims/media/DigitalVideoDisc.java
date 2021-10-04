package hust.soict.globalict.aims.media;

public class DigitalVideoDisc extends Disc implements Playable{
	// Constructors
	public DigitalVideoDisc() {
		
	}
	
	public DigitalVideoDisc(String title, float cost) {
		super(title, cost);
	}
	
	public DigitalVideoDisc(String title, String category, String director, int length, float cost, int id) {
		super(title, category, director, length, cost, id);
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
		play();
		
	}

	@Override
	public void play() {
		// TODO Auto-generated method stub
		System.out.println("   Playing DVD: " + this.getTitle());
		System.out.println("   DVD length: " + this.getLength());
	}

}
