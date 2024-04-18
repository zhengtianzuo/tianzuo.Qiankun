<?php

// 检查是否加载了 FFI 扩展
if (extension_loaded('ffi')) {
    echo("已启用 FFI 扩展\n");
} else {
    die("未启动 FFI 扩展\n");
}

enum Qiankun_error_code
{
const Qiankun_errorcode_success       = 0x00000001;            ///<  正确的值
const Qiankun_errorcode_normal        = 0x00000002;            ///<  错误的值
const Qiankun_errorcode_differ        = 0x00000003;            ///<  数据库文件数效验未通过 (The number of database files fails to be verified)
const Qiankun_errorcode_no_rights     = 0x00000004;            ///<  数据库密码效验未通过 (The database password verification failed)
const Qiankun_errorcode_db_not_exist  = 0x00000005;            ///<  数据库文件不存在 (The database file does not exist)
const Qiankun_errorcode_exist         = 0x00000006;            ///<  数据已存在 (Data already exists)
const Qiankun_errorcode_not_exist     = 0x00000007;            ///<  数据不存在 (Data does not exist)
const Qiankun_errorcode_out_of_range  = 0x00000008;            ///<  超出范围 (out of range)
const Qiankun_errorcode_type          = 0x00000009;            ///<  类型不符 (wrong type)
const Qiankun_errorcode_param         = 0x0000000A;            ///<  参数错误 (parameter error)
const Qiankun_errorcode_compress      = 0x0000000B;            ///<  压缩错误 (compression error)
const Qiankun_errorcode_get_array     = 0x0000000C;            ///<  数组错误 (arrary error)
const Qiankun_errorcode_out_of_memory = 0x0000000D;            ///<  内存溢出 (memory overflow)
const Qiankun_errorcode_handle        = 0x0000000E;            ///<  句柄错误 (error handle)
const Qiankun_errorcode_io            = 0x0000000F;            ///<  IO错误 (io error)
}

$ffi = FFI::cdef("
    void* tianzuo_QiankunInterface_initialize();
    void tianzuo_QiankunInterface_terminate(void* *QiankunInt_pointer);
    int tianzuo_QiankunInt_initialize(void* QiankunInt_pointer);
    int tianzuo_QiankunInt_db_create_database(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* db_name, bool const over_write);
    int tianzuo_QiankunInt_db_open_database(void* QiankunInt_pointer, const char* db_file_name, const char* db_password);
    int tianzuo_QiankunInt_db_close_database(void* QiankunInt_pointer, const char* db_file_name, const char* db_password);
    int tianzuo_QiankunInt_data_int_combine(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, const char* remark, int data);
    int tianzuo_QiankunInt_data_int_extract(void* QiankunInt_pointer, const char* db_file_name, const char* db_password, const char* data_name, int* data);
", "tianzuo.Qiankun.dll");

# 初始化接口 initialize the interface
echo "initialize the interface" . "\n";

# 创建实例 create an instance
$qiankun = $ffi->tianzuo_QiankunInterface_initialize();

$error_code = $ffi->tianzuo_QiankunInt_initialize($qiankun);
if ($error_code != Qiankun_error_code::Qiankun_errorcode_success) {
    echo "initialize error: " . $error_code . "\n";
    return;
}

# 创建数据库 create database
$db_file_name = "qiankunDataBase.Ztz";
$db_password = "password";
$error_code = $ffi->tianzuo_QiankunInt_db_create_database($qiankun, $db_file_name, $db_password, "qiankunDataBase", true);
if ($error_code != Qiankun_error_code::Qiankun_errorcode_success) {
    echo "tianzuo_QiankunInt_db_create_database error: " . $error_code . "\n";
    return;
}

# 打开数据库 open database
$error_code = $ffi->tianzuo_QiankunInt_db_open_database($qiankun, $db_file_name, $db_password);
if ($error_code != Qiankun_error_code::Qiankun_errorcode_success) {
    echo "tianzuo_QiankunInt_db_open_database error: " . $error_code . "\n";
    return;
}

# 向数据库写入一个整型数据 writes an integer to the database
$intInt = 12345678;
$error_code = $ffi->tianzuo_QiankunInt_data_int_combine($qiankun, $db_file_name, $db_password, "integer", "", $intInt);
if ($error_code != Qiankun_error_code::Qiankun_errorcode_success) {
    echo "tianzuo_QiankunInt_data_int_combine error: " . $error_code . "\n";
    return;
}

# 读取刚写入的数据 read the data just written
$return_data = FFI::new("int");
$error_code = $ffi->tianzuo_QiankunInt_data_int_extract($qiankun, $db_file_name, $db_password, "integer", FFI::addr($return_data));
if ($error_code != Qiankun_error_code::Qiankun_errorcode_success) {
    echo "tianzuo_QiankunInt_data_int_extract error: " . $error_code . "\n";
    return;
}

echo "get integer data: " . $return_data->cdata . "\n";

# 关闭数据库 close database
$error_code = $ffi->tianzuo_QiankunInt_db_close_database($qiankun, $db_file_name, $db_password);
if ($error_code != Qiankun_error_code::Qiankun_errorcode_success) {
    echo "tianzuo_QiankunInt_db_close_database error: " . $error_code . "\n";
    return;
}

echo "test done -------------------" . "\n";

?>