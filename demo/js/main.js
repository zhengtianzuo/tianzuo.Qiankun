
Qiankun_errorcode_success           = 0x00000001;   ///<  正确的值
Qiankun_errorcode_normal            = 0x00000002;   ///<  错误的值
Qiankun_errorcode_differ            = 0x00000003;   ///<  数据库文件数效验未通过 (The number of database files fails to be verified)
Qiankun_errorcode_no_rights         = 0x00000004;   ///<  数据库密码效验未通过 (The database password verification failed)
Qiankun_errorcode_db_not_exist      = 0x00000005;   ///<  数据库文件不存在 (The database file does not exist)
Qiankun_errorcode_exist             = 0x00000006;   ///<  数据已存在 (Data already exists)
Qiankun_errorcode_not_exist         = 0x00000007;   ///<  数据不存在 (Data does not exist)
Qiankun_errorcode_out_of_range      = 0x00000008;   ///<  超出范围 (out of range)
Qiankun_errorcode_type              = 0x00000009;   ///<  类型不符 (wrong type)
Qiankun_errorcode_param             = 0x0000000A;   ///<  参数错误 (parameter error)
Qiankun_errorcode_compress          = 0x0000000B;   ///<  压缩错误 (compression error)
Qiankun_errorcode_get_array         = 0x0000000C;   ///<  数组错误 (arrary error)
Qiankun_errorcode_out_of_memory     = 0x0000000D;   ///<  内存溢出 (memory overflow)
Qiankun_errorcode_handle            = 0x0000000E;   ///<  句柄错误 (error handle)
Qiankun_errorcode_io                = 0x0000000F;   ///<  IO错误 (io error)

let ffi = require('ffi-napi')
const ref = require('ref-napi');

let tianzuo_QiankunLib = ffi.Library("tianzuo.Qiankun.dll", {
    'tianzuo_QiankunInterface_initialize': ['pointer', []],
    'tianzuo_QiankunInterface_terminate':['void',['pointer']],
    'tianzuo_QiankunInt_initialize':['int',['pointer']],
    'tianzuo_QiankunInt_db_create_database':['int',['pointer','string','string','string', 'bool']],
    'tianzuo_QiankunInt_db_open_database':['int',['pointer', 'string', 'string']],
    'tianzuo_QiankunInt_db_close_database':['int',['pointer', 'string', 'string']],
    'tianzuo_QiankunInt_data_int_combine':['int',['pointer','string','string','string', 'string', 'int']],
    'tianzuo_QiankunInt_data_int_extract':['int',['pointer','string','string','string', 'pointer']],
})


// 初始化接口 initialize the interface
console.log("initialize the interface\n");

// 创建实例 create an instance
let qiankun = tianzuo_QiankunLib.tianzuo_QiankunInterface_initialize();
let error_code = tianzuo_QiankunLib.tianzuo_QiankunInt_initialize(qiankun);
if (error_code !== Qiankun_errorcode_success) {
    console.log("tianzuo_QiankunInt_initialize error: %d\n", error_code);
    return;
}

// 创建数据库 create database
let db_file_name = "qiankunDataBase.Ztz";
let db_password = "password";
error_code = tianzuo_QiankunLib.tianzuo_QiankunInt_db_create_database(qiankun, db_file_name, db_password, "qiankunDataBase", true);
if (error_code !== Qiankun_errorcode_success) {
    console.log("tianzuo_QiankunInt_db_create_database error: %d\n", error_code);
    return;
}

// 打开数据库 open database
error_code = tianzuo_QiankunLib.tianzuo_QiankunInt_db_open_database(qiankun, db_file_name, db_password);
if (error_code !== Qiankun_errorcode_success) {
    console.log("tianzuo_QiankunInt_db_open_database error: %d\n", error_code);
    return;
}

// 向数据库写入一个整型数据 writes an integer to the database
let intInt = 12345678;
error_code = tianzuo_QiankunLib.tianzuo_QiankunInt_data_int_combine(qiankun, db_file_name, db_password, "integer", "", intInt);
if (error_code !== Qiankun_errorcode_success) {
    console.log("tianzuo_QiankunInt_data_int_combine error: %d\n", error_code);
    return;
}

// 读取刚写入的数据 read the data just written
return_buf = Buffer.alloc(1 * ref.sizeof.int);
error_code = tianzuo_QiankunLib.tianzuo_QiankunInt_data_int_extract(qiankun, db_file_name, db_password, "integer", return_buf);
if (error_code !== Qiankun_errorcode_success) {
    console.log("tianzuo_QiankunInt_data_int_extract error: %d\n", error_code);
    return;
}

return_data = ref.get(return_buf, 0, ref.types.int);
console.log("get int: %d\n", return_data);

// 关闭数据库 close database
error_code = tianzuo_QiankunLib.tianzuo_QiankunInt_db_close_database(qiankun, db_file_name, db_password);
if (error_code !== Qiankun_errorcode_success) {
    console.log("tianzuo_QiankunInt_db_close_database error: %d\n", error_code);
   return;
}

console.log("test done -------------------\n");

tianzuo_QiankunLib.tianzuo_QiankunInterface_terminate(qiankun);
