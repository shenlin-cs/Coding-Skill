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
 * Book服务层接�?
 * */
public interface AuditService {
	
	/**
	 * 查找�?有图�?
	 * @return Book对象集合
	 * */
	//δ����б�
	List<Audit> getAll();
	
	//���ͨ��ҵ��
	int UpdateAuditMessage(String ApplicationID,String AuditorID,
			 String AuditorName,String AuditTime,
			 String AuditResult,String Feedback);
	
	int InsertAuditNote(String ApplicationID,String EmployeeID,
			String AuditDate,String AuditComments,
			String AuditResult);
	
	//���ʵ�������ҵ��
	ExperimentNote ExperimentExists(String ExperimentID);
	OperationNote OperationExists(String OperationID);
	CheckNote InspectExists(String InspectID);
	DiscussionNote DiscussionExists(String DiscussionID);
	TransferinNote RollInExists(String RollinID);
	TransferoutNote RollOutExists(String RolloutID);
	
}
