package org.g7.service.impl;

import java.util.List;

import org.g7.domin.APIResult;
import org.g7.domin.Audit;
import org.g7.domin.ExperimentNote;
import org.g7.domin.ResultCode;
import org.g7.domin.filelocation;
import org.g7.mapper.AuditMapper;
import org.g7.mapper.ExperimentNoteMapper;
import org.g7.service.PrintFileService;
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
@Service("PrintFileService")
public class PrintFileServiceImpl implements PrintFileService {	
	/**
	 * 自动注入updateFileMapper
	 * */
	@Autowired
	private ExperimentNoteMapper ExperimentNoteMapper;

	/**
	 * updateFileService接口getAll方法实现
	 * @see { updateFileService }
	 * */
	@Transactional(readOnly=true)
	@Override
	public List<ExperimentNote> getAll() {		
		return ExperimentNoteMapper.findAll();
	}
	
	public List<filelocation> getAllprintlist(){
		return ExperimentNoteMapper.findAllprintlist();
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult Isprintlist(String isprint) {
		List<filelocation> data=ExperimentNoteMapper.findAllisprint(isprint);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.PERMISSION_NO_ACCESS);
		}
	}


}
