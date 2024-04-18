

using System.Runtime.InteropServices;

public enum Qiankun_error_code
{
    Qiankun_errorcode_success       = 0x00000001,              ///<  正确的值
    Qiankun_errorcode_normal        = 0x00000002,              ///<  错误的值
    Qiankun_errorcode_differ        = 0x00000003,              ///<  数据库文件数效验未通过 (The number of database files fails to be verified)
    Qiankun_errorcode_no_rights     = 0x00000004,              ///<  数据库密码效验未通过 (The database password verification failed)
    Qiankun_errorcode_db_not_exist  = 0x00000005,              ///<  数据库文件不存在 (The database file does not exist)
    Qiankun_errorcode_exist         = 0x00000006,              ///<  数据已存在 (Data already exists)
    Qiankun_errorcode_not_exist     = 0x00000007,              ///<  数据不存在 (Data does not exist)
    Qiankun_errorcode_out_of_range  = 0x00000008,              ///<  超出范围 (out of range)
    Qiankun_errorcode_type          = 0x00000009,              ///<  类型不符 (wrong type)
    Qiankun_errorcode_param         = 0x0000000A,              ///<  参数错误 (parameter error)
    Qiankun_errorcode_compress      = 0x0000000B,              ///<  压缩错误 (compression error)
    Qiankun_errorcode_get_array     = 0x0000000C,              ///<  数组错误 (arrary error)
    Qiankun_errorcode_out_of_memory = 0x0000000D,              ///<  内存溢出 (memory overflow)
    Qiankun_errorcode_handle        = 0x0000000E,              ///<  句柄错误 (error handle)
    Qiankun_errorcode_io            = 0x0000000F,              ///<  IO错误 (io error)
}

class Program {
    [DllImport("tianzuo.Qiankun.dll")]
    public static extern IntPtr tianzuo_QiankunInterface_initialize();
    [DllImport("tianzuo.Qiankun.dll")]
    public static extern void tianzuo_QiankunInterface_terminate(IntPtr qiankun);
    [DllImport("tianzuo.Qiankun.dll")]
    public static extern int tianzuo_QiankunInt_initialize(IntPtr qiankun);
    [DllImport("tianzuo.Qiankun.dll")]
    public static extern int tianzuo_QiankunInt_db_create_database(IntPtr qiankun, string db_file_name, string db_password, string db_name, bool over_write);
    [DllImport("tianzuo.Qiankun.dll")]
    public static extern int tianzuo_QiankunInt_db_open_database(IntPtr qiankun, string db_file_name, string db_password);
    [DllImport("tianzuo.Qiankun.dll")]
    public static extern int tianzuo_QiankunInt_db_close_database(IntPtr qiankun, string db_file_name, string db_password);
    [DllImport("tianzuo.Qiankun.dll")]
    public static extern int tianzuo_QiankunInt_data_int_combine(IntPtr qiankun, string db_file_name, string db_password, string data_name, string remark, int data);
    [DllImport("tianzuo.Qiankun.dll")]
    public static extern int tianzuo_QiankunInt_data_int_extract(IntPtr qiankun, string db_file_name, string db_password, string data_name, ref int data);
    
    static void Main(string[] args) {
        // 初始化接口 initialize the interface
        Console.WriteLine("initialize the interface\n");

        // 创建实例 create an instance
        IntPtr qiankun = tianzuo_QiankunInterface_initialize();
        int error_code = tianzuo_QiankunInt_initialize(qiankun);
        if (error_code != ((int)Qiankun_error_code.Qiankun_errorcode_success))
        {
            Console.WriteLine("tianzuo_QiankunInt_initialize error:" + error_code);
            return;
        }

        // 创建数据库 create database
        string db_file_name = "qiankunDataBase.Ztz";
        string db_password = "password";
        error_code = tianzuo_QiankunInt_db_create_database(qiankun, db_file_name, db_password, "qiankunDataBase", true);
        if (error_code != ((int)Qiankun_error_code.Qiankun_errorcode_success))
        {
            Console.WriteLine("tianzuo_QiankunInt_db_create_database error:" + error_code);
            return;
        }

        // 打开数据库 open database
        error_code = tianzuo_QiankunInt_db_open_database(qiankun, db_file_name, db_password);
        if (error_code != ((int)Qiankun_error_code.Qiankun_errorcode_success)) {
            Console.WriteLine("tianzuo_QiankunInt_db_open_database error:" + error_code);
            return;
        }

        // 向数据库写入一个整型数据 writes an integer to the database
        int intInt = 12345678;
        error_code = tianzuo_QiankunInt_data_int_combine(qiankun, db_file_name, db_password, "integer", "", intInt);
        if (error_code != ((int)Qiankun_error_code.Qiankun_errorcode_success))
        {
            Console.WriteLine("tianzuo_QiankunInt_data_int_combine error:" + error_code);
            return;
        }

        // 读取刚写入的数据 read the data just written
        int return_data = 0;
        error_code = tianzuo_QiankunInt_data_int_extract(qiankun, db_file_name, db_password, "integer", ref return_data);
        if (error_code != ((int)Qiankun_error_code.Qiankun_errorcode_success))
        {
            Console.WriteLine("tianzuo_QiankunInt_data_int_extract error:" + error_code);
            return;
        }

        Console.WriteLine("get int: " + return_data);

        // 关闭数据库 close database
        error_code = tianzuo_QiankunInt_db_close_database(qiankun, db_file_name, db_password);
        if (error_code != ((int)Qiankun_error_code.Qiankun_errorcode_success))
        {
            Console.WriteLine("tianzuo_QiankunInt_db_close_database error:" + error_code);
            return;
        }

        Console.WriteLine("test done -------------------\n");

        tianzuo_QiankunInterface_terminate(qiankun);

    }

}