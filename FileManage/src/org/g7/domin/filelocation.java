package org.g7.domin;

public class filelocation {
	private String  ExperimentID;
	private String Isprinted;
	private String ShelfLocation;
	private String LayLocation;
	public String getExperimentID() {
		return ExperimentID;
	}
	public void setExperimentID(String experimentID) {
		ExperimentID = experimentID;
	}
	public String getIsprinted() {
		return Isprinted;
	}
	public void setIsprinted(String isprinted) {
		Isprinted = isprinted;
	}
	public String getShelfLocation() {
		return ShelfLocation;
	}
	public void setShelfLocation(String shelfLocation) {
		ShelfLocation = shelfLocation;
	}
	public String getLayLocation() {
		return LayLocation;
	}
	public void setLayLocation(String layLocation) {
		LayLocation = layLocation;
	}
	@Override
	public String toString() {
		return "filelocation [ExperimentID=" + ExperimentID + ", Isprinted=" + Isprinted + ", ShelfLocation="
				+ ShelfLocation + ", LayLocation=" + LayLocation + "]";
	}
	
}
