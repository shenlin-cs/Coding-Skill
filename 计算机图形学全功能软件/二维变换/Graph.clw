; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGraphView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Graph.h"
LastPage=0

ClassCount=6
Class1=CGraphApp
Class2=CGraphDoc
Class3=CGraphView
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_TOOL_CTRL_BAR
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Resource3=IDR_MAINFRAME
Resource4=IDD_EDIT_DIALOG
Class6=CCoordinate
Resource5=IDD_COOR_DIALOG

[CLS:CGraphApp]
Type=0
HeaderFile=Graph.h
ImplementationFile=Graph.cpp
Filter=N
LastObject=IDC_CMD_EDIT
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CGraphDoc]
Type=0
HeaderFile=GraphDoc.h
ImplementationFile=GraphDoc.cpp
Filter=N
LastObject=CGraphDoc

[CLS:CGraphView]
Type=0
HeaderFile=GraphView.h
ImplementationFile=GraphView.cpp
Filter=C
LastObject=CGraphView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDC_READ
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Graph.cpp
ImplementationFile=Graph.cpp
Filter=D
LastObject=IDC_CUT

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=IDC_READ
Command18=IDC_COORD
Command19=IDC_MOVE_COORD
CommandCount=19

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_TOOL_CTRL_BAR]
Type=1
Class=?
Command1=IDC_FILL
Command2=IDC_ZOOM
Command3=IDC_MOVE_H
Command4=IDC_MOVE_V
Command5=IDC_RORATE
Command6=IDC_SHEAR_H
Command7=IDC_SHEAR_V
Command8=IDC_IMAGE_H
Command9=IDC_IMAGE_V
Command10=IDC_BACKUP
Command11=IDC_CLEAR
Command12=IDC_CUT
CommandCount=12

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=IDC_COORD
Command10=IDC_MOVE_COORD
Command11=IDC_READ
CommandCount=11

[DLG:IDD_EDIT_DIALOG]
Type=1
Class=?
ControlCount=1
Control1=IDC_CMD_EDIT,edit,1352728644

[CLS:CCoordinate]
Type=0
HeaderFile=Coordinate.h
ImplementationFile=Coordinate.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_COOR_DIALOG]
Type=1
Class=CCoordinate
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

