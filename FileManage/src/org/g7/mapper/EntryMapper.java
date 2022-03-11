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

public interface EntryMapper {
	@Insert(" insert into g7_checknote(CheckID,CheckRoomID,CheckHeadID,CheckHeadName,"  
			+"PIID,PIName,PIPhoneNumber,PITeamName,ExperimentID,ExperimentName,"  
			+"AnimalID,ParticipantsNumber,CheckAim,CheckResult,CheckExcuter,CheckEquipment,"  
			+"CheckMedicament,CheckTime,InputTime,IsEstablished) values(#{CheckID},#{CheckRoomID},"
			+ "#{CheckHeadID},#{CheckHeadName},#{PIID},#{PIName},#{PIPhoneNumber},#{PITeamName},"
			+ "#{ExperimentID},#{ExperimentName},#{AnimalID},#{ParticipantsNumber},#{CheckAim},#{CheckResult},"
			+ "#{CheckExcuter},#{CheckEquipment},#{CheckMedicament},#{CheckTime},#{InputTime},#{IsEstablished})")
			
	int Insert_check(@Param("CheckID")String CheckID,
			@Param("CheckRoomID")String CheckRoomID,
			@Param("CheckHeadID")String CheckHeadID,
			@Param("CheckHeadName")String CheckHeadName,		
			@Param("PIID")String PIID,
			@Param("PIName")String PIName,
			@Param("PIPhoneNumber")String PIPhoneNumber,
			@Param("PITeamName")String PITeamName,
			@Param("ExperimentID")String ExperimentID,
			@Param("ExperimentName")String ExperimentName,
			@Param("AnimalID")String AnimalID,			
			@Param("ParticipantsNumber")String ParticipantsNumber,			
			@Param("CheckAim")String CheckAim,
			@Param("CheckResult")String CheckResult,
			@Param("CheckExcuter")String CheckExcuter,
			@Param("CheckEquipment")String CheckEquipment,
			@Param("CheckMedicament")String CheckMedicament,
			@Param("CheckTime")String CheckTime,
			@Param("InputTime")String InputTime,
			@Param("IsEstablished")String IsEstablished
			);	
	
	@Insert(" insert into g7_discussionnote(DiscussionID,DiscussionName,"
			+ "DiscussionRoomID,DiscussionHeadID,DiscussionHeadName,"
			+ "PIID,PIName,PIPhoneNumber,PITeamName,ExperimentID,ExperimentName,AnimalID,"
			+ "DiscussionAim,DiscussionResult,DiscussionExcuter,DiscussionEquipment,"
			+ "DiscussionMedicament,DiscussionTime,InputTime,IsEstablished) values(#{DiscussionID},#{DiscussionName},"
			+ "#{DiscussionRoomID},#{DiscussionHeadID},#{DiscussionHeadName},#{PIID},#{PIName},"
			+ "#{PIPhoneNumber},#{PITeamName},#{ExperimentID},"
			+ "#{ExperimentName},#{AnimalID},#{DiscussionAim},#{DiscussionResult},"
			+ "#{DiscussionExcuter},#{DiscussionEquipment},#{DiscussionMedicament},"
			+ "#{DiscussionTime},#{InputTime},#{IsEstablished})")
	int Insert_discussion(@Param("DiscussionID")String DiscussionID,
			@Param("DiscussionName")String DiscussionName,
			@Param("DiscussionRoomID")String DiscussionRoomID,
			@Param("DiscussionHeadID")String DiscussionHeadID,
			@Param("DiscussionHeadName")String DiscussionHeadName,
			@Param("PIID")String PIID,
			@Param("PIName")String PIName,
			@Param("PIPhoneNumber")String PIPhoneNumber,
			@Param("PITeamName")String PITeamName,
			@Param("ExperimentID")String ExperimentID,
			@Param("ExperimentName")String ExperimentName,
			@Param("AnimalID")String AnimalID,
			@Param("DiscussionAim")String DiscussionAim,
			@Param("DiscussionResult")String DiscussionResult,
			@Param("DiscussionExcuter")String DiscussionExcuter,
			@Param("DiscussionEquipment")String DiscussionEquipment,
			@Param("DiscussionMedicament")String DiscussionMedicament,
			@Param("DiscussionTime")String DiscussionTime,
			@Param("InputTime")String InputTime,
			@Param("IsEstablished")String IsEstablished
			);	
	
