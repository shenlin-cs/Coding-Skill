package org.g7.service.impl;

import java.util.List;

import org.g7.domin.APIResult;
import org.g7.domin.CheckNote;
import org.g7.domin.Note;
import org.g7.domin.ResultCode;
import org.g7.mapper.CheckNoteMapper;
import org.g7.service.CheckNoteService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;


@Transactional(propagation=Propagation.REQUIRED,isolation=Isolation.DEFAULT)
@Service("checknoteService")
public class CheckNoteServiceImpl implements CheckNoteService {
	
	@Autowired
	private CheckNoteMapper checknoteMapper;

	@Transactional(readOnly=true)
	@Override
	public APIResult GetCheckNote(String CheckID) {
		CheckNote res =  checknoteMapper.GetCheckNote(CheckID);
		if(res!=null)
		{
			return APIResult.success(res);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=false)
	@Override
	public int UpdateCheckNote(String CheckRoomID,
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
			String CheckID) {
		return checknoteMapper.UpdateCheckNote(CheckRoomID, CheckHeadID, CheckHeadName, PIID, PIName, PIPhoneNumber, PITeamName, ExperimentID, ExperimentName, AnimalID, ParticipantsNumber, CheckAim, CheckResult, CheckExcuter, CheckEquipment, CheckMedicament, CheckTime, isEstablished, CheckID);
	}
	
	@Transactional(readOnly=false)
	@Override
	public int DeleteCheckNote(String CheckID) {
		return checknoteMapper.DeleteCheckNote(CheckID);
	}
	
	@Transactional(readOnly=true)
	@Override
	public CheckNote CheckNoteInfo(String CheckID) {
		return checknoteMapper.GetCheckNote(CheckID);
	}
	

}
