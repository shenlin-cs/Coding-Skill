package org.g7.service;

import org.g7.domin.APIResult;

public interface QueryService {
	APIResult query(String loginname,String password);
	APIResult getuserinfo(String loginname);
	APIResult SigninfoQuerybyAnimalID(String AnimalID);
	APIResult SigninfoQuerybyExperimentID(String ExperimentID);
	APIResult AnimalQuery(String AnimalID);
	APIResult getexpelist(String PIID);
	APIResult getnotelisrt(String ExperimentID);
	APIResult getexperinfo(String ExperimentID);

	
	APIResult showtfinote(String NoteID);
	APIResult showtfonote(String NoteID);
	APIResult showchknote(String NoteID);
	APIResult showdisnote(String NoteID);
	APIResult showoptnote(String NoteID);

}
