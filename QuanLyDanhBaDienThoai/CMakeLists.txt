cmake_minimum_required(VERSION 3.10)
project(PhonebookManager)

set(CMAKE_CXX_STANDARD 17)

# Thêm thư mục chứa mã nguồn
add_executable(PhonebookManager
    src/Contact.cpp
    src/Phonebook.cpp
    src/main.cpp
)

# Thêm đường dẫn thư viện nếu cần thiết
# target_link_libraries(PhonebookManager some_library)
