package org.g7.domin;
import java.io.Serializable;

public class DiscussionNote implements Serializable{
	private String DiscussionID;
	private String DiscussionName;
	private String DiscussionRoomID;
	private String DiscussionHeadID;
	private String DiscussionHeadName;
	private String PIID;
	private String PIName;
	private String PIPhoneNumber;
	private String PITeamName;
	private String ExperimentID;
	private String ExperimentName;
	private String AnimalID;
	private String DiscussionAim;
	private String DiscussionResult;
	private String DiscussionExcuter;
	private String DiscussionEquipment;
	private String DiscussionMedicament;
	private String DiscussionTime;
	private String InputTime;
	private String IsEstablished;
	
	public DiscussionNote() {
		super();
	}

	public String getDiscussionID() {
		return DiscussionID;
	}

	public void setDiscussionID(String discussionID) {
		DiscussionID = discussionID;
	}

	public String getDiscussionName() {
		return DiscussionName;
	}

	public void setDiscussionName(String discussionName) {
		DiscussionName = discussionName;
	}

	public String getDiscussionRoomID() {
		return DiscussionRoomID;
	}

	public void setDiscussionRoomID(String discussionRoomID) {
		DiscussionRoomID = discussionRoomID;
	}

	public String getDiscussionHeadID() {
		return DiscussionHeadID;
	}

	public void setDiscussionHeadID(String discussionHeadID) {
		DiscussionHeadID = discussionHeadID;
	}

	public String getDiscussionHeadName() {
		return DiscussionHeadName;
	}

	public void setDiscussionHeadName(String discussionHeadName) {
		DiscussionHeadName = discussionHeadName;
	}

	public String getPIID() {
		return PIID;
	}

	public void setPIID(String pIID) {
		PIID = pIID;
	}

	public String getPIName() {
		return PIName;
	}

	public void setPIName(String pIName) {
		PIName = pIName;
	}

	public String getPIPhoneNumber() {
		return PIPhoneNumber;
	}

	public void setPIPhoneNumber(String pIPhoneNumber) {
		PIPhoneNumber = pIPhoneNumber;
	}

	public String getPITeamName() {
		return PITeamName;
	}

	public void setPITeamName(String pITeamName) {
		PITeamName = pITeamName;
	}

	public String getExperimentID() {
		return ExperimentID;
	}

	public void setExperimentID(String experimentID) {
		ExperimentID = experimentID;
	}

	public String getExperimentName() {
		return ExperimentName;
	}

	public void setExperimentName(String experimentName) {
		ExperimentName = experimentName;
	}

	public String getAnimalID() {
		return AnimalID;
	}

	public void setAnimalID(String animalID) {
		AnimalID = animalID;
	}

	public String getDiscussionAim() {
		return DiscussionAim;
	}

	public void setDiscussionAim(String discussionAim) {
		DiscussionAim = discussionAim;
	}

	public String getDiscussionResult() {
		return DiscussionResult;
	}

	public void setDiscussionResult(String discussionResult) {
		DiscussionResult = discussionResult;
	}

	public String getDiscussionExcuter() {
		return DiscussionExcuter;
	}

	public void setDiscussionExcuter(String discussionExcuter) {
		DiscussionExcuter = discussionExcuter;
	}

	public String getDiscussionEquipment() {
		return DiscussionEquipment;
	}

	public void setDiscussionEquipment(String discussionEquipment) {
		DiscussionEquipment = discussionEquipment;
	}

	public String getDiscussionMedicament() {
		return DiscussionMedicament;
	}

	public void setDiscussionMedicament(String discussionMedicament) {
		DiscussionMedicament = discussionMedicament;
	}

	public String getDiscussionTime() {
		return DiscussionTime;
	}

	public void setDiscussionTime(String discussionTime) {
		DiscussionTime = discussionTime;
	}

	public String getInputTime() {
		return InputTime;
	}

	public void setInputTime(String inputTime) {
		InputTime = inputTime;
	}

	public String getIsEstablished() {
		return IsEstablished;
	}

	public void setIsEstablished(String isEstablished) {
		IsEstablished = isEstablished;
	}

	@Override
	public String toString() {
		return "DiscussionNote [DiscussionID=" + DiscussionID + ", DiscussionName=" + DiscussionName
				+ ", DiscussionRoomID=" + DiscussionRoomID + ", DiscussionHeadID=" + DiscussionHeadID
				+ ", DiscussionHeadName=" + DiscussionHeadName + ", PIID=" + PIID + ", PIName=" + PIName
				+ ", PIPhoneNumber=" + PIPhoneNumber + ", PITeamName=" + PITeamName + ", ExperimentID=" + ExperimentID
				+ ", ExperimentName=" + ExperimentName + ", AnimalID=" + AnimalID + ", DiscussionAim=" + DiscussionAim
				+ ", DiscussionResult=" + DiscussionResult + ", DiscussionExcuter=" + DiscussionExcuter
				+ ", DiscussionEquipment=" + DiscussionEquipment + ", DiscussionMedicament=" + DiscussionMedicament
				+ ", DiscussionTime=" + DiscussionTime + ", InputTime=" + InputTime + ", IsEstablished=" + IsEstablished
				+ "]";
	}
	
	
	
}
