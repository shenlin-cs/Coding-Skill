package huatu;
import java.awt.*;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.sqrt;
import java.util.*;
public class my extends Canvas implements  MouseListener,MouseMotionListener{
    static int ox, oy;
    static int k=0;
    static int [][]s = {{1,2,1},{2,4,2},{1,2,1}};
    static int a,b,c;//保存理想直线方程中的一次项系数和常数项
ArrayList<shape> list=new ArrayList<shape>();
 int leftx,lefty,rightx,righty;
 Color color=Color.black;
 int f=0;
 int ff=0;
my(){
        addMouseListener(this);
addMouseMotionListener(this);
}

public void paint(Graphics g){
int newX = Math.min(leftx,rightx);
int newY = Math.min(lefty,righty);
int newWidth = Math.abs(leftx-rightx);
int newHeight = Math.abs(lefty-righty);

if(ff==1){
Iterator<shape> iterator=list.iterator();
while(iterator.hasNext()){
shape p=(shape)iterator.next();
int newX1 = Math.min(p.leftx,p.rightx);
int newY1 = Math.min(p.lefty,p.righty);
int newWidth1 = Math.abs(p.leftx-p.rightx);
int newHeight1 = Math.abs(p.lefty-p.righty);
if((p.color).equals(Color.red)){
g.setColor(color.red);
}

if((p.color).equals(Color.green)){
g.setColor(color.green);
}

if((p.color).equals(Color.blue)){
g.setColor(color.blue);
}

if((p.color).equals(Color.yellow)){
g.setColor(color.yellow);
}

if((p.color).equals(Color.black)){
g.setColor(color.black);
}

if(p.flag==0){
//g.drawLine(p.leftx, p.lefty, p.rightx, p.righty);
	int x=p.leftx;
	int y=p.lefty;
	int dx=abs(p.rightx - p.leftx);
	int dy=abs(p.righty - p.lefty);
	int s1=p.rightx > p.leftx ? 1:-1;
	int s2=p.righty > p.lefty ? 1:-1;
	
	boolean flag = false;	// 默认不互换 dx、dy
	if (dy>dx)				// 当斜率大于 1 时，dx、dy 互换
	{
		int temp=dx;
		dx=dy;
		dy=temp;
		flag=true;
	}
	
	int e=2*dy-dx;
	for(int i=0;i<dx;i++){
		g.drawLine(x, y, x, y);
		if (e>=0){
			if (!flag)		// 当斜率 < 1 时，选取上下象素点
                            y+=s2;
			else					// 当斜率 > 1 时，选取左右象素点
                            x+=s1;
			e-=2*dx;
		}
		if (!flag)
			x+=s1;				// 当斜率 < 1 时，选取 x 为步长
		else
			y+=s2;				// 当斜率 > 1 时，选取 y 为步长
		e+=2*dy;
	}
}

if(p.flag==1){
//g.drawRect(newX1, newY1, newWidth1, newHeight1);
}

if(p.flag==2){
//g.drawOval(newX1, newY1, newWidth1, newHeight1);

    int squrea=newWidth1*newWidth1;
    int squreb=newHeight1*newHeight1;
    int d=4*(squreb-squrea*newHeight1)+squrea;
    int xP=(int)(0.5+(float)squrea/sqrt((float)(squrea+squreb)));
    int yP=(int)(0.5+(float)squreb/sqrt((float)(squrea+squreb)));
    int tx=0, ty=newHeight1;
    g.drawLine(newX1+tx, newY1+ty, newX1+tx, newY1+ty);
    g.drawLine(newX1-tx, newY1+ty, newX1-tx, newY1+ty);
    g.drawLine(newX1+tx, newY1-ty, newX1+tx, newY1-ty);
    g.drawLine(newX1-tx, newY1-ty, newX1-tx, newY1-ty);
    while (tx<=xP)
    {
        if (d<=0)
            d+=4*squreb*(2*tx+3);
        else
        {
            d+=4*squreb*(2*tx+3)-8*squrea*(ty-1);
            --ty;
        }
        ++tx;
        g.drawLine(newX1+tx, newY1+ty, newX1+tx, newY1+ty);
        g.drawLine(newX1-tx, newY1+ty, newX1-tx, newY1+ty);
        g.drawLine(newX1+tx, newY1-ty, newX1+tx, newY1-ty);
        g.drawLine(newX1-tx, newY1-ty, newX1-tx, newY1-ty);
    }
    
    tx=newWidth1;ty=0;
    d=4*(squrea-squreb*newWidth1)+squreb;
    g.drawLine(newX1+tx, newY1+ty, newX1+tx, newY1+ty);
    g.drawLine(newX1-tx, newY1+ty, newX1-tx, newY1+ty);
    g.drawLine(newX1+tx, newY1-ty, newX1+tx, newY1-ty);
    g.drawLine(newX1-tx, newY1-ty, newX1-tx, newY1-ty);
    while (ty<yP)
    {
        if (d<=0)
        {
            d+=4*squrea*(2*ty+3);
        }
        else{
            d+=4*squrea*(2*ty+3)-8*squreb*(tx-1);
            tx--;
        }
        ++ty;
        g.drawLine(newX1+tx, newY1+ty, newX1+tx, newY1+ty);
        g.drawLine(newX1-tx, newY1+ty, newX1-tx, newY1+ty);
        g.drawLine(newX1+tx, newY1-ty, newX1+tx, newY1-ty);
        g.drawLine(newX1-tx, newY1-ty, newX1-tx, newY1-ty);
    }
}

if(p.flag==3){
g.fillRect(newX1, newY1, newWidth1, newHeight1);
}

if(p.flag==4){
g.fillOval(newX1, newY1, newWidth1, newHeight1);
}

if(p.flag==5){
g.clearRect(newX1, newY1, newWidth1, newHeight1);
}

if(p.flag==6){
//g.drawOval(newX1,newY1,max(newWidth1, newHeight1),max(newWidth1, newHeight1));
        int tx=0, ty=max(newWidth1, newHeight1), d=5-4*max(newWidth1, newHeight1);
	while(tx<=ty)
	{
		// 利用圆的八分对称性画点
		g.drawLine(newX1+tx, newY1+ty, newX1+tx, newY1+ty);
                g.drawLine(newX1-tx, newY1-ty, newX1-tx, newY1-ty);
                g.drawLine(newX1-tx, newY1+ty, newX1-tx, newY1+ty);
                g.drawLine(newX1+tx, newY1-ty, newX1+tx, newY1-ty);
                g.drawLine(newX1+ty, newY1+tx, newX1+ty, newY1+tx);
                g.drawLine(newX1+ty, newY1-tx, newX1+ty, newY1-tx);
                g.drawLine(newX1-ty, newY1+tx, newX1-ty, newY1+tx);
                g.drawLine(newX1-ty, newY1-tx, newX1-ty, newY1-tx);
		if(d<0){
                    d+=8*tx+12;
                }
                else{
                    d+=8*(tx-ty)+20;
                    ty--;
                }
		tx++;
        }
}

if(p.flag==7){
g.drawRect(newX1, newY1, max(newWidth1, newHeight1),max(newWidth1, newHeight1));
}

if(p.flag==8){
    if (ox >= 0) {
    g.drawLine(ox, oy, p.rightx, p.righty);
    }
    ox =  p.rightx;
    oy =  p.righty;
}

if(p.flag==12){
    if (ox >= 0) {
    g.drawOval(ox,oy,0,0);
    }
    ox =  p.rightx;
    oy =  p.righty;
}

if(p.flag==10){
    Graphics2D g2 = (Graphics2D)g;  //g是Graphics对象  
    g2.setStroke(new BasicStroke(2.0f));  
    g2.drawLine(p.leftx, p.lefty, p.rightx, p.righty);
}

if(p.flag==11){
    Graphics2D g2 = (Graphics2D)g;  //g是Graphics对象  
    g2.setStroke(new BasicStroke(1.0f));  
    g2.drawLine(p.leftx, p.lefty, p.rightx, p.righty);
}

if(p.flag==9){
//voidAntilise_line(int x0,int y0,int x1,int y1,int color){
    double temp, w1, w2, w3, temp2;
    int s[][] = { { 1, 2, 1 }, { 2, 4, 2 }, { 1, 2, 1 } };
    int Red,Green,Blue;
    int x = p.leftx;
    int y = p.lefty;
    int w = p.rightx - p.leftx;
    int h = p.righty - p.lefty;
    int dx1 = w < 0 ? -1 : (w > 0 ? 1 : 0);
    int dy1 = h < 0 ? -1 : (h > 0 ? 1 : 0);
    int dx2 = w < 0 ? -1 : (w > 0 ? 1 : 0);
    int dy2 = 0;
    int s1 = Math.abs(w);
    int s2 = Math.abs(h);
    if (s1 <= s2) {
    s1 = Math.abs(h);
    s2 = Math.abs(w);
    dx2 = 0;
    dy2 = h < 0 ? -1 : (h > 0 ? 1 : 0);
    }
    int s3 = s1 >> 1;
    if (p.leftx == p.rightx) {
        for (int i = 0; i <= s1; i++) {
            g.drawLine(x, y, x, y);
            s3 += s2;
            if (s3 >= s1) {
                s3 -= s1;
                x += dx1;
                y += dy1;
            } 
            else {
                x += dx2;
                y += dy2;
            }
        }
    } 
    else {
        for (int i = 0; i <= s1; i++) {
            w1 = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    temp = (y + 1 + k / 3.0 - 1 / 3.0 - 1.0 * h / w * (x + j / 3.0 - 1 / 3.0 - p.leftx)
                    - 0.5 * Math.sqrt(1 + h / w * h / w) - p.lefty);
                    if (temp < 0) {
                        w1 += s[j][k];
                    }
                }
            }
            Red = color.getRed();Green = color.getGreen();Blue = color.getBlue();
            Red = (int) ((255 - Red) * (1 - w1 / 16.0)) + Red;
            Green = (int) ((255 - Green) * (1 - w1 / 16.0)) + Green;
            Blue = (int) ((255 - Blue) * (1 - w1 / 16.0)) + Blue;
            g.setColor(new Color(Red, Green, Blue));
            g.drawLine(x, y + 1, x, y + 1);

            w2 = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    temp = (y + k / 3.0 - 1 / 3.0 - 1.0 * h / w * (x + j / 3.0 - 1 / 3.0 - p.leftx)
                    - 0.5 * Math.sqrt(1 + h / w * h / w) - p.lefty);
                    temp2 = (y + k / 3.0 - 1 / 3.0 - 1.0 * h / w * (x + j / 3.0 - 1 / 3.0 - p.leftx)
                    + 0.5 * Math.sqrt(1 + h / w * h / w) - p.lefty);
                    if (temp < 0 && temp2 > 0) {
                        w2 += s[j][k];
                    }
                }
            }
            Red = color.getRed();Green = color.getGreen();Blue = color.getBlue();
            Red = (int) ((255 - Red) * (1 - w2 / 16.0)) + Red;
            Green = (int) ((255 - Green) * (1 - w2 / 16.0)) + Green;
            Blue = (int) ((255 - Blue) * (1 - w2 / 16.0)) + Blue;
            g.setColor(new Color(Red, Green, Blue));
            g.drawLine(x, y, x, y);

            w3 = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    temp = (y - 1 + k / 3.0 - 1 / 3.0 - 1.0 * h / w * (x + j / 3.0 - 1 / 3.0 - p.leftx)
                    + 0.5 * Math.sqrt(1 + h / w * h / w) - p.lefty);
                    if (temp > 0) {
                        w3 += s[j][k];
                    }
                }
            }
            Red = color.getRed();Green = color.getGreen();Blue = color.getBlue();
            Red = (int) ((255 - Red) * (1 - w3 / 16.0)) + Red;
            Green = (int) ((255 - Green) * (1 - w3 / 16.0)) + Green;
            Blue = (int) ((255 - Blue) * (1 - w3 / 16.0)) + Blue;
            g.setColor(new Color(Red, Green, Blue));
            g.drawLine(x, y - 1, x, y - 1);
            s3 += s2;
            if (s3 >= s1) {
                s3 -= s1;
                x += dx1;
                y += dy1;
            } 
            else {
                x += dx2;
                y += dy2;
            }
        }
    }
}
}

}

