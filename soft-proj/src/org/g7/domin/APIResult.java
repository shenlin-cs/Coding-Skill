package org.g7.domin;
import java.io.Serializable;
public class APIResult implements Serializable {

    private Integer code;
    private String message;
    private Object data;


    public APIResult() {
    }

    public APIResult(Integer code, String message) {
        this.code = code;
        this.message = message;
    }

    public static APIResult success(){
        APIResult res = new APIResult();
        res.setResultCode(ResultCode.SUCCESS);
        return res;
    }

    public static APIResult success(Object data) {
        APIResult APIResult = new APIResult();
        APIResult.setResultCode(ResultCode.SUCCESS);
        APIResult.setData(data);
        return APIResult;
    }

    public static APIResult failure(ResultCode resultCode) {
        APIResult APIResult = new APIResult();
        APIResult.setResultCode(resultCode);
        APIResult.setMessage(resultCode.message());
        return APIResult;
    }

    public static APIResult failure(ResultCode resultCode, Object data) {
        APIResult APIResult = new APIResult();
        APIResult.setResultCode(resultCode);
        APIResult.setData(data);
        return APIResult;
    }
    public void setResultCode(ResultCode code) {
        this.code = code.code();
        this.message = code.message();
    }

    public Integer getCode() {
        return code;
    }

    public void setCode(Integer code) {
        this.code = code;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }
}