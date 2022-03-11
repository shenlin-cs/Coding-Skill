package org.g7.domin;

public class Signinfo {
	private int SignInfoID;
	private String AnimalID;
	private String ExperimentID;
	private String RecordTime;
	private double Temperature;
	private int Pulse;
	private int Breathe;
	private double Out;
	private double In;
	private double Mass;
	
	public Signinfo() {
		super();
	}

	public int getSignInfoID() {
		return SignInfoID;
	}

	public void setSignInfoID(int signInfoID) {
		SignInfoID = signInfoID;
	}

	public String getAnimalID() {
		return AnimalID;
	}

	public void setAnimalID(String animalID) {
		AnimalID = animalID;
	}

	public String getExperimentID() {
		return ExperimentID;
	}

	public void setExperimentID(String experimentID) {
		ExperimentID = experimentID;
	}

	public String getRecordTime() {
		return RecordTime;
	}

	public void setRecordTime(String recordTime) {
		RecordTime = recordTime;
	}

	public double getTemperature() {
		return Temperature;
	}

	public void setTemperature(double temperature) {
		Temperature = temperature;
	}

	public int getPulse() {
		return Pulse;
	}

	public void setPulse(int pulse) {
		Pulse = pulse;
	}

	public int getBreathe() {
		return Breathe;
	}

	public void setBreathe(int breathe) {
		Breathe = breathe;
	}

	public double getOut() {
		return Out;
	}

	public void setOut(double out) {
		Out = out;
	}

	public double getIn() {
		return In;
	}

	public void setIn(double in) {
		In = in;
	}

	public double getMass() {
		return Mass;
	}

	public void setMass(double mass) {
		Mass = mass;
	}

	@Override
	public String toString() {
		return "Signinfo [SignInfoID=" + SignInfoID + ", AnimalID=" + AnimalID + ", ExperimentID=" + ExperimentID
				+ ", RecordTime=" + RecordTime + ", Temperature=" + Temperature + ", Pulse=" + Pulse + ", Breathe="
				+ Breathe + ", Out=" + Out + ", In=" + In + ", Mass=" + Mass + "]";
	}
	
	
}
