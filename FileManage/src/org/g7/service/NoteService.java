package org.g7.service;

import org.g7.domin.APIResult;
import org.g7.domin.Note;

/**
 * User服务层接�?
 * */
public interface NoteService {
	
	APIResult UnConfirmedNoteQuery(String IsEstablished,String IsClerkDeal,String startTime,String endTime);

}
