package org.g7.service;

import org.g7.domin.APIResult;
import org.g7.domin.User;

/**
 * User服务层接�?
 * */
public interface UserService {
	
	/**
	 * 判断用户登录
	 * @param String loginname
	 * @param String password
	 * @return 找到返回User对象，没有找到返回null
	 * */
	User login(String loginname,String password);
	
	APIResult StaffIDQuery(String StaffID, String power);

}
