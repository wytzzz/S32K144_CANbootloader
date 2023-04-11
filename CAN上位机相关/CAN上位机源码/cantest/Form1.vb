Option Strict Off
Option Explicit On 
Imports VB = Microsoft.VisualBasic

Public Class Form1
    Inherits System.Windows.Forms.Form

#Region " Windows 窗体设计器生成的代码 "

    Public Sub New()
        MyBase.New()

        '该调用是 Windows 窗体设计器所必需的。
        InitializeComponent()

        '在 InitializeComponent() 调用之后添加任何初始化

    End Sub

    '窗体重写 dispose 以清理组件列表。
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Windows 窗体设计器所必需的
    Private components As System.ComponentModel.IContainer

    '注意: 以下过程是 Windows 窗体设计器所必需的
    '可以使用 Windows 窗体设计器修改此过程。
    '不要使用代码编辑器修改它。
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox3 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox4 As System.Windows.Forms.GroupBox
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents Label13 As System.Windows.Forms.Label
    Friend WithEvents butSend As System.Windows.Forms.Button
    Friend WithEvents cboMode As System.Windows.Forms.ComboBox
    Friend WithEvents txtTimer1 As System.Windows.Forms.TextBox
    Friend WithEvents txtTimer0 As System.Windows.Forms.TextBox
    Friend WithEvents cboFilterMode As System.Windows.Forms.ComboBox
    Friend WithEvents txtScreenCode As System.Windows.Forms.TextBox
    Friend WithEvents txtCheckCode As System.Windows.Forms.TextBox
    Friend WithEvents cboCANNum As System.Windows.Forms.ComboBox
    Friend WithEvents cboIndexNum As System.Windows.Forms.ComboBox
    Friend WithEvents txtFrameID As System.Windows.Forms.TextBox
    Friend WithEvents cboFrameFormat As System.Windows.Forms.ComboBox
    Friend WithEvents cboFrameType As System.Windows.Forms.ComboBox
    Friend WithEvents txtDate As System.Windows.Forms.TextBox
    Friend WithEvents cboSendFormat As System.Windows.Forms.ComboBox
    Friend WithEvents butStartUp As System.Windows.Forms.Button
    Friend WithEvents butReplacement As System.Windows.Forms.Button
    Friend WithEvents lstInfo As System.Windows.Forms.ListBox
    Friend WithEvents tmrRead As System.Windows.Forms.Timer
    Friend WithEvents cboDevtype As System.Windows.Forms.ComboBox
    Friend WithEvents Label14 As System.Windows.Forms.Label
    Friend WithEvents TextBox1 As TextBox
    Friend WithEvents Label15 As Label
    Friend WithEvents FileSet As Button
    Friend WithEvents butConnect As System.Windows.Forms.Button
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.cboDevtype = New System.Windows.Forms.ComboBox()
        Me.Label14 = New System.Windows.Forms.Label()
        Me.GroupBox2 = New System.Windows.Forms.GroupBox()
        Me.cboMode = New System.Windows.Forms.ComboBox()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.txtTimer1 = New System.Windows.Forms.TextBox()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.txtTimer0 = New System.Windows.Forms.TextBox()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.cboFilterMode = New System.Windows.Forms.ComboBox()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.txtScreenCode = New System.Windows.Forms.TextBox()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.txtCheckCode = New System.Windows.Forms.TextBox()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.cboCANNum = New System.Windows.Forms.ComboBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.cboIndexNum = New System.Windows.Forms.ComboBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.GroupBox3 = New System.Windows.Forms.GroupBox()
        Me.butSend = New System.Windows.Forms.Button()
        Me.txtFrameID = New System.Windows.Forms.TextBox()
        Me.Label13 = New System.Windows.Forms.Label()
        Me.cboFrameFormat = New System.Windows.Forms.ComboBox()
        Me.Label12 = New System.Windows.Forms.Label()
        Me.cboFrameType = New System.Windows.Forms.ComboBox()
        Me.Label11 = New System.Windows.Forms.Label()
        Me.txtDate = New System.Windows.Forms.TextBox()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.cboSendFormat = New System.Windows.Forms.ComboBox()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.butStartUp = New System.Windows.Forms.Button()
        Me.butReplacement = New System.Windows.Forms.Button()
        Me.GroupBox4 = New System.Windows.Forms.GroupBox()
        Me.lstInfo = New System.Windows.Forms.ListBox()
        Me.tmrRead = New System.Windows.Forms.Timer(Me.components)
        Me.butConnect = New System.Windows.Forms.Button()
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.Label15 = New System.Windows.Forms.Label()
        Me.FileSet = New System.Windows.Forms.Button()
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.cboDevtype)
        Me.GroupBox1.Controls.Add(Me.Label14)
        Me.GroupBox1.Controls.Add(Me.GroupBox2)
        Me.GroupBox1.Controls.Add(Me.cboCANNum)
        Me.GroupBox1.Controls.Add(Me.Label2)
        Me.GroupBox1.Controls.Add(Me.cboIndexNum)
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.Location = New System.Drawing.Point(8, 8)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(480, 144)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "设备参数"
        '
        'cboDevtype
        '
        Me.cboDevtype.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cboDevtype.Items.AddRange(New Object() {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"})
        Me.cboDevtype.Location = New System.Drawing.Point(62, 22)
        Me.cboDevtype.MaxDropDownItems = 15
        Me.cboDevtype.Name = "cboDevtype"
        Me.cboDevtype.Size = New System.Drawing.Size(137, 20)
        Me.cboDevtype.TabIndex = 7
        '
        'Label14
        '
        Me.Label14.Location = New System.Drawing.Point(4, 24)
        Me.Label14.Name = "Label14"
        Me.Label14.Size = New System.Drawing.Size(52, 16)
        Me.Label14.TabIndex = 6
        Me.Label14.Text = "类型号:"
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.cboMode)
        Me.GroupBox2.Controls.Add(Me.Label8)
        Me.GroupBox2.Controls.Add(Me.txtTimer1)
        Me.GroupBox2.Controls.Add(Me.Label7)
        Me.GroupBox2.Controls.Add(Me.txtTimer0)
        Me.GroupBox2.Controls.Add(Me.Label6)
        Me.GroupBox2.Controls.Add(Me.cboFilterMode)
        Me.GroupBox2.Controls.Add(Me.Label5)
        Me.GroupBox2.Controls.Add(Me.txtScreenCode)
        Me.GroupBox2.Controls.Add(Me.Label4)
        Me.GroupBox2.Controls.Add(Me.txtCheckCode)
        Me.GroupBox2.Controls.Add(Me.Label3)
        Me.GroupBox2.Location = New System.Drawing.Point(8, 56)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(464, 80)
        Me.GroupBox2.TabIndex = 5
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "初始化CAN参数"
        '
        'cboMode
        '
        Me.cboMode.Location = New System.Drawing.Point(376, 48)
        Me.cboMode.Name = "cboMode"
        Me.cboMode.Size = New System.Drawing.Size(80, 20)
        Me.cboMode.TabIndex = 11
        '
        'Label8
        '
        Me.Label8.Location = New System.Drawing.Point(336, 50)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(48, 16)
        Me.Label8.TabIndex = 10
        Me.Label8.Text = "模式："
        '
        'txtTimer1
        '
        Me.txtTimer1.Location = New System.Drawing.Point(233, 47)
        Me.txtTimer1.Name = "txtTimer1"
        Me.txtTimer1.Size = New System.Drawing.Size(63, 21)
        Me.txtTimer1.TabIndex = 9
        Me.txtTimer1.Text = "1C"
        '
        'Label7
        '
        Me.Label7.Location = New System.Drawing.Point(158, 50)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(73, 16)
        Me.Label7.TabIndex = 8
        Me.Label7.Text = "定时器1：0x"
        '
        'txtTimer0
        '
        Me.txtTimer0.Location = New System.Drawing.Point(88, 48)
        Me.txtTimer0.Name = "txtTimer0"
        Me.txtTimer0.Size = New System.Drawing.Size(56, 21)
        Me.txtTimer0.TabIndex = 7
        Me.txtTimer0.Text = "00"
        '
        'Label6
        '
        Me.Label6.Location = New System.Drawing.Point(10, 48)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(80, 16)
        Me.Label6.TabIndex = 6
        Me.Label6.Text = "定时器0：0x"
        '
        'cboFilterMode
        '
        Me.cboFilterMode.Location = New System.Drawing.Point(376, 17)
        Me.cboFilterMode.Name = "cboFilterMode"
        Me.cboFilterMode.Size = New System.Drawing.Size(80, 20)
        Me.cboFilterMode.TabIndex = 5
        '
        'Label5
        '
        Me.Label5.Location = New System.Drawing.Point(312, 20)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(72, 16)
        Me.Label5.TabIndex = 4
        Me.Label5.Text = "滤波方式："
        '
        'txtScreenCode
        '
        Me.txtScreenCode.Location = New System.Drawing.Point(233, 16)
        Me.txtScreenCode.Name = "txtScreenCode"
        Me.txtScreenCode.Size = New System.Drawing.Size(64, 21)
        Me.txtScreenCode.TabIndex = 3
        Me.txtScreenCode.Text = "FFFFFFFF"
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(164, 19)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(68, 16)
        Me.Label4.TabIndex = 2
        Me.Label4.Text = "屏蔽码：0x"
        '
        'txtCheckCode
        '
        Me.txtCheckCode.Location = New System.Drawing.Point(88, 14)
        Me.txtCheckCode.Name = "txtCheckCode"
        Me.txtCheckCode.Size = New System.Drawing.Size(56, 21)
        Me.txtCheckCode.TabIndex = 1
        Me.txtCheckCode.Text = "00000000"
        '
        'Label3
        '
        Me.Label3.Location = New System.Drawing.Point(16, 17)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(72, 16)
        Me.Label3.TabIndex = 0
        Me.Label3.Text = "验收码：0x"
        '
        'cboCANNum
        '
        Me.cboCANNum.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cboCANNum.Location = New System.Drawing.Point(403, 21)
        Me.cboCANNum.Name = "cboCANNum"
        Me.cboCANNum.Size = New System.Drawing.Size(59, 20)
        Me.cboCANNum.TabIndex = 3
        '
        'Label2
        '
        Me.Label2.Location = New System.Drawing.Point(331, 25)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(72, 15)
        Me.Label2.TabIndex = 2
        Me.Label2.Text = "第几路CAN:"
        '
        'cboIndexNum
        '
        Me.cboIndexNum.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cboIndexNum.Location = New System.Drawing.Point(261, 21)
        Me.cboIndexNum.Name = "cboIndexNum"
        Me.cboIndexNum.Size = New System.Drawing.Size(64, 20)
        Me.cboIndexNum.TabIndex = 1
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(205, 24)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(50, 16)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "索引号:"
        '
        'GroupBox3
        '
        Me.GroupBox3.Controls.Add(Me.butSend)
        Me.GroupBox3.Controls.Add(Me.txtFrameID)
        Me.GroupBox3.Controls.Add(Me.Label13)
        Me.GroupBox3.Controls.Add(Me.cboFrameFormat)
        Me.GroupBox3.Controls.Add(Me.Label12)
        Me.GroupBox3.Controls.Add(Me.cboFrameType)
        Me.GroupBox3.Controls.Add(Me.Label11)
        Me.GroupBox3.Controls.Add(Me.txtDate)
        Me.GroupBox3.Controls.Add(Me.Label10)
        Me.GroupBox3.Controls.Add(Me.cboSendFormat)
        Me.GroupBox3.Controls.Add(Me.Label9)
        Me.GroupBox3.Location = New System.Drawing.Point(8, 158)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(576, 87)
        Me.GroupBox3.TabIndex = 1
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "发送数据帧"
        '
        'butSend
        '
        Me.butSend.Location = New System.Drawing.Point(368, 48)
        Me.butSend.Name = "butSend"
        Me.butSend.Size = New System.Drawing.Size(56, 24)
        Me.butSend.TabIndex = 10
        Me.butSend.Text = "发送"
        '
        'txtFrameID
        '
        Me.txtFrameID.Location = New System.Drawing.Point(456, 17)
        Me.txtFrameID.Name = "txtFrameID"
        Me.txtFrameID.Size = New System.Drawing.Size(80, 21)
        Me.txtFrameID.TabIndex = 9
        Me.txtFrameID.Text = "1ff"
        '
        'Label13
        '
        Me.Label13.Location = New System.Drawing.Point(414, 21)
        Me.Label13.Name = "Label13"
        Me.Label13.Size = New System.Drawing.Size(48, 16)
        Me.Label13.TabIndex = 8
        Me.Label13.Text = "帧ID："
        '
        'cboFrameFormat
        '
        Me.cboFrameFormat.Location = New System.Drawing.Point(339, 17)
        Me.cboFrameFormat.Name = "cboFrameFormat"
        Me.cboFrameFormat.Size = New System.Drawing.Size(64, 20)
        Me.cboFrameFormat.TabIndex = 7
        '
        'Label12
        '
        Me.Label12.Location = New System.Drawing.Point(287, 21)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(64, 16)
        Me.Label12.TabIndex = 6
        Me.Label12.Text = "帧格式："
        '
        'cboFrameType
        '
        Me.cboFrameType.Location = New System.Drawing.Point(210, 17)
        Me.cboFrameType.Name = "cboFrameType"
        Me.cboFrameType.Size = New System.Drawing.Size(72, 20)
        Me.cboFrameType.TabIndex = 5
        '
        'Label11
        '
        Me.Label11.Location = New System.Drawing.Point(158, 22)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(64, 16)
        Me.Label11.TabIndex = 4
        Me.Label11.Text = "帧类型："
        '
        'txtDate
        '
        Me.txtDate.Location = New System.Drawing.Point(72, 48)
        Me.txtDate.Name = "txtDate"
        Me.txtDate.Size = New System.Drawing.Size(280, 21)
        Me.txtDate.TabIndex = 3
        Me.txtDate.Text = "01 02 03 04 05 06 07 08 "
        '
        'Label10
        '
        Me.Label10.Location = New System.Drawing.Point(31, 48)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(48, 16)
        Me.Label10.TabIndex = 2
        Me.Label10.Text = "数据："
        '
        'cboSendFormat
        '
        Me.cboSendFormat.Location = New System.Drawing.Point(71, 17)
        Me.cboSendFormat.Name = "cboSendFormat"
        Me.cboSendFormat.Size = New System.Drawing.Size(80, 20)
        Me.cboSendFormat.TabIndex = 1
        '
        'Label9
        '
        Me.Label9.Location = New System.Drawing.Point(8, 19)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(80, 16)
        Me.Label9.TabIndex = 0
        Me.Label9.Text = "发送格式："
        '
        'butStartUp
        '
        Me.butStartUp.Location = New System.Drawing.Point(512, 64)
        Me.butStartUp.Name = "butStartUp"
        Me.butStartUp.Size = New System.Drawing.Size(64, 24)
        Me.butStartUp.TabIndex = 2
        Me.butStartUp.Text = "启动CAN"
        '
        'butReplacement
        '
        Me.butReplacement.Location = New System.Drawing.Point(512, 112)
        Me.butReplacement.Name = "butReplacement"
        Me.butReplacement.Size = New System.Drawing.Size(64, 24)
        Me.butReplacement.TabIndex = 3
        Me.butReplacement.Text = "复位CAN"
        '
        'GroupBox4
        '
        Me.GroupBox4.Controls.Add(Me.lstInfo)
        Me.GroupBox4.Location = New System.Drawing.Point(4, 310)
        Me.GroupBox4.Name = "GroupBox4"
        Me.GroupBox4.Size = New System.Drawing.Size(576, 191)
        Me.GroupBox4.TabIndex = 4
        Me.GroupBox4.TabStop = False
        Me.GroupBox4.Text = "信息"
        '
        'lstInfo
        '
        Me.lstInfo.ItemHeight = 12
        Me.lstInfo.Location = New System.Drawing.Point(6, 18)
        Me.lstInfo.Name = "lstInfo"
        Me.lstInfo.Size = New System.Drawing.Size(560, 160)
        Me.lstInfo.TabIndex = 0
        '
        'tmrRead
        '
        Me.tmrRead.Enabled = True
        '
        'butConnect
        '
        Me.butConnect.Location = New System.Drawing.Point(512, 24)
        Me.butConnect.Name = "butConnect"
        Me.butConnect.Size = New System.Drawing.Size(64, 24)
        Me.butConnect.TabIndex = 5
        Me.butConnect.Text = "连接设备"
        '
        'TextBox1
        '
        Me.TextBox1.Location = New System.Drawing.Point(47, 270)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(160, 21)
        Me.TextBox1.TabIndex = 6
        Me.TextBox1.Text = "test.bin"
        '
        'Label15
        '
        Me.Label15.AutoSize = True
        Me.Label15.Location = New System.Drawing.Point(12, 273)
        Me.Label15.Name = "Label15"
        Me.Label15.Size = New System.Drawing.Size(29, 12)
        Me.Label15.TabIndex = 7
        Me.Label15.Text = "文件"
        '
        'FileSet
        '
        Me.FileSet.Location = New System.Drawing.Point(238, 268)
        Me.FileSet.Name = "FileSet"
        Me.FileSet.Size = New System.Drawing.Size(75, 23)
        Me.FileSet.TabIndex = 8
        Me.FileSet.Text = "发送"
        Me.FileSet.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(6, 14)
        Me.ClientSize = New System.Drawing.Size(592, 513)
        Me.Controls.Add(Me.FileSet)
        Me.Controls.Add(Me.Label15)
        Me.Controls.Add(Me.TextBox1)
        Me.Controls.Add(Me.butConnect)
        Me.Controls.Add(Me.GroupBox4)
        Me.Controls.Add(Me.butReplacement)
        Me.Controls.Add(Me.butStartUp)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox1)
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "Form1"
        Me.Text = "CANtest"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.GroupBox3.ResumeLayout(False)
        Me.GroupBox3.PerformLayout()
        Me.GroupBox4.ResumeLayout(False)
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

