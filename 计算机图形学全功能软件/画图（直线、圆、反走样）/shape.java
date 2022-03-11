package huatu;
import java.awt.Color;
public class shape   {
    int leftx,lefty,rightx,righty,flag;
    Color color;
    shape(int leftx,int lefty,int rightx,int righty,int flag,Color color){
    this.leftx=leftx;
    this.lefty=lefty;
    this.rightx=rightx;
    this.righty=righty;
    this.flag=flag;
    this.color=color;
    }

    void setColor(Color color){
    this.color=color;
    }

    Color getColor(){
    return color;
    }

    int getLeftx(){
    return leftx;
    }

    void  setLeftx(int leftx){
    this.leftx=leftx;
    }

    int getLefty(){
    return lefty;
    }

    void  setLefty(int lefty){
    this.lefty=lefty;
    }

    int getRightx(){
    return rightx;
    }

    void  setRightx(int rightx){
    this.rightx=rightx;
    }

    int getRighty(){
    return righty;
    }

    void  setRighty(int righty){
    this.righty=righty;
    }

    int getFlag(){
    return flag;
    }

    void setFlag(int flag){
    this.flag=flag;
    }

}


