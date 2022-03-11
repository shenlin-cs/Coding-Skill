package org.g7.service.impl;

import java.util.List;

import org.g7.domin.APIResult;
import org.g7.domin.ResultCode;
import org.g7.domin.Note;
import org.g7.mapper.NoteMapper;
import org.g7.service.NoteService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

/**
 * User服务层接口实现类
 * @Service("userService")用于将当前类注释为一个Spring的bean，名为userService
 * */
@Transactional(propagation=Propagation.REQUIRED,isolation=Isolation.DEFAULT)
@Service("noteService")
public class NoteServiceImpl implements NoteService {
	
	@Autowired
	private NoteMapper noteMapper;

	@Transactional(readOnly=true)
	@Override
	public APIResult UnConfirmedNoteQuery(String IsEstablished,String IsClerkDeal,String startTime,String endTime) {
		List<Note> dataList=noteMapper.UnConfirmedNoteQuery(IsEstablished,IsClerkDeal,startTime, endTime);
		if(dataList.size()!=0)
		{
			System.out.println("ListSize:");
			System.out.println(dataList.size());
			for(int i=0;i<dataList.size();i++) {
				dataList.get(i).setMessageid(String.valueOf(i+10000000+1));
			}
			return APIResult.success(dataList);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}

}
