package org.g7.service;

import java.util.List;

import org.g7.domin.Audit;
import org.g7.domin.CheckNote;
import org.g7.domin.DiscussionNote;
import org.g7.domin.ExperimentNote;
import org.g7.domin.OperationNote;
import org.g7.domin.TransferinNote;
import org.g7.domin.TransferoutNote;

public interface EntryService {
	
	int Insert_check(String CheckID,String CheckRoomID,String CheckHeadID,String CheckHeadName,String PIID,
			 String PIName,String PIPhoneNumber,String PITeamName,String ExperimentID,String ExperimentName,
			 String AnimalID,String ParticipantsNumber,String CheckAim,String CheckResult,String CheckExcuter,
			 String CheckEquipment,String CheckMedicament,String CheckTime,
			 String InputTime,String IsEstablished);
	
	int Insert_discussion(String DiscussionID,String DiscussionName,String DiscussionRoomID,
			String DiscussionHeadID,String DiscussionHeadName,String PIID,String PIName,
			String PIPhoneNumber,String PITeamName,String ExperimentID,String ExperimentName,
			String AnimalID,String DiscussionAim,String DiscussionResult,String DiscussionExcuter,
			String DiscussionEquipment,String DiscussionMedicament,
			String DiscussionTime,String InputTime,String IsEstablished);
	
	int Insert_experiment( String Name,String ExperimentID,String EmployeeID,String Contact,String PIName,
			 String PIID,String Department,String BranchName,String AnimalID,String AnimalSpecies,
			 String ExperimentRoom,String ExperimentStartTime,String ExperimentEndTime,String ExperimentNoteTime,
			 String ExperimentPurpose,String ExperimentContent,
			 String ExperimentStep,String ExperimentConclusion,String ExperimentNote);
	
	int Insert_operation( String OperationID,String OperationName,String OperationRoomID,
			String OperationHeadID,String OperationHeadName,String PIID,
			String PIName,String PIPhoneNumber,String PITeamName,String ExperimentID,
			String ExperimentName,String AnimalID,String OperationAim,String OperationResult,
			String OperationExcuter,String OperationEquipment,String OperationMedicament,
			String OperationTime,String InputTime,String IsEstablished);
	
	int Insert_transferin(String TransferinID,String researcher_name,String researcher_ID,String in_charge_person_name,
			 String in_charge_person_ID,String experimental_object,String object_number,String item_number,
			 String item_name,String time,String transferfromobject,String InputTime,String IsEstablished);
	
	int Insert_transferout(String TransferoutID,String researcher_name,String researcher_ID,String in_charge_person_name,
			 String in_charge_person_ID,String experimental_object,String object_number,String item_number,
			 String item_name,String time,String transferobject,String InputTime,String IsEstablished);
	
	List<Audit> InsertList();
	
	int updateApplicationInformation(String ApplicationID);
	
	List<CheckNote> SearchCheckKey();
	
	List<DiscussionNote> SearchDiscussionKey();
	
	List<ExperimentNote> SearchExperimentKey();
	
	List<OperationNote> SearchOperationKey();
	
	List<TransferinNote> SearchTransferinKey();
	
	List<TransferoutNote> SearchTransferoutKey();

}
