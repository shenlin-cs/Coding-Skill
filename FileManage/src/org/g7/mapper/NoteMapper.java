package org.g7.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.g7.domin.Note;;

/**
 * BookMapper接口
 * */
public interface NoteMapper {

	@Select("select noteview.* from NoteView where IsEstablished = #{IsEstablished} and IsClerkDeal = #{IsClerkDeal} and InputTime between #{startTime} and #{endTime}")
	List<Note> UnConfirmedNoteQuery(
			@Param("IsEstablished")String IsEstablished,
			@Param("IsClerkDeal")String IsClerkDeal,
			@Param("startTime")String startTime,
			@Param("endTime") String endTime);
}
