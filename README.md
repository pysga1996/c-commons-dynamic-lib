# c-common-functions-dynamic-lib
C common function dynamic library

Hướng dẫn liên kết thư viện.

1. Biên dịch source code thư viện được 2 file: file .dll là
 file nhị phân, file .dll.a (hoặc .lib) là file chứa thông tin 
 linking.
2. Copy file 2 file trên và file header trong source code của thư 
viện vào source code của project.
3. Thêm các cấu hình vào file CMakeLists.txt:
- include_directories(...) là thư mục chứa header (bỏ header của
thư viện vào đây).
- link_directories(...) là thư mục chứa file thông tin linkjng,
bỏ file .dll.a vào đây.
- target_link_libraries(program_binary library_binary) liệt kê
tên file executable của program và file binary của thư viện.
4. Copy file .dll vào thư mục windows trong ổ C, hoặc để cùng thư
mục với file execuatable của program hoặc cấu hình biến môi trường
PATH trỏ vào thư mục chứa file .dll.
5. Run program.


