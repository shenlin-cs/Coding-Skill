package org.g7.domin;

import java.io.Serializable;
import java.util.Date;

/**
 * CREATE TABLE tb_book (
	id INT (11) PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR (54),
	author VARCHAR (54),
	publicationdate DATE ,
	publication VARCHAR (150),
	price DOUBLE ,
	image VARCHAR (54),
	remark VARCHAR (600)
);
 * */
public class Audit implements Serializable{
	private String applicationID;
	private String applicationOperateType;
	private String applicantName;
	private String applicationTime;
	private String auditStatus;	
	private String recordtype;
	private String clerkname;
	private String auditorName;
	public Audit() {
		
	}
	public String getAuditorName() {
		return auditorName;
	}
	public void setAuditorName(String auditorName) {
		this.auditorName = auditorName;
	}
	public String getAuditStatus() {
		return auditStatus;
	}
	public void setAuditStatus(String auditStatus) {
		this.auditStatus = auditStatus;
	}
	public String getRecordtype() {
		return recordtype;
	}
	public void setRecordtype(String recordtype) {
		this.recordtype = recordtype;
	}
	public String getClerkname() {
		return clerkname;
	}
	public void setClerkname(String clerkname) {
		this.clerkname = clerkname;
	}
	public String getApplicationID() {
		return applicationID;
	}
	public void setApplicationID(String applicationID) {
		this.applicationID = applicationID;
	}
	public String getApplicationOperateType() {
		return applicationOperateType;
	}
	public void setApplicationOperateType(String applicationOperateType) {
		this.applicationOperateType = applicationOperateType;
	}
	public String getApplicantName() {
		return applicantName;
	}
	public void setApplicantName(String applicantName) {
		this.applicantName = applicantName;
	}
	public String getApplicationTime() {
		return applicationTime;
	}
	public void setApplicationTime(String applicationTime) {
		this.applicationTime = applicationTime;
	}
	@Override
	public String toString() {
		return "Audit [applicationID=" + applicationID + ", applicationOperateType=" + applicationOperateType
				+ ", applicantName=" + applicantName + ", applicationTime=" + applicationTime + ", auditStatus="
				+ auditStatus + ", recordtype=" + recordtype + ", clerkname=" + clerkname + ", auditorName="
				+ auditorName + "]";
	}	
}
