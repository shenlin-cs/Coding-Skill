package org.g7.service.impl;

import org.g7.domin.APIResult;
import org.g7.domin.ResultCode;
import org.g7.domin.User;
import org.g7.mapper.UserMapper;
import org.g7.service.UserService;
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
@Service("userService")
public class UserServiceImpl implements UserService {
	
	/**
	 * 自动注入UserMapper
	 * */
	@Autowired
	private UserMapper userMapper;

	/**
	 * UserService接口login方法实现
	 * @see { UserService }
	 * */
	@Transactional(readOnly=true)
	@Override
	public User login(String loginname, String password) {
		return userMapper.findWithLoginnameAndPassword(loginname, password);
	}
	
	@Transactional(readOnly=true)
	@Override
	public APIResult StaffIDQuery(String StaffID, String power) {
		User data=userMapper.StaffIDQuery(StaffID, power);
		if(data!=null)
		{
			return APIResult.success(data);
		}
		else
		{
			return APIResult.failure(ResultCode.USER_NOT_EXIST);
		}
	}

}
