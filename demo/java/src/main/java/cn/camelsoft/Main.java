package cn.camelsoft;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;

enum Qiankun_error_code {
    Qiankun_errorcode_success           (0x00000001),   ///<  正确的值
    Qiankun_errorcode_normal            (0x00000002),   ///<  错误的值
    Qiankun_errorcode_differ            (0x00000003),   ///<  数据库文件数效验未通过 (The number of database files fails to be verified)
    Qiankun_errorcode_no_rights         (0x00000004),   ///<  数据库密码效验未通过 (The database password verification failed)
    Qiankun_errorcode_db_not_exist      (0x00000005),   ///<  数据库文件不存在 (The database file does not exist)
    Qiankun_errorcode_exist             (0x00000006),   ///<  数据已存在 (Data already exists)
    Qiankun_errorcode_not_exist         (0x00000007),   ///<  数据不存在 (Data does not exist)
    Qiankun_errorcode_out_of_range      (0x00000008),   ///<  超出范围 (out of range)
    Qiankun_errorcode_type              (0x00000009),   ///<  类型不符 (wrong type)
    Qiankun_errorcode_param             (0x0000000A),   ///<  参数错误 (parameter error)
    Qiankun_errorcode_compress          (0x0000000B),   ///<  压缩错误 (compression error)
    Qiankun_errorcode_get_array         (0x0000000C),   ///<  数组错误 (arrary error)
    Qiankun_errorcode_out_of_memory     (0x0000000D),   ///<  内存溢出 (memory overflow)
    Qiankun_errorcode_handle            (0x0000000E),   ///<  句柄错误 (error handle)
    Qiankun_errorcode_io                (0x0000000F);   ///<  IO错误 (io error)

    private int value;

    Qiankun_error_code(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}

public class Main {

    public interface tianzuo_QiankunLib extends Library {
        tianzuo_QiankunLib instance = (tianzuo_QiankunLib) Native.load("./tianzuo.Qiankun.dll", tianzuo_QiankunLib.class);
        Pointer tianzuo_QiankunInterface_initialize();
        void tianzuo_QiankunInterface_terminate(Pointer qiankun);
        int tianzuo_QiankunInt_initialize(Pointer qiankun);

        int tianzuo_QiankunInt_db_create_database(Pointer qiankun, String db_file_name, String db_password, String db_name, Boolean over_write);
        int tianzuo_QiankunInt_db_open_database(Pointer qiankun, String db_file_name, String db_password);
        int tianzuo_QiankunInt_db_close_database(Pointer qiankun, String db_file_name, String db_password);
        int tianzuo_QiankunInt_data_int_combine(Pointer qiankun, String db_file_name, String db_password, String data_name, String remark, int data);
        int tianzuo_QiankunInt_data_int_extract(Pointer qiankun, String db_file_name, String db_password, String data_name, int[] data);
    }

    public static void main(String[] args) {
        System.setProperty("jna.encoding","UTF-8");

        // 初始化接口 initialize the interface
        System.out.printf("initialize the interface\n");

        // 创建实例 create an instance
        Pointer qiankun = tianzuo_QiankunLib.instance.tianzuo_QiankunInterface_initialize();
        int error_code = tianzuo_QiankunLib.instance.tianzuo_QiankunInt_initialize(qiankun);
        if (error_code != Qiankun_error_code.Qiankun_errorcode_success.getValue()) {
            System.out.printf("tianzuo_QiankunInt_initialize error: %d\n", error_code);
            return;
        }

        // 创建数据库 create database
        String db_file_name = "qiankunDataBase.Ztz";
        String db_password = "password";
        error_code = tianzuo_QiankunLib.instance.tianzuo_QiankunInt_db_create_database(qiankun, db_file_name, db_password, "qiankunDataBase", true);
        if (error_code != Qiankun_error_code.Qiankun_errorcode_success.getValue()) {
            System.out.printf("tianzuo_QiankunInt_db_create_database error: %d\n", error_code);
            return;
        }

        // 打开数据库 open database
        error_code = tianzuo_QiankunLib.instance.tianzuo_QiankunInt_db_open_database(qiankun, db_file_name, db_password);
        if (error_code != Qiankun_error_code.Qiankun_errorcode_success.getValue()) {
            System.out.printf("tianzuo_QiankunInt_db_open_database error: %d\n", error_code);
            return;
        }

        // 向数据库写入一个整型数据 writes an integer to the database
        int intInt = 12345678;
        error_code = tianzuo_QiankunLib.instance.tianzuo_QiankunInt_data_int_combine(qiankun, db_file_name, db_password, "integer", "", intInt);
        if (error_code != Qiankun_error_code.Qiankun_errorcode_success.getValue()) {
            System.out.printf("tianzuo_QiankunInt_data_int_combine error: %d\n", error_code);
            return;
        }

        // 读取刚写入的数据 read the data just written
        int[] return_data = {0};
        error_code = tianzuo_QiankunLib.instance.tianzuo_QiankunInt_data_int_extract(qiankun, db_file_name, db_password, "integer", return_data);
        if (error_code != Qiankun_error_code.Qiankun_errorcode_success.getValue()) {
            System.out.printf("tianzuo_QiankunInt_data_int_extract error: %d\n", error_code);
            return;
        }

        System.out.printf("get int: %d\n", return_data[0]);

        // 关闭数据库 close database
        error_code = tianzuo_QiankunLib.instance.tianzuo_QiankunInt_db_close_database(qiankun, db_file_name, db_password);
        if (error_code != Qiankun_error_code.Qiankun_errorcode_success.getValue()) {
            System.out.printf("tianzuo_QiankunInt_db_close_database error: %d\n", error_code);
            return;
        }

        System.out.printf("test done -------------------\n");

        tianzuo_QiankunLib.instance.tianzuo_QiankunInterface_terminate(qiankun);
    }
}