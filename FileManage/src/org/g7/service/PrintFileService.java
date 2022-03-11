package org.g7.service;

import java.util.List;

import org.g7.domin.APIResult;
import org.g7.domin.Audit;
import org.g7.domin.ExperimentNote;
import org.g7.domin.filelocation;

/**
 * Book服务层接�?
 * */
public interface PrintFileService {	
	/**
	 * 查找�?有图�?
	 * @return Book对象集合
	 * */
	List<ExperimentNote> getAll();
	
	List<filelocation> getAllprintlist();
	
	APIResult Isprintlist(String isprint);


}
