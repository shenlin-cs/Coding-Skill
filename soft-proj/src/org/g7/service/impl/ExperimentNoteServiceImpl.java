package org.g7.service.impl;

import java.util.List;

import org.g7.domin.APIResult;
import org.g7.domin.ExperimentNote;
import org.g7.domin.Note;
import org.g7.domin.ResultCode;
import org.g7.mapper.ExperimentNoteMapper;
import org.g7.service.ExperimentNoteService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;


@Transactional(propagation=Propagation.REQUIRED,isolation=Isolation.DEFAULT)
@Service("experimentnoteService")
public class ExperimentNoteServiceImpl implements ExperimentNoteService {
	
	@Autowired
	private ExperimentNoteMapper experimentnoteMapper;

	@Transactional(readOnly=true)
	@Override
	public APIResult GetExperimentNote(String ExperimentID) {
		ExperimentNote res =  experimentnoteMapper.GetExperimentNote(ExperimentID);
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
	public int UpdateExperimentNote(String Name,
			String ExperimentID,
			String EmployeeID,
			String Contact,
			String PIName,
			String PIID,
			String Department,
			String BranchName,
			String AnimalID,
			String AnimalSpecies,
			String ExperimentRoom,
			String ExperimentStartTime,
			String ExperimentEndTime,
			String ExperimentPurpose,
			String ExperimentContent,
			String ExperimentStep,
			String ExperimentConclusion,
			String ExperimentNote) {
		return experimentnoteMapper.UpdateExperimentNote(Name, ExperimentID, EmployeeID, Contact, PIName, PIID, Department, BranchName, AnimalID, AnimalSpecies, ExperimentRoom, ExperimentStartTime, ExperimentEndTime, ExperimentPurpose, ExperimentContent, ExperimentStep, ExperimentConclusion, ExperimentNote);
	}
	
	@Transactional(readOnly=false)
	@Override
	public int DeleteExperimentNote(String ExperimentID) {
		return experimentnoteMapper.DeleteExperimentNote(ExperimentID);
	}
	
	@Transactional(readOnly=true)
	@Override
	public ExperimentNote ExperimentNoteInfo(String ExperimentID) {
		return experimentnoteMapper.GetExperimentNote(ExperimentID);
	}
	

}
