package org.g7.service.impl;

import java.util.List;

import org.g7.domin.Audit;
import org.g7.domin.CheckNote;
import org.g7.domin.DiscussionNote;
import org.g7.domin.ExperimentNote;
import org.g7.domin.OperationNote;
import org.g7.domin.TransferinNote;
import org.g7.domin.TransferoutNote;
import org.g7.mapper.AuditMapper;
import org.g7.service.AuditService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

/**
 * Book服务层接口实现类
 * @Service("bookService")用于将当前类注释为一个Spring的bean，名为bookService
 * */
@Transactional(propagation=Propagation.REQUIRED,isolation=Isolation.DEFAULT)
@Service("AuditService")
public class AuditServiceImpl implements AuditService {
	
	/**
	 * 自动注入BookMapper
	 * */
	@Autowired
	private AuditMapper AuditMapper;

	/**
	 * BookService接口getAll方法实现
	 * @see { BookService }
	 * */
	@Transactional(readOnly=true)
	@Override
	public List<Audit> getAll() {		
		return AuditMapper.findAll();
	}
	
	public int UpdateAuditMessage(String ApplicationID,String AuditorID,
			 String AuditorName,String AuditTime,
			 String AuditResult,String Feedback){
		return AuditMapper.UpdateOne(ApplicationID, AuditorID, AuditorName, AuditTime, AuditResult, Feedback);			
	}
	
	public int InsertAuditNote(String ApplicationID,String EmployeeID,
			String AuditDate,String AuditComments,
			String AuditResult) {
		return AuditMapper.InsertAuditNote(ApplicationID, EmployeeID, AuditDate, AuditComments, AuditResult);
	}
	
	public ExperimentNote ExperimentExists(String ExperimentID) {
		return AuditMapper.ExperimentExists(ExperimentID);
	}
	public OperationNote OperationExists(String OperationID) {
		return AuditMapper.OperationExists(OperationID);
	}
	public CheckNote InspectExists(String InspectID) {
		return AuditMapper.InspectExists(InspectID);
	}
	public DiscussionNote DiscussionExists(String DiscussionID) {
		return AuditMapper.DiscussionExists(DiscussionID);
	}
	public TransferinNote RollInExists(String RollinID) {
		return AuditMapper.RollInExists(RollinID);
	}
	public TransferoutNote RollOutExists(String RolloutID) {
		return AuditMapper.RollOutExists(RolloutID);
	}
}
