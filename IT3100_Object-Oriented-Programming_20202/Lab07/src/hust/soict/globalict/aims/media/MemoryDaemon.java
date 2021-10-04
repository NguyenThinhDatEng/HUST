package hust.soict.globalict.aims.media;

public class MemoryDaemon implements Runnable{
	// instance member
	private long memoryUsed = 0;	//  It keeps track of the memory usage in the system
	
	// constructor
	public MemoryDaemon() {
		// TODO Auto-generated constructor stub
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		Runtime runtime = Runtime.getRuntime();
		long used;
		
		while (true) {
			used = runtime.totalMemory() - runtime.freeMemory();
			if (used != memoryUsed)
				System.err.println("\n\tMemory used = " + used);
				memoryUsed = used;
		}
	}

}
