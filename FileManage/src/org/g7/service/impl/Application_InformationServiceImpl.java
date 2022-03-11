package org.g7.service.impl;
import org.g7.domin.Application_Information;
import org.g7.mapper.Application_InformationMapper;
import org.g7.service.Application_InformationService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

/**
 * Book服务层接口实现类
 * @Service("ExperimentNoteService")用于将当前类注释为一个Spring的bean，名为bookService
 * */
@Transactional(propagation=Propagation.REQUIRED,isolation=Isolation.DEFAULT)
@Service("Application_InformationService")
public class Application_InformationServiceImpl implements Application_InformationService {
	
	/**
	 * 自动注入BookMapper
	 * */
	@Autowired
	private Application_InformationMapper application_InformationMapper;

	/**
	 * Application_InformationService接口getAll方法实现
	 * @see { Application_InformationService };
	 * */
	@Transactional(readOnly=false)
	@Override
	public Application_Information getUserById(String id) {
		System.out.println("ServiceImpl���id:"+id);
		return application_InformationMapper.getUserInfo(id);
	}
}