#End Region


    Dim m_devtype As Integer
    Dim m_connect As Byte
    Dim m_devind As Integer
    Dim m_cannum As Integer
    Dim SendType, frameformat As Object
    Dim frametype As Byte
    Dim ID As Integer
    Dim sendata(7) As Byte
    'Dim frameinfo(49) As VCI_CAN_OBJ
    Dim m_arrdevtype(20) As Int32




    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        m_connect = 0
        m_cannum = 0
        Dim i As Integer
        '初始化Combobox控件
        For i = 0 To 7
            cboIndexNum.Items.Add(i)
        Next

        cboCANNum.Items.Add(0)
        cboCANNum.Items.Add(1)
        cboCANNum.Items.Add(2)
        cboCANNum.Items.Add(3)

        cboFilterMode.Items.Add("双滤波")
        cboFilterMode.Items.Add("单滤波")

        cboMode.Items.Add("正常模式")
        cboMode.Items.Add("只听模式")

        cboSendFormat.Items.Add("正常发送")
        cboSendFormat.Items.Add("单次发送")
        cboSendFormat.Items.Add("自发自收")
        cboSendFormat.Items.Add("单次自发自收")

        cboFrameType.Items.Add("标准帧")
        cboFrameType.Items.Add("扩展帧")

        cboFrameFormat.Items.Add("数据帧")
        cboFrameFormat.Items.Add("远程帧")
        'tmrRead.Enabled = False
        cboIndexNum.SelectedIndex = 0
        cboCANNum.SelectedIndex = 0
        cboSendFormat.SelectedIndex = 2
        cboFrameType.SelectedIndex = 0
        cboFrameFormat.SelectedIndex = 0
        cboFilterMode.SelectedIndex = 1
        cboMode.SelectedIndex = 0


        'SendType = cboSendFormat.SelectedIndex
        'frameformat = cboFrameFormat.SelectedIndex
        'frametype = cboFrameType.SelectedIndex
        'ID = Val("&H" + txtFrameID.Text)

        'For i = 0 To frameinfo.Length - 1
        'frameinfo(i).Initialize()
        'frameinfo(i).DataLen = 0
        'frameinfo(i).ExternFlag = 0
        'frameinfo(i).RemoteFlag = 0
        'frameinfo(i).SendType = 0
        'frameinfo(i).ID = 0
        'frameinfo(i) = New VCI_CAN_OBJ(7, 2)
        'Next

        '
        Dim curindex As Int32 = 0
        cboDevtype.Items.Clear()

        curindex = cboDevtype.Items.Add("VCI_PCI5121")
        'cboDevtype.Items(0) = "VCI_PCI5121"
        'm_arrdevtype(0) = VCI_PCI5121
        m_arrdevtype(curindex) = VCI_PCI5121

        curindex = cboDevtype.Items.Add("VCI_PCI9810")
        'cboDevtype.Items(1) = "VCI_PCI9810"
        'm_arrdevtype(1) = VCI_PCI9810
        m_arrdevtype(curindex) = VCI_PCI9810

        curindex = cboDevtype.Items.Add("VCI_USBCAN1(I+)")
        'cboDevtype.Items(2) = "VCI_USBCAN1"
        'm_arrdevtype(2) = VCI_USBCAN1
        m_arrdevtype(curindex) = VCI_USBCAN1

        curindex = cboDevtype.Items.Add("VCI_USBCAN2(II+)")
        'cboDevtype.Items(3) = "VCI_USBCAN2"
        'm_arrdevtype(3) = VCI_USBCAN2
        m_arrdevtype(curindex) = VCI_USBCAN2

        curindex = cboDevtype.Items.Add("VCI_USBCAN2A")
        'cboDevtype.Items(4) = "VCI_USBCAN2A"
        'm_arrdevtype(4) = VCI_USBCAN2A
        m_arrdevtype(curindex) = VCI_USBCAN2A

        curindex = cboDevtype.Items.Add("VCI_PCI9820")
        'cboDevtype.Items(5) = "VCI_PCI9820"
        'm_arrdevtype(5) = VCI_PCI9820
        m_arrdevtype(curindex) = VCI_PCI9820

        curindex = cboDevtype.Items.Add("VCI_PCI5110")
        'cboDevtype.Items(6) = "VCI_PCI5110"
        'm_arrdevtype(6) = VCI_PCI5110
        m_arrdevtype(curindex) = VCI_PCI5110

        curindex = cboDevtype.Items.Add("VCI_ISA9620")
        'cboDevtype.Items(7) = "VCI_ISA9620"
        'm_arrdevtype(7) = VCI_ISA9620
        m_arrdevtype(curindex) = VCI_ISA9620

        curindex = cboDevtype.Items.Add("VCI_CANLITE")
        'cboDevtype.Items(15) = "VCI_CANLITE"
        'm_arrdevtype(15) = VCI_CANLITE
        m_arrdevtype(curindex) = VCI_CANLITE

        curindex = cboDevtype.Items.Add("VCI_ISA5420")
        'cboDevtype.Items(8) = "VCI_ISA5420"
        'm_arrdevtype(8) = VCI_ISA5420
        m_arrdevtype(curindex) = VCI_ISA5420

        curindex = cboDevtype.Items.Add("VCI_PC104CAN")
        'cboDevtype.Items(9) = "VCI_PC104CAN"
        'm_arrdevtype(9) = VCI_PC104CAN
        m_arrdevtype(curindex) = VCI_PC104CAN

        curindex = cboDevtype.Items.Add("VCI_DNP9810")
        'cboDevtype.Items(10) = "VCI_DNP9810"
        'm_arrdevtype(10) = VCI_DNP9810
        m_arrdevtype(curindex) = VCI_DNP9810

        curindex = cboDevtype.Items.Add("VCI_PCI9840")
        'cboDevtype.Items(11) = "VCI_PCI9840"
        'm_arrdevtype(11) = VCI_PCI9840
        m_arrdevtype(curindex) = VCI_PCI9840

        curindex = cboDevtype.Items.Add("VCI_PC104CAN2")
        'cboDevtype.Items(12) = "VCI_PC104CAN2"
        'm_arrdevtype(12) = VCI_PC104CAN2
        m_arrdevtype(curindex) = VCI_PC104CAN2

        curindex = cboDevtype.Items.Add("VCI_PCI9820I")
        'cboDevtype.Items(13) = "VCI_PCI9820I"
        'm_arrdevtype(13) = VCI_PCI9820I
        m_arrdevtype(curindex) = VCI_PCI9820I

        curindex = cboDevtype.Items.Add("VCI_PEC9920")
        'cboDevtype.Items(14) = "VCI_PEC9920"
        'm_arrdevtype(14) = VCI_PEC9920
        m_arrdevtype(curindex) = VCI_PEC9920



        cboDevtype.SelectedIndex = 3 '默认硬件是 USBCAN
        cboDevtype.MaxDropDownItems = cboDevtype.Items.Count

    End Sub

    Private Sub butStartUp_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles butStartUp.Click
        If m_connect = 0 Then
            MsgBox("请先打开端口")
            Exit Sub
        End If
        If VCI_StartCAN(m_devtype, m_devind, m_cannum) <> 1 Then
            MsgBox("启动CAN错误")
        Else
            lstInfo.Items.Add("启动CAN成功")
            'lstInfo.Items.Count()
        End If

    End Sub

    Private Sub butReplacement_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles butReplacement.Click
        If m_connect = 0 Then
            MsgBox("请先打开端口")
            Exit Sub
        End If
        If VCI_ResetCAN(m_devtype, m_devind, m_cannum) <> 1 Then
            MsgBox("复位CAN错误")
        Else
            lstInfo.Items.Add("复位CAN成功")
        End If

    End Sub

    Private Sub butSend_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles butSend.Click
        'Dim j As Object
        Dim i As Object
        Dim strdata As Object

        If m_connect = 0 Then
            MsgBox("请先打开端口")
            Exit Sub
        End If
        Dim frameinfo(0) As VCI_CAN_OBJ

        Dim str As String
        SendType = cboSendFormat.SelectedIndex
        frameformat = cboFrameFormat.SelectedIndex
        frametype = cboFrameType.SelectedIndex
        str = "&H"
        str = str + txtFrameID.Text
        ID = Val(str)
        str = txtDate.Text
        strdata = " "
        i = 0
        For i = 0 To 7

            strdata = VB.Left(str, 2)
            If Len(strdata) = 0 Then
                Exit For
            End If
            'If Len(str) - 3 >= 0 Then
            str = VB.Right(str, Len(str) - 3)
            'Else
            '    str = " "
            'End If
            sendata(i) = Val("&H" + strdata)
            'data(i) = strdata
        Next

        frameinfo(0).DataLen = i
        frameinfo(0).ExternFlag = frametype
        frameinfo(0).RemoteFlag = frameformat
        frameinfo(0).SendType = SendType
        frameinfo(0).ID = ID

        frameinfo(0).data0 = sendata(0)
        frameinfo(0).data1 = sendata(1)
        frameinfo(0).data2 = sendata(2)
        frameinfo(0).data3 = sendata(3)
        frameinfo(0).data4 = sendata(4)
        frameinfo(0).data5 = sendata(5)
        frameinfo(0).data6 = sendata(6)
        frameinfo(0).data7 = sendata(7)


        If VCI_Transmit(m_devtype, m_devind, m_cannum, frameinfo(0), 1) <> 1 Then
            MsgBox("发送数据失败")
        Else
            lstInfo.Items.Add("发送数据成功")
        End If
    End Sub

    Private Sub tmrRead_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles tmrRead.Tick
        tmrRead.Enabled = False
        Dim j As Object
        Dim tmpstr As Object
        Dim i As Object
        Dim ErrInfo(0) As VCI_ERR_INFO
        Dim data(7) As Byte
        If m_connect = 0 Then
            tmrRead.Enabled = True
            Exit Sub
        End If
        Dim length As Long
        Dim SendFrame(49) As VCI_CAN_OBJ        '接受数组长度50

        Dim str As String
        length = VCI_GetReceiveNum(m_devtype, m_devind, m_cannum)
        If length <= 0 Then
            VCI_ReadErrInfo(m_devtype, m_devind, m_cannum, ErrInfo(0)) '注意：如果没有读到数据则必须调用此函数来读取出当前的错误码，
            '千万不能省略这一步（即使你可能不想知道错误码是什么）
            tmrRead.Enabled = True
            Exit Sub
        End If

        length = VCI_Receive(m_devtype, m_devind, m_cannum, SendFrame(0), 50, 10)
        For i = 0 To length - 1
            str = "接收到数据帧:  "
            If SendFrame(i).TimeFlag = 0 Then
                tmpstr = "时间标识:无  "
            Else
                tmpstr = "时间标识:0x" + Hex(SendFrame(i).TimeStamp)
            End If
            str = str + tmpstr
            tmpstr = "  帧ID:0x" + Hex(SendFrame(i).ID)
            str = str + tmpstr
            str = str + "  帧格式:"
            If SendFrame(i).RemoteFlag = 0 Then
                tmpstr = "数据帧 "
            Else
                tmpstr = "远程帧 "
            End If
            str = str + tmpstr
            str = str + "  帧类型:"
            If SendFrame(i).ExternFlag = 0 Then
                tmpstr = "标准帧 "
            Else
                tmpstr = "扩展帧 "
            End If
            str = str + tmpstr
            lstInfo.Items.Add(str)
            If SendFrame(i).RemoteFlag = 0 Then
                str = "  数据:"
                If SendFrame(i).DataLen > 8 Then
                    SendFrame(i).DataLen = 8
                End If
                data(0) = SendFrame(i).data0
                data(1) = SendFrame(i).data1
                data(2) = SendFrame(i).data2
                data(3) = SendFrame(i).data3
                data(4) = SendFrame(i).data4
                data(5) = SendFrame(i).data5
                data(6) = SendFrame(i).data6
                data(7) = SendFrame(i).data7
                For j = 0 To SendFrame(i).DataLen - 1
                    tmpstr = Hex(data(j)) + " "
                    str = str + tmpstr
                Next
                lstInfo.Items.Add(str)
            End If
        Next
        tmrRead.Enabled = True
    End Sub

    Private Sub butConnect_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles butConnect.Click
        Dim index As Integer
        Dim cannum As Integer
        Dim code As Object
        Dim mask As Integer
        Dim Timing0, Timing1, filtertype As Object
        Dim Mode As Byte
        Dim InitConfig As VCI_INIT_CONFIG

        'Dim frameinfo(49) As VCI_CAN_OBJ
        'Dim SendType, frameformat As Object
        'Dim frametype As Byte
        'Dim ID As Integer
        'Dim data(7) As Byte

        'Dim k As VCI_BOARD_INFO

        If m_connect = 1 Then
            m_connect = 0
            butConnect.Text = "连接设备"
            VCI_CloseDevice(m_devtype, m_devind)
            Exit Sub
        End If
        If cboIndexNum.SelectedIndex <> -1 And cboCANNum.SelectedIndex <> -1 Then
            m_devtype = m_arrdevtype(cboDevtype.SelectedIndex)

            index = cboIndexNum.SelectedIndex
            cannum = cboCANNum.SelectedIndex
            filtertype = cboFilterMode.SelectedIndex
            Mode = cboMode.SelectedIndex
            code = Val("&H" + txtCheckCode.Text)
            mask = Val("&H" + txtScreenCode.Text)
            Timing0 = Val("&H" + txtTimer0.Text)
            Timing1 = Val("&H" + txtTimer1.Text)
            InitConfig.AccCode = code
            InitConfig.AccMask = mask
            InitConfig.Filter_Renamed = filtertype
            InitConfig.Mode = Mode
            InitConfig.Timing0 = Timing0
            InitConfig.Timing1 = Timing1

            If VCI_OpenDevice(m_devtype, index, 0) <> 1 Then        '见定义
                MsgBox("打开设备错误")
            Else
                If VCI_InitCAN(m_devtype, index, cannum, InitConfig) = 1 Then
                    m_connect = 1
                    m_devind = index
                    m_cannum = cannum
                    butConnect.Text = "断开设备"
                Else
                    MsgBox("初始化CAN错误")
                End If
            End If
        End If
    End Sub

    Private Sub cboFilterMode_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cboFilterMode.SelectedIndexChanged

    End Sub

    Private Sub GroupBox3_Enter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles GroupBox3.Enter

    End Sub

    Private Sub cboSendFormat_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cboSendFormat.SelectedIndexChanged

    End Sub

    Private Sub cboMode_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cboMode.SelectedIndexChanged

    End Sub


    Private Sub FileSet_Click(sender As Object, e As EventArgs) Handles FileSet.Click

        Dim datasendone As VCI_SEND_ONE
        Dim filepath As String
        'Dim fileReader() As Byte
        Dim fileone(7) As Byte

        'Dim butone(7) As String
        'Dim i As Integer
        'Dim filetype As String
        'Dim sendone As Object
        filepath = TextBox1.Text
        FileOpen(1, filepath, OpenMode.Binary)



        'ID
        Dim str As String
        Dim idnum As Integer
        str = "&H"
        str = str + txtFrameID.Text
        idnum = Val(str)

        '发送文件数据
        Dim filelen As New System.IO.FileInfo(filepath)
        Dim filelength As Integer = filelen.Length
        Dim i As Integer = 0
        Dim j As Integer = 0
        Dim m As Integer = 0
        'Dim datastr As String
        'datastr = ""
        'For m = 0 To 7
        '    datastr = datastr & str(fileone(m))
        'Next

        Do While filelength >= 8
            FileGet(1, fileone)
            datasendone.data0 = fileone(3)
            datasendone.data1 = fileone(2)
            datasendone.data2 = fileone(1)
            datasendone.data3 = fileone(0)
            datasendone.data4 = fileone(7)
            datasendone.data5 = fileone(6)
            datasendone.data6 = fileone(5)
            datasendone.data7 = fileone(4)

            'For m = 0 To 7
            '    datastr = datastr + str(datasendone.data0)
            'Next
            'datastr = datastr & str(fileone(0))




            If send(datasendone, idnum, 8) <> 1 Then
                'MsgBox("文件发送失败")
                'lstInfo.Items.Add(datastr)
                'Exit Do
                MsgBox("文件发送失败")
                Exit Do
            End If

            filelength = filelength - 8
            i = i + 1

        Loop

        'zuihou
        If filelength = 0 Then
            lstInfo.Items.Add("文件传输完毕")
        Else
            'FileGet(1, fileone)
            'For j = filelength To 7
            '    fileone(j) = 255
            'Next
            i = i + 1
            'datasendone.data0 = fileone(0)
            'datasendone.data1 = fileone(1)
            'datasendone.data2 = fileone(2)
            'datasendone.data3 = fileone(3)
            'datasendone.data4 = fileone(4)
            'datasendone.data5 = fileone(5)
            'datasendone.data6 = fileone(6)
            'datasendone.data7 = fileone(7)
            'send(datasendone, i, 8)
            Dim filelast(filelength - 1) As Byte
            FileGet(1, filelast)

            For j = 0 To filelength - 1
                fileone(j) = filelast(j)
            Next
            For j = filelength To 7
                fileone(j) = 255
            Next
            datasendone.data0 = fileone(3)
            datasendone.data1 = fileone(2)
            datasendone.data2 = fileone(1)
            datasendone.data3 = fileone(0)
            datasendone.data4 = fileone(7)
            datasendone.data5 = fileone(6)
            datasendone.data6 = fileone(5)
            datasendone.data7 = fileone(4)

            If send(datasendone, idnum, 8) = 1 Then
                MsgBox("文件发送成功")
                lstInfo.Items.Add("文件传输完毕")
            Else
                MsgBox("文件发送失败")
            End If

        End If


        ''fileReader = My.Computer.FileSystem.ReadAllBytes("filetest2.bin")
        'fileReader = My.Computer.FileSystem.ReadAllBytes(filepath)  '读操作前使用FileOpen（）会占用文件
        'filetype = Mid(filepath, filepath.Length - 2, 3)
        'If filetype = "bin" Then
        '    lstInfo.Items.Add("文件读取成功")
        'Else
        '    lstInfo.Items.Add("文件需要处理")
        'End If
        'FileClose(1)

        'lstInfo.Items.Add(butone)

        FileClose(1)
    End Sub

    Private Sub ButFileSend_Click(sender As Object, e As EventArgs)

    End Sub

    Private Sub lstInfo_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles lstInfo.SelectedIndexChanged

    End Sub

    Dim sendata1 As VCI_SEND_ONE
    Dim datalen As Integer
    Public Function send(sendata1, IDnum, datalen)
        'Dim i As Object = 8
        'Dim strdata As Object

        If m_connect = 0 Then
            MsgBox("请先打开端口")
            Return 0
            Exit Function
        End If
        Dim frameinfo(0) As VCI_CAN_OBJ

        'Dim str As String
        SendType = cboSendFormat.SelectedIndex
        frameformat = cboFrameFormat.SelectedIndex
        frametype = cboFrameType.SelectedIndex
        'str = "&H"
        'str = str + str(IDnum)
        'ID = Val(str)
        'str = "&H"
        'str = str + txtFrameID.Text
        'ID = Val(str)
        ''str = data()
        'strdata = " "
        'i = 0
        'For i = 0 To 7

        '    strdata = VB.Left(str, 2)
        '    If Len(strdata) = 0 Then
        '        Exit For
        '    End If
        '    'If Len(str) - 3 >= 0 Then
        '    str = VB.Right(str, Len(str) - 3)
        '    'Else
        '    '    str = " "
        '    'End If
        '    data(i) = Val("&H" + strdata)
        '    'data(i) = strdata
        'Next

        frameinfo(0).DataLen = datalen
        frameinfo(0).ExternFlag = frametype
        frameinfo(0).RemoteFlag = frameformat
        frameinfo(0).SendType = SendType
        frameinfo(0).ID = IDnum

        frameinfo(0).data0 = sendata1.data0
        frameinfo(0).data1 = sendata1.data1
        frameinfo(0).data2 = sendata1.data2
        frameinfo(0).data3 = sendata1.data3
        frameinfo(0).data4 = sendata1.data4
        frameinfo(0).data5 = sendata1.data5
        frameinfo(0).data6 = sendata1.data6
        frameinfo(0).data7 = sendata1.data7


        If VCI_Transmit(m_devtype, m_devind, m_cannum, frameinfo(0), 1) <> 1 Then
            'MsgBox("发送数据失败")
            Return 0
        Else
            'lstInfo.Items.Add("发送数据成功")

            'Print(ID)
            Return 1
        End If
        'Return 0
    End Function
End Class