if((color).equals(Color.red)){
g.setColor(color.red);
}

if((color).equals(Color.green)){
g.setColor(color.green);
}

if((color).equals(Color.blue)){
g.setColor(color.blue);
}

if((color).equals(Color.yellow)){
g.setColor(color.yellow);
}

if((color).equals(Color.black)){
g.setColor(color.black);
}

if(f==0){
g.drawLine(leftx, lefty, rightx, righty);
	int x=leftx;
	int y=lefty;
	int dx=abs(rightx - leftx);
	int dy=abs(righty - lefty);
	int s1=rightx > leftx ? 1:-1;
	int s2=righty > lefty ? 1:-1;
	
	boolean flag=false;	// 默认不互换 dx、dy
	if (dy>dx)				// 当斜率大于 1 时，dx、dy 互换
	{
		int temp=dx;
		dx=dy;
		dy=temp;
		flag=true;
	}
	
	int e=2*dy-dx;
	for(int i=0;i<dx;i++){
		g.drawLine(x, y, x, y);
		if (e>=0){
			if (!flag)		// 当斜率 < 1 时，选取上下象素点
                            y+=s2;
			else					// 当斜率 > 1 时，选取左右象素点
                            x+=s1;
			e-=2*dx;
		}
		if (!flag)
			x+=s1;				// 当斜率 < 1 时，选取 x 为步长
		else
			y+=s2;				// 当斜率 > 1 时，选取 y 为步长
		e+=2*dy;
	}
}

