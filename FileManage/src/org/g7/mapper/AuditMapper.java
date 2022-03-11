package org.g7.mapper;
import java.util.List;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import org.g7.domin.Audit;
import org.g7.domin.CheckNote;
import org.g7.domin.DiscussionNote;
import org.g7.domin.ExperimentNote;
import org.g7.domin.OperationNote;
import org.g7.domin.TransferinNote;
import org.g7.domin.TransferoutNote;

/**
 * BookMapper鎺ュ彛
 * */
public interface AuditMapper {

	/**
	 * 鏌ヨ鎵?鏈夊浘涔?
	 * @return 鍥句功瀵硅薄闆嗗悎
	 * */
	@Select(" select ApplicationID,ApplicationOperateType,ApplicantName,ApplicationTime,AuditStatus,RecordType,ClerkName from g7_application_information where AuditStatus='未审' order by ApplicationTime desc; ")
	List<Audit> findAll();
	
	@Update(" update g7_application_information set AuditorID=#{AuditorID},"
			+ "AuditorName=#{AuditorName},AuditTime=#{AuditTime},"
			+ "AuditResult=#{AuditResult},Feedback=#{Feedback},AuditStatus='已审' where ApplicationID=#{ApplicationID}")
	int UpdateOne(@Param("ApplicationID")String ApplicationID,@Param("AuditorID")String AuditorID,
			@Param("AuditorName")String AuditorName,@Param("AuditTime")String AuditTime,
			@Param("AuditResult")String AuditResult,@Param("Feedback")String Feedback);	
	
	@Insert(" insert into g7_audit_note(ApplicationID,EmployeeID,"
			+ "AuditDate,AuditComments,AuditResult) values(#{ApplicationID},#{EmployeeID},"
			+ "#{AuditDate},#{AuditComments},#{AuditResult})")
	int InsertAuditNote(@Param("ApplicationID")String ApplicationID,@Param("EmployeeID")String EmployeeID,
			@Param("AuditDate")String AuditDate,@Param("AuditComments")String AuditComments,
			@Param("AuditResult")String AuditResult);	
	
	@Select("select * from g7_experimentnote where ExperimentID = #{ExperimentID}")
	ExperimentNote ExperimentExists(String ExperimentID);
	
	@Select("select * from g7_operationnote where OperationID = #{OperationID}")
	OperationNote OperationExists(String OperationID);
	
	@Select("select * from g7_checknote where CheckID = #{InspectID}")
	CheckNote InspectExists(String InspectID);
	
	@Select("select * from g7_discussionnote where DiscussionID = #{DiscussionID}")
	DiscussionNote DiscussionExists(String DiscussionID);
	
	@Select("select * from g7_transferinnote where TransferinID = #{RollinID}")
	TransferinNote RollInExists(String RollinID);
	
	@Select("select * from g7_transferoutnote where TransferoutID = #{RolloutID}")
	TransferoutNote RollOutExists(String RolloutID);
	
	@Select(" select ApplicationID,ApplicationOperateType,ApplicantName,ApplicationTime,AuditStatus,RecordType,ClerkName from g7_application_information where AuditStatus='已审' and ApplicationOperateType like '%删%' and AuditResult='审核通过' order by ApplicationTime desc; ")
	List<Audit> findDelete();
	
	@Select(" select ApplicationID,ApplicationOperateType,ApplicantName,ApplicationTime,AuditStatus,RecordType,ClerkName from g7_application_information where AuditStatus='已审' and ApplicationOperateType like '%改%' and AuditResult='审核通过' order by ApplicationTime desc; ")
	List<Audit> findUpdate();
	
}
