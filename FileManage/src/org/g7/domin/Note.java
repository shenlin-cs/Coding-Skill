package org.g7.domin;

public class Note {
	private String messageid;
	private String ExperimentID;
	private String Type;
	private String ID;
	private String InputTime;
	private String HeadID;
	private String HeadName;
	private String IsEstablished;
	
	public Note() {
		super();
	}

	public String getMessageid() {
		return messageid;
	}

	public void setMessageid(String messageid) {
		this.messageid = messageid;
	}

	public String getExperimentID() {
		return ExperimentID;
	}

	public void setExperimentID(String experimentID) {
		ExperimentID = experimentID;
	}

	public String getType() {
		return Type;
	}

	public void setType(String type) {
		Type = type;
	}

	public String getID() {
		return ID;
	}

	public void setID(String iD) {
		ID = iD;
	}

	public String getInputTime() {
		return InputTime;
	}

	public void setInputTime(String inputTime) {
		InputTime = inputTime;
	}

	public String getHeadID() {
		return HeadID;
	}

	public void setHeadID(String headID) {
		HeadID = headID;
	}

	public String getHeadName() {
		return HeadName;
	}

	public void setHeadName(String headName) {
		HeadName = headName;
	}

	public String getIsEstablished() {
		return IsEstablished;
	}

	public void setIsEstablished(String isEstablished) {
		IsEstablished = isEstablished;
	}

	@Override
	public String toString() {
		return "Note [messageid=" + messageid + ", ExperimentID=" + ExperimentID + ", Type=" + Type + ", ID=" + ID
				+ ", InputTime=" + InputTime + ", HeadID=" + HeadID + ", HeadName=" + HeadName + ", IsEstablished="
				+ IsEstablished + "]";
	}

	
	
}