if(f==1){
g.drawRect(newX, newY, newWidth, newHeight);
}

if(f==2){
//g.drawOval(newX, newY, newWidth, newHeight);

    int squrea=newWidth*newWidth;
    int squreb=newHeight*newHeight;
    int d=4*(squreb-squrea*newHeight)+squrea;
    int xP=(int)(0.5+(float)squrea/sqrt((float)(squrea+squreb)));
    int yP=(int)(0.5+(float)squreb/sqrt((float)(squrea+squreb)));
    int tx=0, ty=newHeight;
    g.drawLine(newX+tx, newY+ty, newX+tx, newY+ty);
    g.drawLine(newX-tx, newY+ty, newX-tx, newY+ty);
    g.drawLine(newX+tx, newY-ty, newX+tx, newY-ty);
    g.drawLine(newX-tx, newY-ty, newX-tx, newY-ty);
    while (tx<=xP)
    {
        if (d<=0)
            d+=4*squreb*(2*tx+3);
        else
        {
            d+=4*squreb*(2*tx+3)-8*squrea*(ty-1);
            --ty;
        }
        ++tx;
        g.drawLine(newX+tx, newY+ty, newX+tx, newY+ty);
        g.drawLine(newX-tx, newY+ty, newX-tx, newY+ty);
        g.drawLine(newX+tx, newY-ty, newX+tx, newY-ty);
        g.drawLine(newX-tx, newY-ty, newX-tx, newY-ty);
    }
    
    tx=newWidth;ty=0;
    d=4*(squrea-squreb*newWidth)+squreb;
    while (ty<yP)
    {
        if (d<=0)
        {
            d+=4*squrea*(2*ty+3);
        }
        else{
            d+=4*squrea*(2*ty+3)-8*squreb*(tx-1);
            tx--;
        }
        ++ty;
        g.drawLine(newX+tx, newY+ty, newX+tx, newY+ty);
        g.drawLine(newX-tx, newY+ty, newX-tx, newY+ty);
        g.drawLine(newX+tx, newY-ty, newX+tx, newY-ty);
        g.drawLine(newX-tx, newY-ty, newX-tx, newY-ty);
    }
}

