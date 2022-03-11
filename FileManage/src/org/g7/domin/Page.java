package org.g7.domin;
import java.io.Serializable;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
/**
 * �����ҳ
 */
public class Page implements Serializable {
    //��ǰҳ
    private Integer intpage;
    //ҳ��С
    private Integer pagesize;
    // �ܼ�¼ ��
    private Integer totalRecord;
    //��ҳ��
    private Integer totalPage;    
    private Integer prepage;
    private Integer nextpage;
   
    public Page() {
    	pagesize=10;
    	intpage=1;
    }

    
	public Integer getPrepage() {
		return prepage;
	}


	public void setPrepage(Integer prepage) {
		this.prepage = prepage;
	}


	public Integer getNextpage() {
		return nextpage;
	}


	public void setNextpage(Integer nextpage) {
		this.nextpage = nextpage;
	}


	public Integer getIntpage() {
		return intpage;
	}

	public void setIntpage(Integer intpage) {
		this.intpage = intpage;
	}

	public Integer getPagesize() {
		return pagesize;
	}

	public void setPagesize(Integer pagesize) {
		this.pagesize = pagesize;
	}

	public Integer getTotalRecord() {
		return totalRecord;
	}

	public void setTotalRecord(Integer totalRecord) {
		this.totalRecord = totalRecord;
	}

	public Integer getTotalPage() {
		return totalPage;
	}

	public void setTotalPage(Integer totalPage) {
		this.totalPage = totalPage;
	}


	@Override
	public String toString() {
		return "Page [intpage=" + intpage + ", pagesize=" + pagesize + ", totalRecord=" + totalRecord + ", totalPage="
				+ totalPage + ", prepage=" + prepage + ", nextpage=" + nextpage + "]";
	}
}
