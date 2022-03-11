package huatu;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileFilter;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileFilter;
import java.util.Calendar.*;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.awt.*;
import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class  win extends JFrame  implements ActionListener
{
    JMenuBar jmb = new JMenuBar();
    JMenu jm = new JMenu("文件(F)");
    JMenuItem jmi1 = new JMenuItem("打开（未实现）");
    JMenuItem jmi2 = new JMenuItem("保存（未实现）");
    JMenu menu1=new JMenu("形状(S)");
    JMenuItem item11=new JMenuItem("直线");
    JMenuItem item12=new JMenuItem("矩形");
    JMenuItem item13=new JMenuItem("椭圆形");
    JMenuItem item14=new JMenuItem("圆形");
    JMenuItem item15=new JMenuItem("正方形");
    JMenuItem item16=new JMenuItem("多边形");
    JMenuItem item17=new JMenuItem("反走样直线");
    JMenu menu2=new JMenu("颜色(C)");
    JMenuItem item21=new JMenuItem("红色");
    JMenuItem item22=new JMenuItem("绿色");
    JMenuItem item23=new JMenuItem("蓝色");
    JMenuItem item24=new JMenuItem("黄色");
    JMenuItem item25=new JMenuItem("黑色");
    JMenu menu3=new JMenu("实心形状(M)");
    JMenuItem item31=new JMenuItem("实心矩形");
    JMenuItem item32=new JMenuItem("实心圆");
    JMenuItem item33=new JMenuItem("多边形填充（未实现）");
    JMenu menu4=new JMenu("工具(T)");
    JMenuItem item41=new JMenuItem("橡皮檫");
    JMenu menu5=new JMenu("线型(M)");
    JMenuItem item51=new JMenuItem("实线");
    JMenuItem item52=new JMenuItem("虚线（未实现）");
    JMenuItem item53=new JMenuItem("点画线（未实现）");
    JMenu menu6=new JMenu("线宽(W)");
    JMenuItem item61=new JMenuItem("细线");
    JMenuItem item62=new JMenuItem("粗线");
    JButton button1=new JButton("长方形");
    JButton button2=new JButton("椭圆");
    
    my pane=new my();
    
//    JFileChooser fileDialog=new JFileChooser();
JFileChooser fileDialog=new JFileChooser();
BufferedReader in;
FileReader fileReader;
BufferedWriter out;
FileWriter fileWriter;
File dir;
    String name;
    win()
   {    
     init();
     setTitle("画图");
     setBounds(100,100,500,300);
     setVisible(true);
     setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   }

    void init(){
     add(pane,BorderLayout.CENTER);
     jm.add(jmi1);
jm.add(jmi2);
jmb.add(jm);
menu1.add(item11);
menu1.add(item12);
menu1.add(item13);
menu1.add(item14);
menu1.add(item15);
menu1.add(item16);
menu1.add(item17);
menu2.add(item21);
menu2.add(item22);
menu2.add(item23);
menu2.add(item24);
menu2.add(item25);
menu3.add(item31);
menu3.add(item32);
menu3.add(item33);
menu4.add(item41);
menu5.add(item51);
menu5.add(item52);
menu5.add(item53);
menu6.add(item61);
menu6.add(item62);
jmb.add(menu1);
jmb.add(menu2);
jmb.add(menu3);
jmb.add(menu4);
jmb.add(menu5);
jmb.add(menu6);
setJMenuBar(jmb);

jmi1.addActionListener(this);
jmi2.addActionListener(this);
item11.addActionListener(this);
item12.addActionListener(this);
item13.addActionListener(this);
item14.addActionListener(this);
item15.addActionListener(this);
item16.addActionListener(this);
item17.addActionListener(this);
item21.addActionListener(this);
item22.addActionListener(this);
item23.addActionListener(this);
item24.addActionListener(this);
item25.addActionListener(this);
item31.addActionListener(this);
item32.addActionListener(this);
item33.addActionListener(this);
item41.addActionListener(this);
item51.addActionListener(this);
item52.addActionListener(this);
item53.addActionListener(this);
item61.addActionListener(this);
item62.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e){
       if (e.getSource()== item11){
       pane.f=0;
   }

   if (e.getSource()== item12){
   pane.f=1;
   }

   if (e.getSource()== item13){
   pane.f=2;
   }

   if (e.getSource()== item31){
   pane.f=3;
   }

   if (e.getSource()== item32){
   pane.f=4;
   }

   if (e.getSource()== item21){
   pane.color=Color.red;
   }

   if (e.getSource()== item22){
   pane.color = Color.green;
   }

   if (e.getSource()== item23){
   pane.color = Color.blue;
   }

   if (e.getSource()== item24){
   pane.color = Color.yellow;
   }

   if (e.getSource()== item25){
   pane.color = Color.black;
   }

   if (e.getSource()== item41){
//   pane.color = Color.black;
   pane.f=5;
   }
   
   if (e.getSource()== item51){
   pane.f=0;
   }
   
   if (e.getSource()== item61){
   pane.f=11;
   }
   
   if (e.getSource()== item62){
   pane.f=10;
   }
   
   if (e.getSource()== item14){
   pane.f=6;
   }
   
   if (e.getSource()== item15){
   pane.f=7;
   }
   
   if (e.getSource()== item16){
   pane.f=8;
   }
   
   if (e.getSource()== item17){
   pane.f=9;
   }
   
   if (e.getSource()== item33){
   pane.f=12;
   }
   
   if(e.getSource()==jmi1){}

   if(e.getSource()==jmi2){}

    }
}
