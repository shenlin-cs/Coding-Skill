package org.g7.service;

import java.util.List;

import org.g7.domin.Audit;
import org.g7.domin.CheckNote;
import org.g7.domin.DiscussionNote;
import org.g7.domin.ExperimentNote;
import org.g7.domin.OperationNote;
import org.g7.domin.TransferinNote;
import org.g7.domin.TransferoutNote;

/**
 * Book鏈嶅姟灞傛帴鍙?
 * */
public interface AuditService {
	
	/**
	 * 鏌ユ壘鎵?鏈夊浘涔?
	 * @return Book瀵硅薄闆嗗悎
	 * */
	//未审核列表
	List<Audit> getAll();
	
	//审核通过业务
	int UpdateAuditMessage(String ApplicationID,String AuditorID,
			 String AuditorName,String AuditTime,
			 String AuditResult,String Feedback);
	
	int InsertAuditNote(String ApplicationID,String EmployeeID,
			String AuditDate,String AuditComments,
			String AuditResult);
	
	//审核实验存在性业务
	ExperimentNote ExperimentExists(String ExperimentID);
	OperationNote OperationExists(String OperationID);
	CheckNote InspectExists(String InspectID);
	DiscussionNote DiscussionExists(String DiscussionID);
	TransferinNote RollInExists(String RollinID);
	TransferoutNote RollOutExists(String RolloutID);
	
}