	@Insert(" insert into g7_experimentnote(Name,ExperimentID,"
			+ "EmployeeID,Contact,PIName,PIID,Department,BranchName,AnimalID,"
			+ "AnimalSpecies,ExperimentRoom,ExperimentStartTime,ExperimentEndTime,"
			+ "ExperimentNoteTime,ExperimentPurpose,ExperimentContent,ExperimentStep,"
			+ "ExperimentConclusion,ExperimentNote) values(#{Name},#{ExperimentID},"
			+ "#{EmployeeID},#{Contact},#{PIName},#{PIID},#{Department},#{BranchName},#{AnimalID},#{AnimalSpecies},"
			+ "#{ExperimentRoom},#{ExperimentStartTime},#{ExperimentEndTime},"
			+ "#{ExperimentNoteTime},#{ExperimentPurpose},#{ExperimentContent},"
			+ "#{ExperimentStep},#{ExperimentConclusion},"
			+ "#{ExperimentNote})")
	int Insert_experiment(@Param("Name")String Name,
			@Param("ExperimentID")String ExperimentID,
			@Param("EmployeeID")String EmployeeID,
			@Param("Contact")String Contact,
			@Param("PIName")String PIName,
			@Param("PIID")String PIID,
			@Param("Department")String Department,
			@Param("BranchName")String BranchName,
			@Param("AnimalID")String AnimalID,
			@Param("AnimalSpecies")String AnimalSpecies,
			@Param("ExperimentRoom")String ExperimentRoom,
			@Param("ExperimentStartTime")String ExperimentStartTime,
			@Param("ExperimentEndTime")String ExperimentEndTime,
			@Param("ExperimentNoteTime")String ExperimentNoteTime,
			@Param("ExperimentPurpose")String ExperimentPurpose,
			@Param("ExperimentContent")String ExperimentContent,
			@Param("ExperimentStep")String ExperimentStep,
			@Param("ExperimentConclusion")String ExperimentConclusion,
			@Param("ExperimentNote")String ExperimentNote
			);	
	
	@Insert(" insert into g7_operationnote(OperationID,OperationName,OperationRoomID,OperationHeadID,"  
			+"OperationHeadName,PIID,PIName,PIPhoneNumber,PITeamName,ExperimentID,"  
			+"ExperimentName,AnimalID,OperationAim,OperationResult,OperationExcuter,"  
			+"OperationEquipment,OperationMedicament,OperationTime,InputTime,IsEstablished) values(#{OperationID},#{OperationName},"
			+ "#{OperationRoomID},#{OperationHeadID},#{OperationHeadName},#{PIID},#{PIName},#{PIPhoneNumber},"
			+ "#{PITeamName},#{ExperimentID},#{ExperimentName},#{AnimalID},#{OperationAim},#{OperationResult},"
			+ "#{OperationExcuter},#{OperationEquipment},#{OperationMedicament},#{OperationTime},#{InputTime},#{IsEstablished})")
		 	 	 	 			
	int Insert_operation(@Param("OperationID")String OperationID,
			@Param("OperationName")String OperationName,
			@Param("OperationRoomID")String OperationRoomID,
			@Param("OperationHeadID")String OperationHeadID,
			@Param("OperationHeadName")String OperationHeadName,
			@Param("PIID")String PIID,
			@Param("PIName")String PIName,
			@Param("PIPhoneNumber")String PIPhoneNumber,
			@Param("PITeamName")String PITeamName,
			@Param("ExperimentID")String ExperimentID,
			@Param("ExperimentName")String ExperimentName,
			@Param("AnimalID")String AnimalID,
			@Param("OperationAim")String OperationAim,
			@Param("OperationResult")String OperationResult,
			@Param("OperationExcuter")String OperationExcuter,
			@Param("OperationEquipment")String OperationEquipment,
			@Param("OperationMedicament")String OperationMedicament,
			@Param("OperationTime")String OperationTime,
			@Param("InputTime")String InputTime,
			@Param("IsEstablished")String IsEstablished
			);	
	
