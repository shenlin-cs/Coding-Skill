package org.g7.service.impl;

import java.util.List;

import org.g7.domin.Audit;
import org.g7.mapper.AuditMapper;
import org.g7.service.UpdateFileService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

/**
 * updateFile服务层接口实现类
 * @Service("updateFileService")用于将当前类注释为一个Spring的bean，名为bookService
 * */
@Transactional(propagation=Propagation.REQUIRED,isolation=Isolation.DEFAULT)
@Service("updateFileService")
public class UpdateFileServiceImpl implements UpdateFileService {	
	/**
	 * 自动注入updateFileMapper
	 * */
	@Autowired
	private AuditMapper AuditMapper;

	/**
	 * updateFileService接口getAll方法实现
	 * @see { updateFileService }
	 * */
	@Transactional(readOnly=true)
	@Override
	public List<Audit> getUpdate() {		
		return AuditMapper.findUpdate();
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
}
