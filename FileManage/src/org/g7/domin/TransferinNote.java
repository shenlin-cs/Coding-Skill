package org.g7.domin;
import java.io.Serializable;

public class TransferinNote implements Serializable{
	private String TransferinID;
	private String researcher_name;
	private String researcher_ID;
	private String in_charge_person_name;
	private String in_charge_person_ID;
	private String experimental_object;
	private String object_number;
	private String item_number;
	private String item_name;
	private String time;
	private String transferfromobject;
	private String InputTime;
	private String IsEstablished;
	
	public String getTransferinID() {
		return TransferinID;
	}

	public void setTransferinID(String transferinID) {
		TransferinID = transferinID;
	}

	public TransferinNote() {
		super();
	}

	public String getResearcher_name() {
		return researcher_name;
	}

	public void setResearcher_name(String researcher_name) {
		this.researcher_name = researcher_name;
	}

	public String getResearcher_ID() {
		return researcher_ID;
	}

	public void setResearcher_ID(String researcher_ID) {
		this.researcher_ID = researcher_ID;
	}

	public String getIn_charge_person_name() {
		return in_charge_person_name;
	}

	public void setIn_charge_person_name(String in_charge_person_name) {
		this.in_charge_person_name = in_charge_person_name;
	}

	public String getIn_charge_person_ID() {
		return in_charge_person_ID;
	}

	public void setIn_charge_person_ID(String in_charge_person_ID) {
		this.in_charge_person_ID = in_charge_person_ID;
	}

	public String getExperimental_object() {
		return experimental_object;
	}

	public void setExperimental_object(String experimental_object) {
		this.experimental_object = experimental_object;
	}

	public String getObject_number() {
		return object_number;
	}

	public void setObject_number(String object_number) {
		this.object_number = object_number;
	}

	public String getItem_number() {
		return item_number;
	}

	public void setItem_number(String item_number) {
		this.item_number = item_number;
	}

	public String getItem_name() {
		return item_name;
	}

	public void setItem_name(String item_name) {
		this.item_name = item_name;
	}

	public String getTime() {
		return time;
	}

	public void setTime(String time) {
		this.time = time;
	}

	public String getTransferfromobject() {
		return transferfromobject;
	}

	public void setTransferfromobject(String transferfromobject) {
		this.transferfromobject = transferfromobject;
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
		return "TransferinNote [TransferinID=" + TransferinID + ", researcher_name=" + researcher_name
				+ ", researcher_ID=" + researcher_ID + ", in_charge_person_name=" + in_charge_person_name
				+ ", in_charge_person_ID=" + in_charge_person_ID + ", experimental_object=" + experimental_object
				+ ", object_number=" + object_number + ", item_number=" + item_number + ", item_name=" + item_name
				+ ", time=" + time + ", transferfromobject=" + transferfromobject + ", InputTime=" + InputTime
				+ ", IsEstablished=" + IsEstablished + "]";
	}

	
}