	@Insert(" insert into g7_transferinnote(TransferinID,researcher_name,researcher_ID,"
			+ "in_charge_person_name,in_charge_person_ID,experimental_object,"
			+ "object_number,item_number,item_name,time,transferfromobject,"
			+ "InputTime,IsEstablished) values(#{TransferinID},#{researcher_name},"
			+ "#{researcher_ID},#{in_charge_person_name},#{in_charge_person_ID},"
			+ "#{experimental_object},#{object_number},#{item_number},#{item_name},"
			+ "#{time},#{transferfromobject},#{InputTime},#{IsEstablished})")
	int Insert_transferin(@Param("TransferinID")String TransferinID,
			@Param("researcher_name")String researcher_name,
			@Param("researcher_ID")String researcher_ID,		
			@Param("in_charge_person_name")String in_charge_person_name,
			@Param("in_charge_person_ID")String in_charge_person_ID,
			@Param("experimental_object")String experimental_object,
			@Param("object_number")String object_number,
			@Param("item_number")String item_number,
			@Param("item_name")String item_name,			
			@Param("time")String time,
			@Param("transferfromobject")String transferfromobject,
			@Param("InputTime")String InputTime,
			@Param("IsEstablished")String IsEstablished
			);	
	
	@Insert(" insert into g7_transferoutnote(TransferoutID,researcher_name,researcher_ID,"
			+ "in_charge_person_name,in_charge_person_ID,experimental_object,"
			+ "object_number,item_number,item_name,time,transferobject,"
			+ "InputTime,IsEstablished) values(#{TransferoutID},#{researcher_name},"
			+ "#{researcher_ID},#{in_charge_person_name},#{in_charge_person_ID},"
			+ "#{experimental_object},#{object_number},#{item_number},#{item_name},"
			+ "#{time},#{transferobject},#{InputTime},#{IsEstablished})")
	int Insert_transferout(@Param("TransferoutID")String TransferoutID,
			@Param("researcher_name")String researcher_name,
			@Param("researcher_ID")String researcher_ID,		
			@Param("in_charge_person_name")String in_charge_person_name,
			@Param("in_charge_person_ID")String in_charge_person_ID,
			@Param("experimental_object")String experimental_object,
			@Param("object_number")String object_number,
			@Param("item_number")String item_number,
			@Param("item_name")String item_name,			
			@Param("time")String time,
			@Param("transferobject")String transferobject,
			@Param("InputTime")String InputTime,
			@Param("IsEstablished")String IsEstablished
			);	
	
	@Select(" select ApplicationID,ApplicationOperateType,ApplicantName,ApplicationTime,AuditStatus,RecordType,ClerkName from g7_application_information where AuditStatus='已审' and ApplicationOperateType like '%增%' and AuditResult='审核通过' and InputStatus='未录入' order by ApplicationTime desc; ")
	List<Audit> Insertlist();
	
	@Update(" update g7_application_information set InputStatus='已录入' where ApplicationID=#{ApplicationID}")

	int UpdateInfor(@Param("ApplicationID")String ApplicationID);
	
	@Select("select CheckID from g7_checknote;")
	List<CheckNote> SearchCheckkey();
	
	@Select("select DiscussionID from g7_discussionnote;")
	List<DiscussionNote> SearchDiscussionkey();
	
	@Select("select ExperimentID from g7_experimentnote;")
	List<ExperimentNote> SearchExperimentkey();
	
	@Select("select OperationID from g7_operationnote;")
	List<OperationNote> SearchOperationkey();
	
	@Select("select TransferinID from g7_transferinnote;")
	List<TransferinNote> SearchTransferinkey();
	
	@Select("select TransferoutID from g7_transferoutnote;")
	List<TransferoutNote> SearchTransferoutkey();

}
