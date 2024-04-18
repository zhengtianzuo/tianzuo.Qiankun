
Imports System.Runtime.InteropServices

Enum Qiankun_error_code
    Qiankun_errorcode_success = 1                     '  正确的值
    Qiankun_errorcode_normal = 2                      '  错误的值
    Qiankun_errorcode_differ = 3                      '  数据库文件数效验未通过 (The number Of database files fails To be verified)
    Qiankun_errorcode_no_rights = 4                   '  数据库密码效验未通过 (The database password verification failed)
    Qiankun_errorcode_db_not_exist = 5                '  数据库文件不存在 (The database file does Not exist)
    Qiankun_errorcode_exist = 6                       '  数据已存在 (Data already exists)
    Qiankun_errorcode_not_exist = 7                   '  数据不存在 (Data does Not exist)
    Qiankun_errorcode_out_of_range = 8                '  超出范围 (out Of range)
    Qiankun_errorcode_type = 9                        '  类型不符 (wrong type)
    Qiankun_errorcode_param = 10                      '  参数错误 (parameter Error)
    Qiankun_errorcode_compress = 11                   '  压缩错误 (compression Error)
    Qiankun_errorcode_get_array = 12                  '  数组错误 (arrary Error)
    Qiankun_errorcode_out_of_memory = 13              '  内存溢出 (memory overflow)
    Qiankun_errorcode_handle = 14                     '  句柄错误 (Error handle)
    Qiankun_errorcode_io = 15                         '  IO错误 (io Error)
End Enum

Module Program
    <DllImport("tianzuo.Qiankun.dll")>
    Public Function tianzuo_QiankunInterface_initialize() As IntPtr
    End Function
    <DllImport("tianzuo.Qiankun.dll")>
    Public Function tianzuo_QiankunInterface_terminate(ByRef QiankunInt_pointer As IntPtr)
    End Function
    <DllImport("tianzuo.Qiankun.dll")>
    Public Function tianzuo_QiankunInt_initialize(QiankunInt_pointer As IntPtr) As Integer
    End Function
    <DllImport("tianzuo.Qiankun.dll")>
    Public Function tianzuo_QiankunInt_db_create_database(QiankunInt_pointer As IntPtr, db_file_name As String, db_password As String, db_name As String, over_write As Boolean) As Integer
    End Function
    <DllImport("tianzuo.Qiankun.dll")>
    Public Function tianzuo_QiankunInt_db_open_database(QiankunInt_pointer As IntPtr, db_file_name As String, db_password As String) As Integer
    End Function
    <DllImport("tianzuo.Qiankun.dll")>
    Public Function tianzuo_QiankunInt_db_close_database(QiankunInt_pointer As IntPtr, db_file_name As String, db_password As String) As Integer
    End Function
    <DllImport("tianzuo.Qiankun.dll")>
    Public Function tianzuo_QiankunInt_data_int_combine(QiankunInt_pointer As IntPtr, db_file_name As String, db_password As String, data_name As String, remark As String, data As Integer) As Integer
    End Function
    <DllImport("tianzuo.Qiankun.dll")>
    Public Function tianzuo_QiankunInt_data_int_extract(QiankunInt_pointer As IntPtr, db_file_name As String, db_password As String, data_name As String, ByRef data As Integer) As Integer
    End Function

    Sub Main(args As String())
        ' 初始化接口 initialize the interface
        Console.WriteLine("initialize the interface")

        ' 创建实例 create an instance
        Dim qiankun As IntPtr = tianzuo_QiankunInterface_initialize()
        Dim error_code As Integer = tianzuo_QiankunInt_initialize(qiankun)
        If (error_code <> Qiankun_error_code.Qiankun_errorcode_success) Then
            Console.WriteLine("tianzuo_QiankunInt_initialize error:" + error_code.ToString)
            Return
        End If

        ' 创建数据库 create database
        Dim db_file_name As String = "qiankunDataBase.Ztz"
        Dim db_password As String = "password"
        error_code = tianzuo_QiankunInt_db_create_database(qiankun, db_file_name, db_password, "qiankunDataBase", True)
        If (error_code <> Qiankun_error_code.Qiankun_errorcode_success) Then
            Console.WriteLine("tianzuo_QiankunInt_db_create_database error:" + error_code.ToString)
            Return
        End If

        ' 打开数据库 open database
        error_code = tianzuo_QiankunInt_db_open_database(qiankun, db_file_name, db_password)
        If (error_code <> Qiankun_error_code.Qiankun_errorcode_success) Then
            Console.WriteLine("tianzuo_QiankunInt_db_open_database error:" + error_code.ToString)
            Return
        End If

        ' 向数据库写入一个整型数据 writes an integer to the database
        Dim intInt As Integer = 12345678
        error_code = tianzuo_QiankunInt_data_int_combine(qiankun, db_file_name, db_password, "integer", "", intInt)
        If (error_code <> Qiankun_error_code.Qiankun_errorcode_success) Then
            Console.WriteLine("tianzuo_QiankunInt_data_int_combine error:" + error_code.ToString)
            Return
        End If

        ' 读取刚写入的数据 read the data just written
        Dim return_data As Integer = 0
        error_code = tianzuo_QiankunInt_data_int_extract(qiankun, db_file_name, db_password, "integer", return_data)
        If (error_code <> Qiankun_error_code.Qiankun_errorcode_success) Then
            Console.WriteLine("tianzuo_QiankunInt_data_int_extract error:" + error_code.ToString)
            Return
        End If

        Console.WriteLine("get int: " + return_data.ToString)

        ' 关闭数据库 close database
        error_code = tianzuo_QiankunInt_db_close_database(qiankun, db_file_name, db_password)
        If (error_code <> Qiankun_error_code.Qiankun_errorcode_success) Then
            Console.WriteLine("tianzuo_QiankunInt_db_close_database error:" + error_code.ToString)
            Return
        End If

        Console.WriteLine("test done -------------------")

    End Sub
End Module
