# DigitalWrite
* Cú pháp: digitalWrite(pin,value)
* pin: Số chân digital muốn điều khiển
* value: HIGH hoặc LOW
* VD: Đối với stm32 blackpill:
    * digitalWrite(PC13,HIGH) // Đèn led tắt 
    * digitalWrite(PC13,LOW) // Đèn led bật 
# PinMode
* Cú pháp: pinMode(pin,mode)
* Dùng để thiết lập chế độ hoạt động cho pin (OUPUT hoặc INPUT)
* Mode:
    * INPUT: Đọc tín hiệu điện tử từ bên ngoài vào vi điều khiển (như cảm biến, nút nhấn, công tắc)
    * OUTPUT: Xuất điện áp từ vi điều khiển ra thiết bị bên ngoài (như bật/tắt đèn LED, kích rơ-le, điều khiển động cơ, phát tín hiệu)
    * INPUT_PULLUP: Không cần cắm điện trở bên ngoài nữa 
* VD: 
    * pinMode(PC13,OUPUT) 
    * pinMode(PC13,INPUT) 
# DigitalRead
* Cú pháp: digitalRead(pin) 
* Đọc tín hiệu điện từ một chân digital (được thiết đặt là INPUT)
* Trả về 2 giá trị HIGH hoặc LOW
* VD:  [led_button.cpp](./src/led_button.cpp) (Thêm nút bật tắt cho đèn Led)
# Cách đọc tín hiệu analog
## Tín hiệu analog
* Tín hiệu analog là tín hiệu điện áp biến thiên liên tục theo thời gian (0V -> 3.3V)
## Cách đọc 
* Sử dụng bộ chuyển đổi ADC được tích hợp sẵn trong STM32F411CEU6
* Sơ đồ chân: 
    * Chân VCC: Nối vào chân 3.3V trên STM32
    * Chân GND: Nối vào chân GND trên STM32
    * Chân Tín hiệu: Nối vào một chân ADC trên STM32
* Viết code để đọc tín hiệu:
# Giao tiếp I2C
* SDA (Serial Data) - đường truyền cho master và slave để gửi và nhận dữ liệu
    * MCU ↔ Động cơ: MCU ra lệnh cho bánh xe quay → Encoder gửi phản hồi báo bánh đã quay bao nhiêu vòng → MCU điều chỉnh để robot đi thẳng và rẽ đúng 90 độ
    * MCU ↔ Cảm biến: MCU hỏi "trước mặt có tường không?" → Cảm biến đo khoảng cách rồi gửi số liệu về → MCU biết đường mà tránh.
    * Robot ↔ Máy tính: Robot gửi bản đồ 16x16 và thông số xe lên máy tính → Bạn xem trên màn hình và gửi lệnh chỉnh tham số PID trực tiếp mà không cần cắm dây nạp lại code
* SCL (Serial Clock) - đường mang tín hiệu xung nhịp.







