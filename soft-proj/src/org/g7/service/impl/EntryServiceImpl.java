package org.g7.service.impl;
import java.util.List;

import org.g7.domin.Audit;
import org.g7.domin.CheckNote;
import org.g7.domin.DiscussionNote;
import org.g7.domin.ExperimentNote;
import org.g7.domin.OperationNote;
import org.g7.domin.TransferinNote;
import org.g7.domin.TransferoutNote;
import org.g7.mapper.EntryMapper;
import org.g7.service.EntryService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

@Transactional(propagation=Propagation.REQUIRED,isolation=Isolation.DEFAULT)
@Service("EntryService")
public class EntryServiceImpl implements EntryService{
	
	@Autowired
	private EntryMapper EntryMapper;
	
	@Transactional(readOnly=false)
	@Override
	public int Insert_check( String CheckID,String CheckRoomID,String CheckHeadID,String CheckHeadName,String PIID,
			 String PIName,String PIPhoneNumber,String PITeamName,String ExperimentID,String ExperimentName,
			 String AnimalID,String ParticipantsNumber,String CheckAim,String CheckResult,String CheckExcuter,
			 String CheckEquipment,String CheckMedicament,String CheckTime,
			 String InputTime,String IsEstablished) {
		return EntryMapper.Insert_check(CheckID,CheckRoomID,CheckHeadID,CheckHeadName,
				   PIID,PIName,PIPhoneNumber,PITeamName,ExperimentID,ExperimentName,
				   AnimalID,ParticipantsNumber,CheckAim,CheckResult,CheckExcuter,
				   CheckEquipment,CheckMedicament,CheckTime,InputTime,IsEstablished);
		}
	
	
	/**
	 * BookService接口getAll方法实现
	 * @see { ExperimentNoteService };
	 * */
	@Transactional(readOnly=false)
	@Override
	public int Insert_discussion(String DiscussionID,String DiscussionName,String DiscussionRoomID,
			String DiscussionHeadID,String DiscussionHeadName,String PIID,String PIName,
			String PIPhoneNumber,String PITeamName,String ExperimentID,String ExperimentName,
			String AnimalID,String DiscussionAim,String DiscussionResult,String DiscussionExcuter,
			String DiscussionEquipment,String DiscussionMedicament,String DiscussionTime,String InputTime,String IsEstablished) {
		return EntryMapper.Insert_discussion(DiscussionID,DiscussionName,DiscussionRoomID,
				DiscussionHeadID,DiscussionHeadName,PIID,PIName,
				PIPhoneNumber,PITeamName,ExperimentID,ExperimentName,
				AnimalID,DiscussionAim,DiscussionResult,DiscussionExcuter,
				DiscussionEquipment,DiscussionMedicament,DiscussionTime,InputTime,IsEstablished);
		}
	

	/**
	 * BookService接口getAll方法实现
	 * @see { ExperimentNoteService };
	 * */
	@Transactional(readOnly=false)
	@Override
	public int Insert_experiment( String Name,String ExperimentID,String EmployeeID,String Contact,String PIName,
			 String PIID,String Department,String BranchName,String AnimalID,String AnimalSpecies,
			 String ExperimentRoom,String ExperimentStartTime,String ExperimentEndTime,String ExperimentNoteTime,
			 String ExperimentPurpose,String ExperimentContent,
			 String ExperimentStep,String ExperimentConclusion,String ExperimentNote) {
		return EntryMapper.Insert_experiment(Name, ExperimentID, EmployeeID, Contact, PIName, 
				PIID, Department, BranchName, AnimalID, AnimalSpecies, ExperimentRoom, 
				ExperimentStartTime, ExperimentEndTime, ExperimentNoteTime, 
				ExperimentPurpose, ExperimentContent, ExperimentStep, ExperimentConclusion, ExperimentNote);
		}
	

	@Transactional(readOnly=false)
	@Override
	public int Insert_transferin(String TransferinID,String researcher_name,String researcher_ID,String in_charge_person_name,
			 String in_charge_person_ID,String experimental_object,String object_number,String item_number,
			 String item_name,String time,String transferfromobject,String InputTime,String IsEstablished) {
		return EntryMapper.Insert_transferin(TransferinID,researcher_name,researcher_ID,in_charge_person_name,
				   in_charge_person_ID,experimental_object,object_number,item_number,item_name,
				   time,transferfromobject,InputTime,IsEstablished);
		}
	

	
	@Transactional(readOnly=false)
	@Override
	public int Insert_operation( String OperationID,String OperationName,String OperationRoomID,
			String OperationHeadID,String OperationHeadName,String PIID,
			String PIName,String PIPhoneNumber,String PITeamName,String ExperimentID,
			String ExperimentName,String AnimalID,String OperationAim,
			String OperationResult,String OperationExcuter,String OperationEquipment,
			String OperationMedicament,String OperationTime,String InputTime,String IsEstablished) {
		return EntryMapper.Insert_operation(OperationID,OperationName,OperationRoomID,
				 OperationHeadID,OperationHeadName,PIID,PIName,PIPhoneNumber,
				 PITeamName,ExperimentID,ExperimentName,AnimalID,
				 OperationAim,OperationResult,OperationExcuter,OperationEquipment,
				 OperationMedicament,OperationTime,InputTime,IsEstablished);
		}
	

	@Transactional(readOnly=false)
	@Override
	public int Insert_transferout(String TransferoutID,String researcher_name,String researcher_ID,String in_charge_person_name,
			 String in_charge_person_ID,String experimental_object,String object_number,String item_number,
			 String item_name,String time,String transferobject,String InputTime,String IsEstablished) {
		return EntryMapper.Insert_transferout(TransferoutID,researcher_name,researcher_ID,in_charge_person_name,
				   in_charge_person_ID,experimental_object,object_number,item_number,item_name,
					 transferobject,time,InputTime,IsEstablished);
		}
	
	@Transactional(readOnly=false)
	@Override
	public List<Audit> InsertList() {		
		return EntryMapper.Insertlist();
	}
	
	public int updateApplicationInformation(String ApplicationID) {
		return EntryMapper.UpdateInfor(ApplicationID);
	}
	
	@Transactional(readOnly=false)
	@Override
	public List<CheckNote> SearchCheckKey() {		
		return EntryMapper.SearchCheckkey();
	}
	
	public List<DiscussionNote> SearchDiscussionKey() {		
		return EntryMapper.SearchDiscussionkey();
	}
	
	public List<ExperimentNote> SearchExperimentKey() {		
		return EntryMapper.SearchExperimentkey();
	}
	
	public List<OperationNote> SearchOperationKey() {		
		return EntryMapper.SearchOperationkey();
	}
	
	public List<TransferinNote> SearchTransferinKey() {		
		return EntryMapper.SearchTransferinkey();
	}
	
	public List<TransferoutNote> SearchTransferoutKey() {		
		return EntryMapper.SearchTransferoutkey();
	}

}
