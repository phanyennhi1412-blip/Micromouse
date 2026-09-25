# BÁO CÁO 
## DigitalWrite
* Cú pháp: digitalWrite(pin,value)
* pin: Số chân digital muốn điều khiển
* value: HIGH hoặc LOW
* VD: Đối với stm32 blackpill:
    * digitalWrite(PC13,HIGH) // Đèn led tắt 
    * digitalWrite(PC13,LOW) // Đèn led bật 
## PinMode
* Cú pháp: pinMode(pin,mode)
* Dùng để thiết lập chế độ hoạt động cho pin (OUPUT hoặc INPUT)
* Mode:
    * INPUT: Đọc tín hiệu điện tử từ bên ngoài vào vi điều khiển (như cảm biến, nút nhấn, công tắc)
    * OUTPUT: Xuất điện áp từ vi điều khiển ra thiết bị bên ngoài (như bật/tắt đèn LED, kích rơ-le, điều khiển động cơ, phát tín hiệu)
    * INPUT_PULLUP: Không cần cắm điện trở bên ngoài nữa 
* VD: 
    * pinMode(PC13,OUPUT) 
    * pinMode(PC13,INPUT) 
## DigitalRead
* Cú pháp: digitalRead(pin) 
* Đọc tín hiệu điện từ một chân digital (được thiết đặt là INPUT)
* Trả về 2 giá trị HIGH hoặc LOW
* VD:  [led_button.cpp](./src/led_button.cpp) (Thêm nút bật tắt cho đèn Led)
## Cách đọc tín hiệu analog
### Tín hiệu analog
* Tín hiệu analog là tín hiệu điện áp biến thiên liên tục theo thời gian (0V -> 3.3V)
### Cách đọc 
* Sử dụng bộ chuyển đổi ADC được tích hợp sẵn trong STM32F411CEU6
* Sơ đồ chân: 
    * Chân VCC: Nối vào chân 3.3V trên STM32
    * Chân GND: Nối vào chân GND trên STM32
    * Chân Tín hiệu: Nối vào một chân ADC trên STM32
* Viết code để đọc tín hiệu:
## Giao tiếp I2C
* SDA (Serial Data) - đường truyền cho master và slave để gửi và nhận dữ liệu
    * MCU ↔ Động cơ: MCU ra lệnh cho bánh xe quay → Encoder gửi phản hồi báo bánh đã quay bao nhiêu vòng → MCU điều chỉnh để robot đi thẳng và rẽ đúng 90 độ
    * MCU ↔ Cảm biến: MCU hỏi "trước mặt có tường không?" → Cảm biến đo khoảng cách rồi gửi số liệu về → MCU biết đường mà tránh.
    * Robot ↔ Máy tính: Robot gửi bản đồ 16x16 và thông số xe lên máy tính → Bạn xem trên màn hình và gửi lệnh chỉnh tham số PID trực tiếp mà không cần cắm dây nạp lại code
* SCL (Serial Clock) - đường mang tín hiệu xung nhịp.
## Differential Drive (Hệ dẫn động vi sai)
### Khái niệm:
* Là kiểu di chuyển cơ bản của robot có 2 bánh xe chủ động độc lập ở hai bên (trái/phải). Robot rẽ bằng cách cho 2 bánh quay với tốc độ khác nhau.
### Di chuyển:
  * Bánh bên trái chuyển động nhanh hơn bánh bên phải => Xe rẽ phải
  * Bánh bên phải chuyển động nhanh hơn bánh bên trái => Xe rẽ trái
  * Bánh bên trải, phải chuyển động ngược chiều nhau => Xe quay tròn
  * Không thể đi ngang
* **Hiện tượng trượt bánh xe** khiến ước tính vị trí của robot (từ phép đo quãng đường bánh xe) bị lệch so với vị trí thực tế, do đó việc lái xe chính xác thường cần thêm các cảm biến (IMU, bộ mã hóa, thị giác) để hiệu chỉnh hiện tượng này.
### Động học nghịch đảo 
* Xác định vận tốc cần thiết để thiết lập cho mỗi bánh xe (hoặc động cơ trên một robot thực tế) => quay, tiến hoặc lùi.
* Phương trình cho Micromouse theo [Differential Drive 1](https://existentialrobotics.org/RobotProvingGrounds/algorithms/control/content/diffy_drive/):
  * **L: Khoảng cách giữa hai bánh xe** 
    * *L=2.r(track)*
  * **Bánh phải:** v=v(forward) + w*L/2
  * **Bánh trái:** v=v(forward) - w*L/2
### Động học thuận 
* Cho biết góc quay của các mô-tơ => Tính ra vị trí của xe.
* Phương trình cho Micromouse theo [Differential Drive 1](https://existentialrobotics.org/RobotProvingGrounds/algorithms/control/content/diffy_drive/):
  * **r(track): Khoảng cách giữa tâm của toàn bộ xe và điểm giữa của một cặp bánh xe (trái hoặc phải).**
  * **Vận tốc tiến:** v=(v(left)+v(right))/2 
  * **Vận tốc góc:** w=(v(left)+v(right))/2*r(track) 
### Tài liệu tham khảo:
  * [Differential Drive 1](https://existentialrobotics.org/RobotProvingGrounds/algorithms/control/content/diffy_drive/)
  * [Differential Drive 2](https://www.scribd.com/document/405425396/differentialDrive-pdf)
## Wheel Encoder (Cảm biến đếm xung bánh xe)
### Khái niệm:
* Đo chính xác số vòng quay của từng bánh xe để tính ra quãng đường và vận tốc tuyến tính của robot.
* 
### Tài liệu tham khảo:
  * [Wheel Encoder 1](https://docs.idew.org/code-robotics/references/physical-inputs/wheel-encoders)
  * [Wheel Encoder 2](https://www.scribd.com/document/810126966/ENCODER-T%E1%BB%AA-A-%C4%90%E1%BA%BEN-Z)
## IMU (Inertial Measurement Unit - Cảm biến quán tính)
* **Khái niệm:** Gồm Gyroscope (đo tốc độ góc quay/hướng) và Accelerometer (đo gia tốc tuyến tính). Cảm biến này đo trực tiếp chuyển động vật lý của thân robot mà không quan tâm bánh xe có bám đường hay không.
* **Tài liệu tham khảo:**
  * [IMU 1](http://arduino.vn/bai-viet/960-doi-dieu-ve-imu-inertial-measurement-unit)
  * [IMU 2](https://www.advancednavigation.com/tech-articles/inertial-measurement-unit-imu-an-introduction/)
  * [IMU 3](https://www.jouav.com/blog/inertial-measurement-unit.html)
## Sensor Fusion (Hợp nhất cảm biến)
* **Khái niệm:** Phương pháp toán học dùng để lấy ưu điểm của cảm biến này bù đắp cho nhược điểm của cảm biến kia, tạo ra kết quả ước lượng chính xác hơn từng cảm biến riêng lẻ.
* **Tài liệu tham khảo:**
  * [Sensor Fusion 1](https://aiots.vn/bai-10-sensor-fusion-nghe-thuat-hop-nhat-du-lieu-khi-1-1-2/) 
  * [Sensor Fusion 2](https://www.udacity.com/blog/sensor-fusion-algorithms-explained/)
  
