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
public class Application implements Serializable{
	
	private String applicationID;
	private String applicationName;
	private String applicationOperateType;
	private String applicationOperateContent;
	private String recordType;
	private String experimentID;
	private String applicantID;
	private String applicantName;
	private String applicantPhoneNumber;
	private String departmentID;
	private String departmentName;
	private String applicationTime;
	private String clerkID;
	private String clerkName;
	private String auditorID;
	private String auditorName;
	private String auditResult;
	private String auditTime;
	private String feedback;
	private String auditStatus;
	
	
	public Application() {
		super();
		// TODO Auto-generated constructor stub
	}


	public String getApplicationID() {
		return applicationID;
	}


	public void setApplicationID(String applicationID) {
		this.applicationID = applicationID;
	}


	public String getApplicationName() {
		return applicationName;
	}


	public void setApplicationName(String applicationName) {
		this.applicationName = applicationName;
	}


	public String getApplicationOperateType() {
		return applicationOperateType;
	}


	public void setApplicationOperateType(String applicationOperateType) {
		this.applicationOperateType = applicationOperateType;
	}


	public String getApplicationOperateContent() {
		return applicationOperateContent;
	}


	public void setApplicationOperateContent(String applicationOperateContent) {
		this.applicationOperateContent = applicationOperateContent;
	}


	public String getRecordType() {
		return recordType;
	}


	public void setRecordType(String recordType) {
		this.recordType = recordType;
	}


	public String getExperimentID() {
		return experimentID;
	}


	public void setExperimentID(String experimentID) {
		this.experimentID = experimentID;
	}


	public String getApplicantID() {
		return applicantID;
	}


	public void setApplicantID(String applicantID) {
		this.applicantID = applicantID;
	}


	public String getApplicantName() {
		return applicantName;
	}


	public void setApplicantName(String applicantName) {
		this.applicantName = applicantName;
	}


	public String getApplicantPhoneNumber() {
		return applicantPhoneNumber;
	}


	public void setApplicantPhoneNumber(String applicantPhoneNumber) {
		this.applicantPhoneNumber = applicantPhoneNumber;
	}


	public String getDepartmentID() {
		return departmentID;
	}


	public void setDepartmentID(String departmentID) {
		this.departmentID = departmentID;
	}


	public String getDepartmentName() {
		return departmentName;
	}


	public void setDepartmentName(String departmentName) {
		this.departmentName = departmentName;
	}


	public String getApplicationTime() {
		return applicationTime;
	}


	public void setApplicationTime(String applicationTime) {
		this.applicationTime = applicationTime;
	}


	public String getClerkID() {
		return clerkID;
	}


	public void setClerkID(String clerkID) {
		this.clerkID = clerkID;
	}


	public String getClerkName() {
		return clerkName;
	}


	public void setClerkName(String clerkName) {
		this.clerkName = clerkName;
	}


	public String getAuditorID() {
		return auditorID;
	}


	public void setAuditorID(String auditorID) {
		this.auditorID = auditorID;
	}


	public String getAuditorName() {
		return auditorName;
	}


	public void setAuditorName(String auditorName) {
		this.auditorName = auditorName;
	}


	public String getAuditResult() {
		return auditResult;
	}


	public void setAuditResult(String auditResult) {
		this.auditResult = auditResult;
	}


	public String getAuditTime() {
		return auditTime;
	}


	public void setAuditTime(String auditTime) {
		this.auditTime = auditTime;
	}


	public String getFeedback() {
		return feedback;
	}


	public void setFeedback(String feedback) {
		this.feedback = feedback;
	}


	public String getAuditStatus() {
		return auditStatus;
	}


	public void setAuditStatus(String auditStatus) {
		this.auditStatus = auditStatus;
	}

}
