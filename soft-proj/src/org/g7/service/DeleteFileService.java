package org.g7.service;

import java.util.List;

import org.g7.domin.Audit;

/**
 * BookæœåŠ¡å±‚æ¥å?
 * */
public interface DeleteFileService {
	
	/**
	 * æŸ¥æ‰¾æ‰?æœ‰å›¾ä¹?
	 * @return Bookå¯¹è±¡é›†åˆ
	 * */
	//Î´ÉóºËÁĞ±í
	List<Audit> getDelete();
	

}
