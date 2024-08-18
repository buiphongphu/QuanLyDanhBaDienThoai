# Dự Án: Quản Lý Danh Bạ Điện Thoại

## Ngôn ngữ lập trình:
### 'C++'

## Mô tả

Bạn sẽ tạo một chương trình quản lý danh bạ điện thoại đơn giản bằng C++. Chương trình sẽ cho phép người dùng thực hiện các chức năng sau:

- Thêm liên lạc mới vào danh bạ.
- Xóa liên lạc từ danh bạ.
- Tìm kiếm liên lạc theo tên.
- Hiển thị toàn bộ danh bạ.
- Lưu và tải dữ liệu từ file.

## Cấu Trúc Chương Trình

Chương trình có thể được chia thành các phần chính sau:

### 1. Lớp `Contact`

Lớp `Contact` chứa các thuộc tính cơ bản và các phương thức liên quan đến thông tin của liên lạc.

#### Các thuộc tính:

- `std::string name` - Tên liên lạc.
- `std::string phoneNumber` - Số điện thoại.

#### Các phương thức:

- `Contact(const std::string& name, const std::string& phoneNumber, const std::string& email)` - Hàm khởi tạo.
- `std::string getName() const` - Lấy tên liên lạc.
- `void setName(const std::string& name)` - Đặt tên liên lạc.
- `std::string getPhoneNumber() const` - Lấy số điện thoại.
- `void setPhoneNumber(const std::string& phoneNumber)` - Đặt số điện thoại.


### 2. Lớp `Phonebook`

Lớp `Phonebook` sử dụng một cấu trúc dữ liệu phù hợp để lưu trữ các đối tượng `Contact` và cung cấp các phương thức để thao tác với danh bạ.

#### Các thuộc tính:

- `std::vector<Contact> contacts` - Danh sách các liên lạc.

#### Các phương thức:

- `void addContact(const Contact& contact)` - Thêm một liên lạc mới vào danh bạ.
- `void removeContact(const std::string& name)` - Xóa liên lạc theo tên.
- `Contact* searchContact(const std::string& name)` - Tìm kiếm liên lạc theo tên.
- `void displayContacts() const` - Hiển thị toàn bộ danh bạ.
- `void saveToFile(const std::string& filename) const` - Lưu danh bạ vào file.
- `void loadFromFile(const std::string& filename)` - Tải danh bạ từ file.

### 3. Hàm `main`

Hàm `main` cung cấp giao diện dòng lệnh để tương tác với người dùng và gọi các phương thức từ lớp `Phonebook`.

#### Các chức năng chính:

- Hiển thị menu cho người dùng với các tùy chọn như thêm, xóa, tìm kiếm, hiển thị danh bạ, lưu và tải dữ liệu.
- Nhận đầu vào từ người dùng và gọi các phương thức tương ứng từ lớp `Phonebook`.
- Xử lý các lỗi và thông báo cho người dùng nếu cần.
