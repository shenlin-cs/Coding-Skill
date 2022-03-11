package org.g7.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.g7.domin.APIResult;
import org.g7.domin.*;
import org.g7.domin.Animal;
import org.g7.domin.ExperimentNote;
import org.g7.domin.NoteInfo;
import org.g7.domin.Signinfo;
import org.g7.domin.User;

public interface QueryMapper {
	@Select("select * from g3_staff where LoginId = #{loginid} and LoginPassword = #{password}")
	User findWithLoginnameAndPassword(@Param("loginid")String loginid,@Param("password") String password);
	
	@Select("select * from g3_staff where LoginId = #{loginid}")
	User findWithLoginname(@Param("loginid")String loginid);
	
	@Select("select * from g7_signinfo where AnimalID = #{AnimalID}")
	List<Signinfo> SigninfoQuerybyAnimalID(@Param("AnimalID")String AnimalID);
	
	@Select("select * from g7_signinfo where ExperimentID = #{ExperimentID}")
	List<Signinfo> SigninfoQuerybyExperimentID(@Param("ExperimentID")String ExperimentID);
	
	@Select("select * from g7_experiment_animal where AnimalID = #{AnimalID}")
	Animal AnimalQuery(@Param("AnimalID")String AnimalID);
	
	@Select("select * from g7_experimentnote where PIID = #{PIID}")
	List<ExperimentNote> findexpersbypiid(@Param("PIID")String PIID);
	
	@Select("select * from g7_experimentnote where ExperimentID = #{ExperimentID}")
	ExperimentNote findexperbyexperid(@Param("ExperimentID")String ExperimentID);
	
	@Select("select * from noteinfo where ExperimentID = #{ExperimentID} order by time")
	List<NoteInfo> findnotesbyexperid(@Param("ExperimentID")String ExperimentID);
	
	@Select("select * from g7_transferinnote where TransferinID = #{NoteID}")
	TransferinNote findtfinotebynoteid(@Param("NoteID")String NoteID);
	
	@Select("select * from g7_transferoutnote where TransferoutID = #{NoteID}")
	TransferoutNote findtfonotebynoteid(@Param("NoteID")String NoteID);
	
	@Select("select * from g7_checknote where CheckID = #{NoteID}")
	CheckNote findchknotebynoteid(@Param("NoteID")String NoteID);
	
	@Select("select * from g7_discussionnote where DiscussionID = #{NoteID}")
	DiscussionNote finddisnotebynoteid(@Param("NoteID")String NoteID);
	
	@Select("select * from g7_operationnote where OperationID = #{NoteID}")
	OperationNote findoptnotebynoteid(@Param("NoteID")String NoteID);
	
}
