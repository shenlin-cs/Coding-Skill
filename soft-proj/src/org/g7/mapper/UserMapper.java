package org.g7.mapper;

import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.g7.domin.User;

/**
 * UserMapper接口
 * */
public interface UserMapper {
	
	/**
	 * 根据登录名和密码查询用户
	 * @param String loginname
	 * @param String password
	 * @return 找到返回User对象，没有找到返回null
	 * */
	@Select("select * from g3_staff where LoginId = #{loginname} and LoginPassword = #{password}")
	User findWithLoginnameAndPassword(@Param("loginname")String loginname,
			@Param("password") String password);
	
	@Select("select * from g3_staff where LoginID = #{StaffID} and power = #{power}")
	User StaffIDQuery(@Param("StaffID")String StaffID, @Param("power")String power);

}
