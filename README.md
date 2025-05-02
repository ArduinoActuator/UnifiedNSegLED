# UnifiedNSegLED

Arduinoに接続するアクチュエータのAPIを統一するためのHardware Abstraction Layer(HAL)を集めています．ただし，HALは
IoTの端末として用いることを前提にしているため，
ネットワーク経由で制御命令を送るだけの使い方を想定しており，
対話的に使う必要がある機能はサポートしていません．


## サポートしているLED

- [超大型赤色16セグメントLED表示器 アノードコモン アノード共通接続 A-2308SR][A2308SR]
- [赤色2桁LED表示器 14セグメント+Dp OSL20541-IR][OSL20541IR]
- [3桁7セグメントLED表示器 赤色 アノードコモン OSL30561-IRA][OSL30561IRA]
- [Grove - 4-Digit Display][Grove4DigitLED]



<!-- 以下は，外部リンクの定義 
- Adafruit Unified Sensor Driver - [https://github.com/adafruit/Adafruit_Sensor][AdafruitUSD]
-->

<!-- 以下は，外部リンクの定義 -->
[A2308SR]:https://akizukidenshi.com/catalog/g/g104440/ <!-- 16セグLED -->
[OSL20541IR]:https://akizukidenshi.com/catalog/g/g116389/ <!-- 2桁 14セグLED + 2*コンマ -->
[OSL30561IRA]:https://akizukidenshi.com/catalog/g/g117364/ <!-- 3桁 7セグLED + 3*コンマ -->
[Grove4DigitLED]:https://wiki.seeedstudio.com/Grove-4-Digit_Display/ <!-- 4桁 7セグLED + 1*コロン -->

<!-- 以下は，外部リンクの定義 -->
[GroveBarometerSensorBMP180]:http://wiki.seeedstudio.com/Grove-Barometer_Sensor-BMP180/
[Grove]:https://www.seeedstudio.io/category/Grove-c-1003.html
[SeedStudio]:https://www.seeedstudio.io/
[AdafruitUSD]:https://github.com/adafruit/Adafruit_Sensor
[shield]:https://www.seeedstudio.com/Base-Shield-V2-p-1378.html
[M0Pro]:https://store.arduino.cc/usa/arduino-m0-pro
[Due]:https://store.arduino.cc/usa/arduino-due
[Uno]:https://store.arduino.cc/usa/arduino-uno-rev3
[UnoWiFi]:https://store.arduino.cc/usa/arduino-uno-wifi-rev2
[Mega]:https://store.arduino.cc/usa/arduino-mega-2560-rev3
[LeonardoEth]:https://store.arduino.cc/usa/arduino-leonardo-eth
[ProMini]:https://www.sparkfun.com/products/11114
[ESPrDev]:https://www.switch-science.com/catalog/2652/
[ESPrDevShield]:https://www.switch-science.com/catalog/2811/
[ESPrOne]:https://www.switch-science.com/catalog/2620/
[ESPrOne32]:https://www.switch-science.com/catalog/3555/
[Grove]:https://www.seeedstudio.io/category/Grove-c-1003.html
[SeedStudio]:https://www.seeedstudio.io/
[Arduino]:http://https://www.arduino.cc/
[Sparkfun]:https://www.sparkfun.com/
[SwitchScience]:https://www.switch-science.com/
[AusExGrove3AxisDigitalAccelerometer1_5g]:http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-1.5g/
[AusExGrove3AxisDigitalAccelerometer16g]:http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-16g/
[AusExGrove3AxisDigitalGyro]:http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Gyro/
[AusExGroveI2cTouchSensor]:http://wiki.seeedstudio.com/Grove-I2C_Touch_Sensor/
[AusExGroveAnalog1AxisGyro]:http://wiki.seeedstudio.com/Grove-Single_Axis_Analog_Gyro/
[AusExGroveAnalogCurrentSensor]:http://wiki.seeedstudio.com/Grove-Electricity_Sensor/
[AusExGroveAnalogTemperatureSensor]:http://wiki.seeedstudio.com/Grove-Temperature_Sensor_V1.2/
[AusExGroveGsr]:http://wiki.seeedstudio.com/Grove-GSR_Sensor/
[AusExGroveRotaryAngleSensor]:http://wiki.seeedstudio.com/Grove-Rotary_Angle_Sensor/
[AusExGroveSimpleLight]:http://wiki.seeedstudio.com/Grove-Light_Sensor/
[AusExGroveSimpleMoisture]:http://wiki.seeedstudio.com/Grove-Moisture_Sensor/
[AusExGroveSimpleSound]:http://wiki.seeedstudio.com/Grove-Loudness_Sensor/
[AusExDigitalSwitch]:http://wiki.seeedstudio.com/Grove-Switch-P/
[AusExGroveDustSensor]:http://wiki.seeedstudio.com/Grove-Dust_Sensor/
[AusExGroveInfraredDistanceSensor]:http://wiki.seeedstudio.com/Grove-IR_Distance_Interrupter_v1.2/
[AusExGroveInfraredReflectiveSensor]:http://wiki.seeedstudio.com/Grove-Infrared_Reflective_Sensor/
[AusExGroveTouchSensor]:http://wiki.seeedstudio.com/Grove-Touch_Sensor/
[AusExGroveUltrasonicRanger]:http://wiki.seeedstudio.com/Grove-Ultrasonic_Ranger/
[AusExGroveWaterSensor]:http://wiki.seeedstudio.com/Grove-Water_Sensor/
[AusExGrovePirSensor]:http://wiki.seeedstudio.com/Grove-PIR_Motion_Sensor/


<!--- コメント
[Adafruit Unified Sensor Driver][AdafruitUSD]
[Groveシールド][shield]
[Arduino M0 Pro][M0Pro]
[Arduino Due][Due]
[Arduino Uno R3][Uno]
[Arduino Mega2560 R3][Mega]
[Arduino Leonardo Ethernet][LeonardoEth]
[Arduino Pro mini 328 - 3.3V/8MHz][ProMini]
[ESpr one][ESPrOne]
[ESPr one 32][ESPrOne32]
[Grove][Grove]
[Seed Studio][SeedStudio]
[Arduino][Arduino]
[Sparkfun][Sparkfun]
[スイッチサイエンス][SwitchScience]
--->
