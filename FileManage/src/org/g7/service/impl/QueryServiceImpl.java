package org.g7.service.impl;

import java.util.List;

import org.g7.domin.APIResult;
import org.g7.domin.Animal;
import org.g7.domin.ExperimentNote;
import org.g7.domin.ResultCode;
import org.g7.domin.Signinfo;
import org.g7.domin.NoteInfo;
import org.g7.domin.User;
import org.g7.domin.*;
import org.g7.mapper.QueryMapper;
import org.g7.service.QueryService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
@Service("queryService")
public class QueryServiceImpl implements QueryService{
	/**
	 * 自动注入UserMapper
	 * */
	@Autowired
	private QueryMapper queryMapper;

	/**
	 * UserService接口login方法实现
	 * @see { UserService }
	 * */
	@Transactional(readOnly=true)
	@Override
	public APIResult query(String loginname, String password) {
		User data=queryMapper.findWithLoginnameAndPassword(loginname, password);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.PERMISSION_NO_ACCESS);
		}
	}
	
	/**
	 * UserService接口login方法实现
	 * @see { UserService }
	 * */
	@Transactional(readOnly=true)
	@Override
	public APIResult getuserinfo(String loginname) {
		User data=queryMapper.findWithLoginname(loginname);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.PERMISSION_NO_ACCESS);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult SigninfoQuerybyAnimalID(String AnimalID) {
		List<Signinfo> data=queryMapper.SigninfoQuerybyAnimalID(AnimalID);
		if(data.size()!=0)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult SigninfoQuerybyExperimentID(String ExperimentID) {
		List<Signinfo> data=queryMapper.SigninfoQuerybyExperimentID(ExperimentID);
		if(data.size()!=0)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult AnimalQuery(String AnimalID) {
		Animal data=queryMapper.AnimalQuery(AnimalID);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	

	@Transactional(readOnly=true)
	@Override
	public APIResult getexpelist(String PIID) {
		List<ExperimentNote> data=queryMapper.findexpersbypiid(PIID);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult getnotelisrt(String ExperimentID) {
		List<NoteInfo> data=queryMapper.findnotesbyexperid(ExperimentID);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult getexperinfo(String ExperimentID) {
		ExperimentNote data=queryMapper.findexperbyexperid(ExperimentID);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult showtfinote(String NoteID) {
		TransferinNote data=queryMapper.findtfinotebynoteid(NoteID);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult showtfonote(String NoteID) {
		TransferoutNote data=queryMapper.findtfonotebynoteid(NoteID);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}

	
	@Transactional(readOnly=true)
	@Override
	public APIResult showchknote(String NoteID) {
		CheckNote data=queryMapper.findchknotebynoteid(NoteID);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult showdisnote(String NoteID) {
		DiscussionNote data=queryMapper.finddisnotebynoteid(NoteID);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult showoptnote(String NoteID) {
		OperationNote data=queryMapper.findoptnotebynoteid(NoteID);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.RESULE_DATA_NONE);
		}
	}

}
