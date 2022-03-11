package org.g7.domin;

public class Animal {
	
	private String AnimalID;
	private String AnimalSpecies;
	private String AnimalGender;
	private String AnimalBirthday;
	private String AnimalLevel;
	private String AnimalRoom;
	private String AnimalRoomChargePerson;
	private String AnimalWeight;
	private String AnimalHealth;
	
	public Animal() {
		super();
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

	public String getAnimalGender() {
		return AnimalGender;
	}

	public void setAnimalGender(String animalGender) {
		AnimalGender = animalGender;
	}

	public String getAnimalBirthday() {
		return AnimalBirthday;
	}

	public void setAnimalBirthday(String animalBirthday) {
		AnimalBirthday = animalBirthday;
	}

	public String getAnimalLevel() {
		return AnimalLevel;
	}

	public void setAnimalLevel(String animalLevel) {
		AnimalLevel = animalLevel;
	}

	public String getAnimalRoom() {
		return AnimalRoom;
	}

	public void setAnimalRoom(String animalRoom) {
		AnimalRoom = animalRoom;
	}

	public String getAnimalRoomChargePerson() {
		return AnimalRoomChargePerson;
	}

	public void setAnimalRoomChargePerson(String animalRoomChargePerson) {
		AnimalRoomChargePerson = animalRoomChargePerson;
	}

	public String getAnimalWeight() {
		return AnimalWeight;
	}

	public void setAnimalWeight(String animalWeight) {
		AnimalWeight = animalWeight;
	}

	public String getAnimalHealth() {
		return AnimalHealth;
	}

	public void setAnimalHealth(String animalHealth) {
		AnimalHealth = animalHealth;
	}

	@Override
	public String toString() {
		return "Animal [AnimalID=" + AnimalID + ", AnimalSpecies=" + AnimalSpecies + ", AnimalGender=" + AnimalGender
				+ ", AnimalBirthday=" + AnimalBirthday + ", AnimalLevel=" + AnimalLevel + ", AnimalRoom=" + AnimalRoom
				+ ", AnimalRoomChargePerson=" + AnimalRoomChargePerson + ", AnimalWeight=" + AnimalWeight
				+ ", AnimalHealth=" + AnimalHealth + "]";
	}	

	
}
