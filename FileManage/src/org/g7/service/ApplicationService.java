package org.g7.service;

import java.util.Date;
import java.util.List;

import org.apache.ibatis.annotations.Param;
import org.g7.domin.APIResult;
import org.g7.domin.Application;

/**
 * Book服务层接�?
 * */
public interface ApplicationService {
	
	/**
	 * 查找�?有图�?
	 * @return Book对象集合
	 * */
	int Insert(String ApplicationID, String ApplicationName, String ApplicationOperateType,
			  String ApplicationOperateContent, String RecordType, String ExperimentID,
			  String OperationID, String InspectID, String DiscussionID,
			  String RollinID, String RolloutID, String ApplicantID,
			  String ApplicantName, String ApplicantPhoneNumber, String DepartmentID,
			  String DepartmentName, String ApplicationTime, String ClerkID,
			  String ClerkName, String AuditStatus);
	
	APIResult findAllExaminedApplication(String AuditStatus,String FeedbackStatus);
	
	APIResult getApplicationInfo(String ApplicationID);
	
	APIResult findApplicationByTime(String startTime, String endTime);
	
	APIResult findApplicationByDepartment(String DepartmentID);
	
	APIResult findApplication();
	
	Application GetApplicationInfo(String ApplicationID);
	
	int updateApplicationFeedbackStatus(String FeedbackStatus,String ApplicationId);

}
