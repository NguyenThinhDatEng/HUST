package hust.soict.globalict.aims.media;

public class Track implements Playable{

	// instance member
	private String title;
	private	int length;
	
	// constructors
	public Track() {
		// TODO Auto-generated constructor stub
	}
	
	public Track(String title, int length) {
		this.title = title;
		this.length = length;
	}

	// getters
	public String getTitle() {
		return title;
	}

	public int getLength() {
		return length;
	}

	@Override
	public void play() {
		// TODO Auto-generated method stub
		System.out.println("Playing Track: " + this.getTitle());
		System.out.println("Track length: " + this.getLength());
	}
}
