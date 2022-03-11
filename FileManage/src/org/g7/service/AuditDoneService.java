package org.g7.service;

import java.util.List;

import org.g7.domin.Audit;

/**
 * BookæœåŠ¡å±‚æ¥å?
 * */
public interface AuditDoneService {
	
	/**
	 * æŸ¥æ‰¾æ‰?æœ‰å›¾ä¹?
	 * @return Bookå¯¹è±¡é›†åˆ
	 * */
	//ÒÑÉóºËÁĞ±í
	List<Audit> getAll();

}
