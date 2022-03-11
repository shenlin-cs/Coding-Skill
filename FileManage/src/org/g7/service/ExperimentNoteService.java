package org.g7.service;

import org.apache.ibatis.annotations.Param;
import org.g7.domin.APIResult;
import org.g7.domin.ExperimentNote;

/**
 * User服务层接�?
 * */
public interface ExperimentNoteService {
	
	int UpdateExperimentNote(String Name,
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
			String ExperimentNote);
	
	int DeleteExperimentNote(String ExperimentID);
	
	APIResult GetExperimentNote(String ExperimentID);
	
	ExperimentNote ExperimentNoteInfo(String ExperimentID);
}
