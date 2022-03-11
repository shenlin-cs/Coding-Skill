package org.g7.service;

import org.apache.ibatis.annotations.Param;
import org.g7.domin.APIResult;
import org.g7.domin.CheckNote;

/**
 * User服务层接�?
 * */
public interface CheckNoteService {
	
	int UpdateCheckNote(String CheckRoomID,
			String CheckHeadID,
			String CheckHeadName,
			String PIID,
			String PIName,
			String PIPhoneNumber,
			String PITeamName,
			String ExperimentID,
			String ExperimentName,
			String AnimalID,
			String ParticipantsNumber,
			String CheckAim,
			String CheckResult,
			String CheckExcuter,
			String CheckEquipment,
			String CheckMedicament,
			String CheckTime,
			String isEstablished,
			String CheckID);
	
	int DeleteCheckNote(String CheckID);
	
	APIResult GetCheckNote(String CheckID);
	
	CheckNote CheckNoteInfo(String CheckID);
}