if(f==3){
g.fillRect(newX, newY, newWidth, newHeight);
}

if(f==4){
g.fillOval(newX, newY, newWidth, newHeight);
}

if(f==5){
g.clearRect(newX, newY, newWidth, newHeight);
}

if(f==6){
//g.drawOval(newX,newY,max(newWidth, newHeight),max(newWidth, newHeight));
int tx=0, ty=max(newWidth, newHeight), d=5-4*max(newWidth, newHeight);
	while(tx<=ty)
	{
		// 利用圆的八分对称性画点
		g.drawLine(newX+tx, newY+ty, newX+tx, newY+ty);
                g.drawLine(newX-tx, newY-ty, newX-tx, newY-ty);
                g.drawLine(newX-tx, newY+ty, newX-tx, newY+ty);
                g.drawLine(newX+tx, newY-ty, newX+tx, newY-ty);
                g.drawLine(newX+ty, newY+tx, newX+ty, newY+tx);
                g.drawLine(newX+ty, newY-tx, newX+ty, newY-tx);
                g.drawLine(newX-ty, newY+tx, newX-ty, newY+tx);
                g.drawLine(newX-ty, newY-tx, newX-ty, newY-tx);
		if(d<0){
                    d+=8*tx+12;
                }
                else{
                    d+=8*(tx-ty)+20;
                    ty--;
                }
		tx++;
        }
}

