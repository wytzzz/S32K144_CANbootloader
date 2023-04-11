

Option Strict Off
Option Explicit On

Imports System.Runtime.InteropServices

Module Module1
    '������Ҫ�õ������ݽṹ

    Public Const VCI_PCI5121 As Int32 = 1
    Public Const VCI_PCI9810 As Int32 = 2
    Public Const VCI_USBCAN1 As Int32 = 3
    Public Const VCI_USBCAN2 As Int32 = 4
    Public Const VCI_USBCAN2A As Int32 = 4
    Public Const VCI_PCI9820 As Int32 = 5
    Public Const VCI_CAN232 As Int32 = 6
    Public Const VCI_PCI5110 As Int32 = 7
    Public Const VCI_CANLITE As Int32 = 8
    Public Const VCI_ISA9620 As Int32 = 9
    Public Const VCI_ISA5420 As Int32 = 10
    Public Const VCI_PC104CAN As Int32 = 11
    Public Const VCI_CANETUDP As Int32 = 12
    Public Const VCI_CANETE As Int32 = 12
    Public Const VCI_DNP9810 As Int32 = 13
    Public Const VCI_PCI9840 As Int32 = 14
    Public Const VCI_PC104CAN2 As Int32 = 15
    Public Const VCI_PCI9820I As Int32 = 16
    Public Const VCI_CANETTCP As Int32 = 17
    Public Const VCI_PEC9920 As Int32 = 18
    Public Const VCI_PCI5010U As Int32 = 19
    Public Const VCI_USBCAN_E_U As Int32 = 20
    Public Const VCI_USBCAN_2E_U As Int32 = 21
    Public Const VCI_PCI5020U As Int32 = 22
    Public Const VCI_EG2OT_CAN As Int32 = 23

  Public Structure VCI_BOARD_INFO
    Dim hw_Version As Short
    Dim fw_Version As Short
    Dim dr_Version As Short
    Dim in_Version As Short
    Dim irq_num As Short
    Dim can_num As Byte
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=20)> Dim str_Serial_Num() As Byte
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=40)> Dim str_hw_Type() As Byte
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=4)> Dim Reserved() As Short

        'Public Sub Initialize()
        '  ReDim str_Serial_Num(19)
        '  ReDim str_hw_Type(39)
        '  ReDim Reserved(3)
        'End Sub
  End Structure

  Public Structure VCI_CAN_OBJ
    Dim ID As Integer
    Dim TimeStamp As Integer
    Dim TimeFlag As Byte
    Dim SendType As Byte
    Dim RemoteFlag As Byte
    Dim ExternFlag As Byte
        Dim DataLen As Byte

        Dim data0 As Byte
        Dim data1 As Byte
        Dim data2 As Byte
        Dim data3 As Byte
        Dim data4 As Byte
        Dim data5 As Byte
        Dim data6 As Byte
        Dim data7 As Byte

        Dim Reserved0 As Byte
        Dim Reserved1 As Byte
        Dim Reserved2 As Byte

    End Structure

  Public Structure VCI_CAN_STATUS
    Dim ErrInterrupt As Byte
    Dim regMode As Byte
    Dim regStatus As Byte
    Dim regALCapture As Byte
    Dim regECCapture As Byte
    Dim regEWLimit As Byte
    Dim regRECounter As Byte
    Dim regTECounter As Byte
    Dim Reserved As Integer
  End Structure

  Public Structure VCI_ERR_INFO
    Dim ErrCode As Integer
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=3)> Dim Passive_ErrData() As Byte
    Dim ArLost_ErrData As Byte

        'Public Sub Initialize()
        '  ReDim Passive_ErrData(2)
        'End Sub
  End Structure

  Public Structure VCI_INIT_CONFIG
    Dim AccCode As Integer
    Dim AccMask As Integer
    Dim Reserved As Integer
    Dim Filter_Renamed As Byte
    Dim Timing0 As Byte
    Dim Timing1 As Byte
    Dim Mode As Byte
    End Structure

    Public Structure VCI_SEND_ONE
        Dim data0 As Byte
        Dim data1 As Byte
        Dim data2 As Byte
        Dim data3 As Byte
        Dim data4 As Byte
        Dim data5 As Byte
        Dim data6 As Byte
        Dim data7 As Byte
    End Structure


    '���豸����ڲ���DeviceType��ʾ�豸���ͺţ�DeviceInd��ʾ�豸�����ţ�������ӿں�����ʹ���ֲᣩ�����豸ΪCAN232ʱReserved��ʾ�򿪴��ڵĲ����ʣ���Ϊ�����豸ʱ����������
    Declare Function VCI_OpenDevice Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal Reserved As Integer) As Integer
  '�ر��豸
  Declare Function VCI_CloseDevice Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer) As Integer
  '��ʼ��ָ����CAN
  Declare Function VCI_InitCAN Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal CANInd As Integer, ByRef InitConfig As VCI_INIT_CONFIG) As Integer
  '��ȡ�豸��Ϣ
    Declare Function VCI_ReadBoardInfo Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByRef info As VCI_BOARD_INFO) As Integer
  '��ȡ���һ�δ�����Ϣ
    Declare Function VCI_ReadErrInfo Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal CANInd As Integer, ByRef ErrInfo As VCI_ERR_INFO) As Integer
  '��ȡCAN״̬
  Declare Function VCI_ReadCANStatus Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal CANInd As Integer, ByRef CANStatus As VCI_CAN_STATUS) As Integer
  '��ȡ�豸����Ӧ����
  Declare Function VCI_GetReference Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal CANInd As Integer, ByVal RefType As Integer, ByRef data As Long) As Integer
  '�����豸����Ӧ��������Ҫ����ͬ�豸���ض�����
  Declare Function VCI_SetReference Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal CANInd As Integer, ByVal RefType As Integer, ByRef data As Long) As Integer
  '��ȡָ�����ջ������н��յ�����δ����ȡ��֡��
  Declare Function VCI_GetReceiveNum Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal CANInd As Integer) As Integer
  '���ָ��������
  Declare Function VCI_ClearBuffer Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal CANInd As Integer) As Integer
  '����CAN
  Declare Function VCI_StartCAN Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal CANInd As Integer) As Integer
  '��λCAN
  Declare Function VCI_ResetCAN Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal CANInd As Integer) As Integer
  '��ָ���ĵ��豸��������
    Declare Function VCI_Transmit Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal CANInd As Integer, ByRef Sendbuf As VCI_CAN_OBJ, ByVal length As Integer) As Integer
  '��ָ�����豸��ȡ����
    Declare Function VCI_Receive Lib "ControlCAN.dll" (ByVal DeviceType As Integer, ByVal DeviceInd As Integer, ByVal CANInd As Integer, ByRef Receive As VCI_CAN_OBJ, ByVal length As Integer, ByVal WaitTime As Integer) As Integer

  Public Sub bytecpy(ByRef desarr() As Byte, ByVal desoff As Long, ByVal srcarr() As Byte, ByVal srcoff As Long, ByVal len As Long)
    Dim i As Long

    For i = 0 To len - 1
      desarr(desoff + i) = srcarr(i + srcoff)
    Next
  End Sub
  

End Module