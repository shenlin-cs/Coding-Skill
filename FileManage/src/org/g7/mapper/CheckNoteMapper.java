package org.g7.mapper;

import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Update;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Select;

import org.g7.domin.CheckNote;

public interface CheckNoteMapper {
	
	@Update("update g7_checknote set CheckRoomID = #{CheckRoomID},"
			+ "CheckHeadID = #{CheckHeadID},CheckHeadName = #{CheckHeadName},"
			+ "PIID = #{PIID},PIName = #{PIName},"
			+ "PIPhoneNumber = #{PIPhoneNumber},PITeamName = #{PITeamName},"
			+ "ExperimentID = #{ExperimentID},ExperimentName = #{ExperimentName},"
			+ "AnimalID = #{AnimalID},ParticipantsNumber = #{ParticipantsNumber},"
			+ "CheckAim = #{CheckAim},CheckResult = #{CheckResult},"
			+ "CheckExcuter = #{CheckExcuter},CheckEquipment = #{CheckEquipment},"
			+ "CheckMedicament = #{CheckMedicament},CheckTime = #{CheckTime},"
			+ "isEstablished = #{isEstablished} where CheckID = #{CheckID}")
	int UpdateCheckNote(@Param("CheckRoomID")String CheckRoomID,
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
			@Param("isEstablished")String isEstablished,
			@Param("CheckID")String CheckID);
	
	@Delete("delete from g7_checknote where CheckID = #{CheckID}")
	int DeleteCheckNote(@Param("CheckID")String CheckID);
	
	@Select("select * from g7_checknote where CheckID = #{CheckID}")
	CheckNote GetCheckNote(@Param("CheckID")String CheckID);

}
