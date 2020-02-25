package org.g7.service.impl;

import java.util.Date;
import java.util.List;

import org.apache.ibatis.annotations.Param;
import org.g7.domin.APIResult;
import org.g7.domin.Application;
import org.g7.domin.ResultCode;
import org.g7.domin.User;
import org.g7.mapper.ApplicationMapper;
import org.g7.service.ApplicationService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

/**
 * Book服务层接口实现类
 * @Service("applicationService")用于将当前类注释为一个Spring的bean，名为bookService
 * */
@Transactional(propagation=Propagation.REQUIRED,isolation=Isolation.DEFAULT)
@Service("applicationService")
public class ApplicationServiceImpl implements ApplicationService {
	
	/**
	 * 自动注入BookMapper
	 * */
	@Autowired
	private ApplicationMapper applicationMapper;

	/**
	 * BookService接口getAll方法实现
	 * @see { BookService }
	 * */
	@Transactional(readOnly=false)
	@Override
	public int Insert(String ApplicationID, String ApplicationName, String ApplicationOperateType,
			  String ApplicationOperateContent, String RecordType, String ExperimentID,
			  String OperationID, String InspectID, String DiscussionID,
			  String RollinID, String RolloutID, String ApplicantID,
			  String ApplicantName, String ApplicantPhoneNumber, String DepartmentID,
			  String DepartmentName, String ApplicationTime, String ClerkID,
			  String ClerkName, String AuditStatus) {
		return applicationMapper.InsertOne( ApplicationID,  ApplicationName,  ApplicationOperateType,
				   ApplicationOperateContent,  RecordType,  ExperimentID,
				   OperationID,  InspectID,  DiscussionID,
				   RollinID,  RolloutID,  ApplicantID,
				   ApplicantName,  ApplicantPhoneNumber,  DepartmentID,
				   DepartmentName,  ApplicationTime,  ClerkID,
				   ClerkName, AuditStatus);
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult findAllExaminedApplication(String AuditStatus,String FeedbackStatus) {
		List<Application> data =  applicationMapper.findAllExaminedApplication(AuditStatus,FeedbackStatus);
		if(data.size()!=0)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult getApplicationInfo(String ApplicationID) {
		Application data = applicationMapper.getApplicationInfo(ApplicationID);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult findApplicationByTime(String startTime, String endTime) {
		List<Application> data =  applicationMapper.findApplicationByTime(startTime, endTime);
		if(data.size()!=0)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult findApplicationByDepartment(String DepartmentID) {
		List<Application> data =  applicationMapper.findApplicationByDepartment(DepartmentID);
		if(data.size()!=0)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult findApplication() {
		List<Application> data =  applicationMapper.findApplication();
		if(data.size()!=0)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public Application GetApplicationInfo(String ApplicationID) {
		return applicationMapper.getApplicationInfo(ApplicationID);
	}
	
	@Transactional(readOnly=false)
	@Override
	public int updateApplicationFeedbackStatus(String FeedbackStatus,String ApplicationId) {
		return applicationMapper.updateApplicationFeedbackStatus(FeedbackStatus, ApplicationId);
	}

}
