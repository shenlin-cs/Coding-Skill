package org.g7.mapper;
import org.g7.domin.Application_Information;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Param;
/**
 * BookMapper接口
 * */
public interface Application_InformationMapper {

	/**
	 * 查询�?有图�?
	 * @return 图书对象集合
	 * */
	@Select("select * from g7_application_information where ApplicationID=#{ApplicationID}")
	Application_Information getUserInfo(@Param("ApplicationID")String ApplicationID);	
}
