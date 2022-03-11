package org.g7.service.impl;

import java.util.List;

import org.g7.domin.Audit;
import org.g7.mapper.AuditDoneMapper;
import org.g7.service.AuditDoneService;
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
@Service("auditDoneService")
public class AuditDoneServiceImpl implements AuditDoneService {
	
	/**
	 * 自动注入BookMapper
	 * */
	@Autowired
	private AuditDoneMapper auditDoneMapper;

	/**
	 * BookService接口getAll方法实现
	 * @see { BookService }
	 * */
	@Transactional(readOnly=true)
	@Override
	public List<Audit> getAll() {
		
		return auditDoneMapper.findAll();
	}

}
