package org.g7.domin;

public class NoteInfo {
	private String experimentid;
	private String recordid;
	private String type;
	private String staffid;
	private String staffname;
	private String time;
	public String getExperimentid() {
		return experimentid;
	}
	public void setExperimentid(String experimentid) {
		this.experimentid = experimentid;
	}
	public String getRecordid() {
		return recordid;
	}
	public void setRecordid(String recordid) {
		this.recordid = recordid;
	}
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public String getStaffid() {
		return staffid;
	}
	public void setStaffid(String staffid) {
		this.staffid = staffid;
	}
	public String getStaffname() {
		return staffname;
	}
	public void setStaffname(String staffname) {
		this.staffname = staffname;
	}
	public String getTime() {
		return time;
	}
	public void setTime(String time) {
		this.time = time;
	}
	@Override
	public String toString() {
		return "noteinfo [experimentid=" + experimentid + ", recordid=" + recordid + ", type=" + type + ", staffid="
				+ staffid + ", staffname=" + staffname + ", time=" + time + "]";
	}
	
	
	
}
