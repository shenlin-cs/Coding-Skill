package org.g7.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Select;
import org.g7.domin.Audit;

/**
 * BookMapper接口
 * */
public interface AuditDoneMapper {

	/**
	 * 查询�?有图�?
	 * @return 图书对象集合
	 * */
	@Select(" select ApplicationID,ApplicationOperateType,ApplicantName,ApplicationTime,AuditStatus,RecordType,AuditorName from g7_application_information where AuditStatus='����' order by ApplicationTime desc; ")
	List<Audit> findAll();
	
}
