Attribute VB_Name = "Module1"
'定义需要用到的数据结构
Public Type VCI_BOARD_INFO
    hw_Version As Integer
    fw_Version As Integer
    dr_Version As Integer
    in_Version As Integer
    irq_num As Integer
    can_num As Byte
    str_Serial_Num(19) As Byte
    str_hw_Type(39) As Byte
    Reserved(3) As Integer
End Type

Public Type VCI_CAN_OBJ
    ID As Long
    TimeStamp As Long
    TimeFlag As Byte
    SendType As Byte
    RemoteFlag As Byte
    ExternFlag As Byte
    DataLen As Byte
    data(7) As Byte
    Reserved(2) As Byte
End Type

Public Type VCI_CAN_STATUS
    ErrInterrupt As Byte
    regMode As Byte
    regStatus As Byte
    regALCapture As Byte
    regECCapture As Byte
    regEWLimit As Byte
    regRECounter As Byte
    regTECounter As Byte
    Reserved As Long
End Type

Public Type VCI_ERR_INFO
    ErrCode As Long
    Passive_ErrData(2) As Byte
    ArLost_ErrData As Byte
End Type

Public Type VCI_INIT_CONFIG
    AccCode As Long
    AccMask As Long
    Reserved As Long
    Filter As Byte
    Timing0 As Byte
    Timing1 As Byte
    Mode As Byte
End Type


Declare Function VCI_OpenDevice Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal Reserved As Long) As Long

Declare Function VCI_CloseDevice Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long) As Long

Declare Function VCI_InitCAN Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long, ByRef InitConfig As VCI_INIT_CONFIG) As Long

Declare Function VCI_ReadBoardInfo Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByRef info As VCI_BOARD_INFO) As Long

Declare Function VCI_ReadErrInfo Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long, ByRef ErrInfo As VCI_ERR_INFO) As Long

Declare Function VCI_ReadCANStatus Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long, ByRef CANStatus As VCI_CAN_STATUS) As Long

Declare Function VCI_GetReference Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long, ByVal RefType As Long, ByRef data As Any) As Long

Declare Function VCI_SetReference Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long, ByVal RefType As Long, ByRef data As Any) As Long

Declare Function VCI_GetReceiveNum Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long) As Long

Declare Function VCI_ClearBuffer Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long) As Long

Declare Function VCI_StartCAN Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long) As Long

Declare Function VCI_ResetCAN Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long) As Long

Declare Function VCI_Transmit Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long, ByRef Send As VCI_CAN_OBJ, ByVal length As Long) As Long

Declare Function VCI_Receive Lib "ControlCAN.dll" (ByVal DeviceType As Long, ByVal DeviceInd As Long, ByVal CANInd As Long, ByRef Receive As VCI_CAN_OBJ, ByVal length As Long, ByVal WaitTime As Long) As Long

