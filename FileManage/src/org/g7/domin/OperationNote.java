package org.g7.domin;
import java.io.Serializable;
import java.util.Date;

public class OperationNote implements Serializable{
	private String OperationID;
	private String OperationName;
	private String OperationRoomID;
	private String OperationHeadID;
	private String OperationHeadName;
	private String PIID;
	private String PIName;
	private String PIPhoneNumber;
	private String PITeamName;
	private String ExperimentID;
	private String ExperimentName;	
	private String AnimalID;
	private String OperationAim;
	private String OperationResult;
	private String OperationExcuter;
	private String OperationEquipment;
	private String OperationMedicament;	
	private String OperationTime;
	private String InputTime;
	private String IsEstablished;
	
	public OperationNote() {
		super();
	}

	public String getOperationID() {
		return OperationID;
	}

	public void setOperationID(String operationID) {
		OperationID = operationID;
	}

	public String getOperationName() {
		return OperationName;
	}

	public void setOperationName(String operationName) {
		OperationName = operationName;
	}

	public String getOperationRoomID() {
		return OperationRoomID;
	}

	public void setOperationRoomID(String operationRoomID) {
		OperationRoomID = operationRoomID;
	}

	public String getOperationHeadID() {
		return OperationHeadID;
	}

	public void setOperationHeadID(String operationHeadID) {
		OperationHeadID = operationHeadID;
	}

	public String getOperationHeadName() {
		return OperationHeadName;
	}

	public void setOperationHeadName(String operationHeadName) {
		OperationHeadName = operationHeadName;
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

	public String getOperationAim() {
		return OperationAim;
	}

	public void setOperationAim(String operationAim) {
		OperationAim = operationAim;
	}

	public String getOperationResult() {
		return OperationResult;
	}

	public void setOperationResult(String operationResult) {
		OperationResult = operationResult;
	}

	public String getOperationExcuter() {
		return OperationExcuter;
	}

	public void setOperationExcuter(String operationExcuter) {
		OperationExcuter = operationExcuter;
	}

	public String getOperationEquipment() {
		return OperationEquipment;
	}

	public void setOperationEquipment(String operationEquipment) {
		OperationEquipment = operationEquipment;
	}

	public String getOperationMedicament() {
		return OperationMedicament;
	}

	public void setOperationMedicament(String operationMedicament) {
		OperationMedicament = operationMedicament;
	}

	public String getOperationTime() {
		return OperationTime;
	}

	public void setOperationTime(String operationTime) {
		OperationTime = operationTime;
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
		return "OperationNote [OperationID=" + OperationID + ", OperationName=" + OperationName + ", OperationRoomID="
				+ OperationRoomID + ", OperationHeadID=" + OperationHeadID + ", OperationHeadName=" + OperationHeadName
				+ ", PIID=" + PIID + ", PIName=" + PIName + ", PIPhoneNumber=" + PIPhoneNumber + ", PITeamName="
				+ PITeamName + ", ExperimentID=" + ExperimentID + ", ExperimentName=" + ExperimentName + ", AnimalID="
				+ AnimalID + ", OperationAim=" + OperationAim + ", OperationResult=" + OperationResult
				+ ", OperationExcuter=" + OperationExcuter + ", OperationEquipment=" + OperationEquipment
				+ ", OperationMedicament=" + OperationMedicament + ", OperationTime=" + OperationTime + ", InputTime="
				+ InputTime + ", IsEstablished=" + IsEstablished + "]";
	}
	
	
}