if(f==7){
g.drawRect(newX, newY, max(newWidth, newHeight),max(newWidth, newHeight));
}

if(f==8){
    if (ox >= 0) {
    g.drawLine(ox, oy, rightx, righty);
    }
    ox =  rightx;
    oy =  righty;
}

if(f==12){
    if (ox >= 0) {
    g.drawOval(ox,oy,0,0);
    }
    ox =  rightx;
    oy =  righty;
    
}

if(f==10){
    Graphics2D g2 = (Graphics2D)g;  //g是Graphics对象  
    g2.setStroke(new BasicStroke(2.0f));  
    g2.drawLine(leftx, lefty, rightx, righty);
}

if(f==11){
    Graphics2D g2 = (Graphics2D)g;  //g是Graphics对象  
    g2.setStroke(new BasicStroke(1.0f));  
    g2.drawLine(leftx, lefty, rightx, righty);
}

if(f==9){
    double temp, w1, w2, w3, temp2;
    int s[][] = { { 1, 2, 1 }, { 2, 4, 2 }, { 1, 2, 1 } };
    int Red,Green,Blue;
    int x = leftx;
    int y = lefty;
    int w = rightx - leftx;
    int h = righty - lefty;
    int dx1 = w < 0 ? -1 : (w > 0 ? 1 : 0);
    int dy1 = h < 0 ? -1 : (h > 0 ? 1 : 0);
    int dx2 = w < 0 ? -1 : (w > 0 ? 1 : 0);
    int dy2 = 0;
    int s1 = Math.abs(w);
    int s2 = Math.abs(h);
    if (s1 <= s2) {
    s1 = Math.abs(h);
    s2 = Math.abs(w);
    dx2 = 0;
    dy2 = h < 0 ? -1 : (h > 0 ? 1 : 0);
    }
    int s3 = s1 >> 1;
    if (leftx == rightx) {
        for (int i = 0; i <= s1; i++) {
            g.drawLine(x, y, x, y);
            s3 += s2;
            if (s3 >= s1) {
                s3 -= s1;
                x += dx1;
                y += dy1;
            } 
            else {
                x += dx2;
                y += dy2;
            }
        }
    } 
    else {
        for (int i = 0; i <= s1; i++) {
            w1 = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    temp = (y + 1 + k / 3.0 - 1 / 3.0 - 1.0 * h / w * (x + j / 3.0 - 1 / 3.0 - leftx)
                    - 0.5 * Math.sqrt(1 + h / w * h / w) - lefty);
                    if (temp < 0) {
                        w1 += s[j][k];
                    }
                }
            }
            Red = color.getRed();Green = color.getGreen();Blue = color.getBlue();
            Red = (int) ((255 - Red) * (1 - w1 / 16.0)) + Red;
            Green = (int) ((255 - Green) * (1 - w1 / 16.0)) + Green;
            Blue = (int) ((255 - Blue) * (1 - w1 / 16.0)) + Blue;
            g.setColor(new Color(Red, Green, Blue));
            g.drawLine(x, y + 1, x, y + 1);

            w2 = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    temp = (y + k / 3.0 - 1 / 3.0 - 1.0 * h / w * (x + j / 3.0 - 1 / 3.0 - leftx)
                    - 0.5 * Math.sqrt(1 + h / w * h / w) - lefty);
                    temp2 = (y + k / 3.0 - 1 / 3.0 - 1.0 * h / w * (x + j / 3.0 - 1 / 3.0 - leftx)
                    + 0.5 * Math.sqrt(1 + h / w * h / w) - lefty);
                    if (temp < 0 && temp2 > 0) {
                        w2 += s[j][k];
                    }
                }
            }
            Red = color.getRed();Green = color.getGreen();Blue = color.getBlue();
            Red = (int) ((255 - Red) * (1 - w2 / 16.0)) + Red;
            Green = (int) ((255 - Green) * (1 - w2 / 16.0)) + Green;
            Blue = (int) ((255 - Blue) * (1 - w2 / 16.0)) + Blue;
            g.setColor(new Color(Red, Green, Blue));
            g.drawLine(x, y, x, y);

            w3 = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    temp = (y - 1 + k / 3.0 - 1 / 3.0 - 1.0 * h / w * (x + j / 3.0 - 1 / 3.0 - leftx)
                    + 0.5 * Math.sqrt(1 + h / w * h / w) - lefty);
                    if (temp > 0) {
                        w3 += s[j][k];
                    }
                }
            }
            Red = color.getRed();Green = color.getGreen();Blue = color.getBlue();
            Red = (int) ((255 - Red) * (1 - w3 / 16.0)) + Red;
            Green = (int) ((255 - Green) * (1 - w3 / 16.0)) + Green;
            Blue = (int) ((255 - Blue) * (1 - w3 / 16.0)) + Blue;
            g.setColor(new Color(Red, Green, Blue));
            g.drawLine(x, y - 1, x, y - 1);
            s3 += s2;
            if (s3 >= s1) {
                s3 -= s1;
                x += dx1;
                y += dy1;
            } 
            else {
                x += dx2;
                y += dy2;
            }
        }
    }
}
}


