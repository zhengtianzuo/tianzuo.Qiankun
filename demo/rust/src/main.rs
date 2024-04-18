
use std::os::raw::c_char;
use std::ffi::{c_int};
use std::ffi::CString;
use std::ptr::null;

#[link(name = "tianzuo.Qiankun")]
extern {
    fn tianzuo_QiankunInterface_initialize() -> *mut std::ffi::c_void;
    fn tianzuo_QiankunInterface_terminate(obj: *mut std::ffi::c_void);
    fn tianzuo_QiankunInt_initialize(obj: *mut std::ffi::c_void) -> c_int;
    fn tianzuo_QiankunInt_db_create_database(obj: *mut std::ffi::c_void, db_file_name: *const c_char, db_password: *const c_char, db_name: *const c_char, over_write: c_int) -> c_int;
    fn tianzuo_QiankunInt_db_open_database(obj: *mut std::ffi::c_void, db_file_name: *const c_char, db_password: *const c_char) -> c_int;
    fn tianzuo_QiankunInt_db_close_database(obj: *mut std::ffi::c_void, db_file_name: *const c_char, db_password: *const c_char) -> c_int;
    fn tianzuo_QiankunInt_data_int_combine(obj: *mut std::ffi::c_void, db_file_name: *const c_char, db_password: *const c_char, data_name: *const c_char, remark: *const c_char, data: c_int) -> c_int;
    fn tianzuo_QiankunInt_data_int_extract(obj: *mut std::ffi::c_void, db_file_name: *const c_char, db_password: *const c_char, data_name: *const c_char, data: *const c_int) -> c_int;
}

fn main() {
    unsafe {
        // 初始化接口 initialize the interface
        println!("initialize the interface");

        // 创建实例 create an instance
        let qiankun = tianzuo_QiankunInterface_initialize();
        let error_code = tianzuo_QiankunInt_initialize(qiankun);
        if 1 != error_code {
            println!("initialize error: {:?}", error_code);
        }

        // 创建数据库 create database
        let db_file_name = CString::new(String::from("qiankunDataBase.Ztz")).expect("Failed to create CString");
        let db_password = CString::new(String::from("password")).expect("Failed to create CString");
        let db_name = CString::new(String::from("qiankunDataBase")).expect("Failed to create CString");
        let error_code = tianzuo_QiankunInt_db_create_database(qiankun, db_file_name.as_ptr(), db_password.as_ptr(), db_name.as_ptr(), 1);
        if 1 != error_code {
            println!("db_create_database error: {:?}", error_code);
        }

        // 打开数据库 open database
        let error_code = tianzuo_QiankunInt_db_open_database(qiankun, db_file_name.as_ptr(), db_password.as_ptr());
        if 1 != error_code {
            println!("db_open_database error: {:?}", error_code);
        }

        // 向数据库写入一个整型数据 writes an integer to the database
        let int = 12345678;
        let data_name = CString::new(String::from("integer")).expect("Failed to create CString");
        let error_code = tianzuo_QiankunInt_data_int_combine(qiankun, db_file_name.as_ptr(), db_password.as_ptr(), data_name.as_ptr(), null(), int);
        if 1 != error_code {
            println!("data_combine error: {:?}", error_code);
        }

        // 读取刚写入的数据 read the data just written
        let mut return_data: c_int = 0;
        let error_code = tianzuo_QiankunInt_data_int_extract(qiankun, db_file_name.as_ptr(), db_password.as_ptr(), data_name.as_ptr(), &mut return_data);
        if 1 != error_code {
            println!("data_extract error: {:?}", error_code);
        }

        println!("get integer data: {:?}", return_data);

        // 关闭数据库 close database
        let error_code = tianzuo_QiankunInt_db_close_database(qiankun, db_file_name.as_ptr(), db_password.as_ptr());
        if 1 != error_code {
            println!("db_close_database error: {:?}", error_code);
        }

        println!("test done -------------------")
    }
}
