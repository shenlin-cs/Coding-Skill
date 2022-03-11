package org.g7.domin;
import java.io.Serializable;

public class ExperimentNote implements Serializable{
	private String Name;
	private String ExperimentID;
	private String EmployeeID;
	private String Contact;
	private String PIName;
	private String PIID;
	private String Department;
	private String BranchName;
	private String AnimalID;
	private String AnimalSpecies;
	private String ExperimentRoom;
	private String ExperimentDate;
	private String ExperimentStartTime;
	private String ExperimentEndTime;
	private String ExperimentNoteTime;
	private String ExperimentPurpose;
	private String ExperimentContent;
	private String ExperimentStep;
	private String ExperimentConclusion;
	private String ExperimentNote;
	public ExperimentNote() {
		super();
	}
	public String getName() {
		return Name;
	}
	public void setName(String name) {
		Name = name;
	}
	public String getExperimentID() {
		return ExperimentID;
	}
	public void setExperimentID(String experimentID) {
		ExperimentID = experimentID;
	}
	public String getEmployeeID() {
		return EmployeeID;
	}
	public void setEmployeeID(String employeeID) {
		EmployeeID = employeeID;
	}
	public String getContact() {
		return Contact;
	}
	public void setContact(String contact) {
		Contact = contact;
	}
	public String getPIName() {
		return PIName;
	}
	public void setPIName(String pIName) {
		PIName = pIName;
	}
	public String getPIID() {
		return PIID;
	}
	public void setPIID(String pIID) {
		PIID = pIID;
	}
	public String getDepartment() {
		return Department;
	}
	public void setDepartment(String department) {
		Department = department;
	}
	public String getBranchName() {
		return BranchName;
	}
	public void setBranchName(String branchName) {
		BranchName = branchName;
	}
	public String getAnimalID() {
		return AnimalID;
	}
	public void setAnimalID(String animalID) {
		AnimalID = animalID;
	}
	public String getAnimalSpecies() {
		return AnimalSpecies;
	}
	public void setAnimalSpecies(String animalSpecies) {
		AnimalSpecies = animalSpecies;
	}
	public String getExperimentRoom() {
		return ExperimentRoom;
	}
	public void setExperimentRoom(String experimentRoom) {
		ExperimentRoom = experimentRoom;
	}
	public String getExperimentDate() {
		return ExperimentDate;
	}
	public void setExperimentDate(String experimentDate) {
		ExperimentDate = experimentDate;
	}
	public String getExperimentStartTime() {
		return ExperimentStartTime;
	}
	public void setExperimentStartTime(String experimentStartTime) {
		ExperimentStartTime = experimentStartTime;
	}
	public String getExperimentEndTime() {
		return ExperimentEndTime;
	}
	public void setExperimentEndTime(String experimentEndTime) {
		ExperimentEndTime = experimentEndTime;
	}
	public String getExperimentNoteTime() {
		return ExperimentNoteTime;
	}
	public void setExperimentNoteTime(String experimentNoteTime) {
		ExperimentNoteTime = experimentNoteTime;
	}
	public String getExperimentPurpose() {
		return ExperimentPurpose;
	}
	public void setExperimentPurpose(String experimentPurpose) {
		ExperimentPurpose = experimentPurpose;
	}
	public String getExperimentContent() {
		return ExperimentContent;
	}
	public void setExperimentContent(String experimentContent) {
		ExperimentContent = experimentContent;
	}
	public String getExperimentStep() {
		return ExperimentStep;
	}
	public void setExperimentStep(String experimentStep) {
		ExperimentStep = experimentStep;
	}
	public String getExperimentConclusion() {
		return ExperimentConclusion;
	}
	public void setExperimentConclusion(String experimentConclusion) {
		ExperimentConclusion = experimentConclusion;
	}
	public String getExperimentNote() {
		return ExperimentNote;
	}
	public void setExperimentNote(String experimentNote) {
		ExperimentNote = experimentNote;
	}
	@Override
	public String toString() {
		return "ExperimentNote [Name=" + Name + ", ExperimentID=" + ExperimentID + ", EmployeeID=" + EmployeeID
				+ ", Contact=" + Contact + ", PIName=" + PIName + ", PIID=" + PIID + ", Department=" + Department
				+ ", BranchName=" + BranchName + ", AnimalID=" + AnimalID + ", AnimalSpecies=" + AnimalSpecies
				+ ", ExperimentRoom=" + ExperimentRoom + ", ExperimentDate=" + ExperimentDate + ", ExperimentStartTime="
				+ ExperimentStartTime + ", ExperimentEndTime=" + ExperimentEndTime + ", ExperimentNoteTime="
				+ ExperimentNoteTime + ", ExperimentPurpose=" + ExperimentPurpose + ", ExperimentContent="
				+ ExperimentContent + ", ExperimentStep=" + ExperimentStep + ", ExperimentConclusion="
				+ ExperimentConclusion + ", ExperimentNote=" + ExperimentNote + "]";
	}
	
}