double color_value(int x,int y){
	int i,j;
	double q=0.0,t,d;
	for(j=0;j<3;j++)//判断每个子像素与矩形区域的位置关系
		for(i=0;i<3;i++){
			t=a*(x+1.0/3*(i-1))+b*(y+1.0/3*(j-1))+c;
			d=4*t*t-a*a-b*b;
			if(d<=0)//如果当前子像素位于矩形区域内
				q+=(double)s[i][j]/16;//将该子像素的权值累加至q中
		}
	return(q);
}

double pixel_value(int x,int y){
	int i,j;
	double q=0.0,d,d1,d2,t1,t2;
	if(k==1){//如果当前处理的像素是P
		t1=a*(x-1.0/3)+b*(y+1.0/3)+c;
		d1=4*t1*t1-a*a-b*b;
		t2=a*(x+1.0/3)+b*(y-1.0/3)+c;
		d2=4*t2*t2-a*a-b*b;
		if(d1<=0&&d2<=0){//如果子像素1和子像素9均落在矩形区域中
			q=1;
                }
                else{
			q=color_value(x,y);
                }
	}
        else if(k==0){//如果当前处理的像素是S
		t1=a*x+b*y+c;
		d=4*t1*t1-a*a-b*b;
		if(d>0){//如果像素5在矩形区域之外
			for(i=0;i<3;i++){//判断子像素1,2,3与矩形区域的位置关系
				t1=a*(x+1.0/3*(i-1))+b*(y+1.0/3)+c;
				d=4*t1*t1-a*a-b*b;
				if(d<=0)//如果当前子像素位于矩形区域内
					q+=(double)s[i][2]/16;//将该子像素的权值累加至q中
			}
			t1=a*(x-1.0/3)+b*y+c;
			d=4*t1*t1-a*a-b*b;
			if(d<=0)//如果子像素4位于矩形区域内
				q+=(double)s[0][1]/16;//将该子像素的权值累加至q中
		}
		else//如果像素5在矩形区域之内
			q=color_value(x,y);
	}
        else if(k==2){//如果当前处理的像素是T
		t1=a*x+b*y+c;
		d=4*t1*t1-a*a-b*b;
		if(d>0){//如果像素5在矩形区域之外
			for(i=0;i<3;i++){//判断子像素7,8,9与矩形区域的位置关系
				t1=a*(x+1.0/3*(i-1))+b*(y-1.0/3)+c;
				d=4*t1*t1-a*a-b*b;
				if(d<=0)//如果当前子像素位于矩形区域内
					q+=(double)s[i][0]/16;//将该子像素的权值累加至q中
			}
			t1=a*(x+1.0/3)+b*y+c;
			d=4*t1*t1-a*a-b*b;
			if(d<=0)//如果子像素6位于矩形区域内
				q+=(double)s[2][1]/16;//将该子像素的权值累加至q中
		}
		else//如果像素5在矩形区域之内
                    q=color_value(x,y);
	}
	k++;
	if(k==3)
            k=0;
    return(q);
}

public void mousePressed(MouseEvent e){

leftx=e.getX();
lefty=e.getY();

// repaint();
ff=1;
}

public void mouseReleased(MouseEvent e) {//写
list.add(new shape(leftx,lefty,rightx,righty,f,color));
ff=0;
}

public void mouseEntered(MouseEvent e){}

public void mouseExited(MouseEvent e) {}

public void mouseClicked(MouseEvent e) {}

public void mouseDragged(MouseEvent e){
    rightx=e.getX();
    righty=e.getY();
    repaint();

}  //负责处理拖动鼠标触发的鼠标事件。

public void mouseMoved(MouseEvent e)  {ox=-1;oy=-1;}

}
