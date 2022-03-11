package org.g7.domin;

import java.io.Serializable;

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
public class Application_Information implements Serializable{
	public String applicationID;
	public String applicationName;
	public String applicationOperateType;
	public String applicationOperateContent;
	public String recordtype;
	public String experimentID;
	public String operationID;
	public String inspectID;
	public String discussionID;
	public String rollinID;
	public String rolloutID;
	public String applicantID;
	public String applicantName;
	public String applicantPhoneNumber;
	public String departmentID;
	public String departmentName;		
	public String applicationTime;
	public String clerkID;
	public String clerkName;
	public String auditorID;		
	public String auditorName;
	public String auditResult;
	public String auditTime;		
	public String feedback	;
	public String auditStatus;
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
	public String getRecordtype() {
		return recordtype;
	}
	public void setRecordtype(String recordtype) {
		this.recordtype = recordtype;
	}
	public String getExperimentID() {
		return experimentID;
	}
	public void setExperimentID(String experimentID) {
		this.experimentID = experimentID;
	}
	public String getOperationID() {
		return operationID;
	}
	public void setOperationID(String operationID) {
		this.operationID = operationID;
	}
	public String getInspectID() {
		return inspectID;
	}
	public void setInspectID(String inspectID) {
		this.inspectID = inspectID;
	}
	public String getDiscussionID() {
		return discussionID;
	}
	public void setDiscussionID(String discussionID) {
		this.discussionID = discussionID;
	}
	public String getRollinID() {
		return rollinID;
	}
	public void setRollinID(String rollinID) {
		this.rollinID = rollinID;
	}
	public String getRolloutID() {
		return rolloutID;
	}
	public void setRolloutID(String rolloutID) {
		this.rolloutID = rolloutID;
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
	@Override
	public String toString() {
		return "Application_Information [applicationID=" + applicationID + ", applicationName=" + applicationName
				+ ", applicationOperateType=" + applicationOperateType + ", applicationOperateContent="
				+ applicationOperateContent + ", recordtype=" + recordtype + ", experimentID=" + experimentID
				+ ", operationID=" + operationID + ", inspectID=" + inspectID + ", discussionID=" + discussionID
				+ ", rollinID=" + rollinID + ", rolloutID=" + rolloutID + ", applicantID=" + applicantID
				+ ", applicantName=" + applicantName + ", applicantPhoneNumber=" + applicantPhoneNumber
				+ ", departmentID=" + departmentID + ", departmentName=" + departmentName + ", applicationTime="
				+ applicationTime + ", clerkID=" + clerkID + ", clerkName=" + clerkName + ", auditorID=" + auditorID
				+ ", auditorName=" + auditorName + ", auditResult=" + auditResult + ", auditTime=" + auditTime
				+ ", feedback=" + feedback + ", auditStatus=" + auditStatus + "]";
	}
	
}
