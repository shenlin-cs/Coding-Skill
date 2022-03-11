package org.g7.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import org.g7.domin.Application;

/**
 * BookMapper接口
 * */
public interface ApplicationMapper {

	/**
	 * 查询�?有图�?
	 * @return 图书对象集合
	 * */
	@Insert(" insert into g7_application_information(ApplicationID,ApplicationName,"
			+ "ApplicationOperateType,ApplicationOperateContent,RecordType,ExperimentID,"
			+ "OperationID,InspectID,DiscussionID,RollinID,RolloutID,ApplicantID,"
			+ "ApplicantName,ApplicantPhoneNumber,DepartmentID,DepartmentName,"
			+ "ApplicationTime,ClerkID,ClerkName,AuditStatus) values(#{ApplicationID},#{ApplicationName},"
			+ "#{ApplicationOperateType},#{ApplicationOperateContent},#{RecordType},#{ExperimentID},"
			+ "#{OperationID},#{InspectID},#{DiscussionID},#{RollinID},"
			+ "#{RolloutID},#{ApplicantID},#{ApplicantName},#{ApplicantPhoneNumber},"
			+ "#{DepartmentID},#{DepartmentName},#{ApplicationTime},#{ClerkID},"
			+ "#{ClerkName},#{AuditStatus})")
	int InsertOne(@Param("ApplicationID")String ApplicationID,@Param("ApplicationName")String ApplicationName,
			@Param("ApplicationOperateType")String ApplicationOperateType,@Param("ApplicationOperateContent")String ApplicationOperateContent,
			@Param("RecordType")String RecordType,@Param("ExperimentID")String ExperimentID,
			@Param("OperationID")String OperationID,@Param("InspectID")String InspectID,
			@Param("DiscussionID")String DiscussionID,@Param("RollinID")String RollinID,
			@Param("RolloutID")String RolloutID,@Param("ApplicantID")String ApplicantID,
			@Param("ApplicantName")String ApplicantName,@Param("ApplicantPhoneNumber")String ApplicantPhoneNumber,
			@Param("DepartmentID")String DepartmentID,@Param("DepartmentName")String DepartmentName,
			@Param("ApplicationTime")String ApplicationTime,@Param("ClerkID")String ClerkID,
			@Param("ClerkName")String ClerkName,@Param("AuditStatus")String AuditStatus);
	
	@Select("select * from g7_application_information where AuditStatus = #{AuditStatus} and FeedbackStatus=#{FeedbackStatus} order by applicationtime")
	List<Application> findAllExaminedApplication(@Param("AuditStatus")String AuditStatus,@Param("FeedbackStatus")String FeedbackStatus);
	
	@Select("select * from g7_application_information where ApplicationID = #{ApplicationID} ")
	Application getApplicationInfo(@Param("ApplicationID")String ApplicationID);
	
	@Select("select * from g7_application_information where ApplicationTime between #{startTime} and #{endTime} order by applicationtime")
	List<Application> findApplicationByTime(@Param("startTime")String startTime,@Param("endTime")String endTime);
	
	@Select("select * from g7_application_information where DepartmentID = #{DepartmentID} order by applicationtime")
	List<Application> findApplicationByDepartment(@Param("DepartmentID")String DepartmentID);
	
	@Select("select * from g7_application_information order by applicationtime")
	List<Application> findApplication();
	
	@Update("update g7_application_information set FeedbackStatus=#{FeedbackStatus} where ApplicationId=#{ApplicationId}")
	int updateApplicationFeedbackStatus(@Param("FeedbackStatus")String FeedbackStatus,@Param("ApplicationId")String ApplicationId);
	
}
