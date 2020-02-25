package org.g7.mapper;
import org.g7.domin.Application_Information;
import org.g7.domin.Audit;
import org.g7.domin.ExperimentNote;
import org.g7.domin.filelocation;
import org.g7.domin.ExperimentNote;

import java.util.List;

import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;
import org.apache.ibatis.annotations.Param;
/**
 * BookMapper接口
 * */
public interface ExperimentNoteMapper {

	@Select(" select Name,ExperimentID,PIID,AnimalID,AnimalSpecies,ExperimentPurpose,ExperimentConclusion from g7_experimentnote order by ExperimentStartTime desc; ")
	List<ExperimentNote> findAll();
	
	@Update("update g7_experimentnote set Name = #{Name},"
			+ "ExperimentID = #{ExperimentID},EmployeeID = #{EmployeeID},"
			+ "Contact = #{Contact},PIName = #{PIName},"
			+ "PIID = #{PIID},Department = #{Department},"
			+ "BranchName = #{BranchName},AnimalID = #{AnimalID},"
			+ "AnimalSpecies = #{AnimalSpecies},"
			+ "ExperimentRoom = #{ExperimentRoom},ExperimentStartTime = #{ExperimentStartTime},"
			+ "ExperimentEndTime = #{ExperimentEndTime},"
			+ "ExperimentPurpose = #{ExperimentPurpose},ExperimentContent = #{ExperimentContent},"
			+ "ExperimentStep = #{ExperimentStep},ExperimentConclusion = #{ExperimentConclusion}, "
			+ "ExperimentNote = #{ExperimentNote} where ExperimentID = #{ExperimentID}")
	int UpdateExperimentNote(@Param("Name")String Name,
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
			@Param("ExperimentPurpose")String ExperimentPurpose,
			@Param("ExperimentContent")String ExperimentContent,
			@Param("ExperimentStep")String ExperimentStep,
			@Param("ExperimentConclusion")String ExperimentConclusion,
			@Param("ExperimentNote")String ExperimentNote);
			
	
	@Delete("delete from g7_experimentnote where ExperimentID = #{ExperimentID}")
	int DeleteExperimentNote(@Param("ExperimentID")String ExperimentID);
	
	@Select("select * from g7_experimentnote where ExperimentID = #{ExperimentID}")
	ExperimentNote GetExperimentNote(@Param("ExperimentID")String ExperimentID);
	
	@Select(" select * from g7_filelocation; ")
	List<filelocation> findAllprintlist();
	
	@Select(" select * from g7_filelocation where IsPrinted=#{isprint}; ")
	List<filelocation> findAllisprint(String isprint);
	
	

}
