# 動作確認(簡易版)

## 動作確認結果のまとめ


### 7セグメントLED(時計型) : [Grove - 4-Digit Display][Grove4DigitLED]



|機種名|[Grove - 4-Digit Display][Grove4DigitLED]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|◯|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|





### [Grove - 4-Digit Display][Grove4DigitLED]以外のLEDで1桁のもの



|機種名|[OSL12306-16-IRA(秋月電子)][OSL12306-16-IRA]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|-|
|[Arduino UNO R4 Minima][UnoR4Minima]|-|
|[Arduino Nano 33 IoT][Nano33IoT]|-|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|-|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||



|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|







### [Grove - 4-Digit Display][Grove4DigitLED]以外のLEDで2桁以上のもの


|機種名|[OSL20541-IR(秋月電子)][OSL20541IR]|[OSL30561-IRA(秋月電子)][OSL30561IRA]|[3-Wire LED Module DFR0090][DFR0090]|
|---|---|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|未1|未1|✕|
|[Arduino Mega 2560][Mega2560]|◯|◯|✕|
|[Arduino M0 pro][M0Pro]|未1|未1|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|未1|未1|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|未1|未1|✕|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|◯|
|[Ardino MKR Zero][MKRZero]|未1|未1|✕|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||||

- 1 : ピン数が不足するため，動作確認していない

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|



## API一覧

```
UnifiedNSegLED(OSL30561* osl30561, UnifiedNSegLedType type);
UnifiedNSegLED(OSL20541* osl20541, UnifiedNSegLedType type);
UnifiedNSegLED(OSL12306_16* osl12306_16, UnifiedNSegLedType type);
UnifiedNSegLED(TM1637* tm1637, UnifiedNSegLedType type);

nSegLedFunctionReturnValue set(uint8_t = BRIGHT_TYPICAL,uint8_t = 0x40,uint8_t = 0xc0);
nSegLedFunctionReturnValue setColomn(bool flag);

nSegLedFunctionReturnValue begin(void);
nSegLedFunctionReturnValue clear(void);
nSegLedFunctionReturnValue display(uint64_t points, const char dispData[]);
nSegLedFunctionReturnValue display(const char dispData[]);
```

```
typedef enum {
  OSL12306_16_TYPE =1,
  OSL20541_TYPE,
  OSL30561_TYPE,
  GROVE_TM1637_TYPE
} UnifiedNSegLedType;

typedef enum {
  NSEGLED_FUNCTION_UNSUPPORTED = 1,
  NSEGLED_FUNCTION_SUCCESS,
  NSEGLED_FUNCTION_FAIL,
} nSegLedFunctionReturnValue;
```


## 7セグメントLED(時計型) : [Grove - 4-Digit Display][Grove4DigitLED]

###  テストシナリオ1 : コロンの点灯/消灯
#### テスト対象API
```
nSegLedFunctionReturnValue setColomn(bool flag);
```


#### 動作
- LEDを消す
- スタート合図を待つ
- 1秒間隔でコロンを点滅させる(合計10回) (消して終わる)
- 人に確認させて，応答を待つ．

#### テスト結果


|機種名|[Grove - 4-Digit Display][Grove4DigitLED]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|◯|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|



###  テストシナリオ2 : 数字の表示
#### テスト対象API
```
nSegLedFunctionReturnValue display(const char dispData[]);
```

#### 動作
- LEDを消す
- スタート合図を待つ
- 3秒間隔で以下のパターンで印字を繰り返す (x:0からf)
  - x□□□
  - □x□□
  - □□x□
  - □□□x
- 3秒間隔で以下のパターンで印字を繰り返す (x:0からf)
  - xxxx (全て同じ文字)
- 人に確認させて，応答を待つ．
- コロンを点けて同じ動作を繰り返す

#### テスト結果


|機種名|[Grove - 4-Digit Display][Grove4DigitLED]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|◯|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|



### テストシナリオ3 : 光度の変更の確認
#### テスト対象API
```
nSegLedFunctionReturnValue set(uint8_t = BRIGHT_TYPICAL,uint8_t = 0x40,uint8_t = 0xc0);
```

#### 動作
- LEDを消す
- スタート合図を待つ
- 光度を最高に設定(7)
- '0123'を印字
- 1秒間隔で光度を0～7まで変化 (3回繰り返す)
- 人に確認してもらい，応答を待つ


#### テスト結果


|機種名|[Grove - 4-Digit Display][Grove4DigitLED]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|◯|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


## [Grove - 4-Digit Display][Grove4DigitLED]以外のLEDで1桁のもの

### テストシナリオ1 : ピリオドだけのテスト

#### テスト対象API
```
nSegLedFunctionReturnValue display(uint64_t points, const char dispData[]);
```

#### 動作
- LEDを消す
- スタート合図を待つ
- 1秒間隔でピリオドだけをON/OFFする ``display(uint64_t 1, const char dispData[]= [0])`` (5回程度)
- LEDを消す
- 人に確認してもらい，応答を待つ



#### テスト結果


|機種名|[OSL12306-16-IRA(秋月電子)][OSL12306-16-IRA]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]||
|[Arduino Mega 2560][Mega2560]||
|[Arduino M0 pro][M0Pro]||
|[Arduino UNO R4 WiFi][UnoR4WiFi]||
|[Arduino UNO R4 Minima][UnoR4Minima]||
|[Arduino Nano 33 IoT][Nano33IoT]||
|[Arduino Giga R1 Wifi][GigaR1WiFi]||
|[Arduino MKR WiFi 1010][MKRWiFi1010]||
|[Ardino MKR Zero][MKRZero]||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|




### テストシナリオ2 : 文字だけのテスト

#### テスト対象API
```
nSegLedFunctionReturnValue display(uint64_t points, const char dispData[]);
```

#### 動作
- LEDを消す
- スタート合図を待つ
- 1秒間隔で表示する文字を変化させていく ``nSegLedFunctionReturnValue display(uint64_t 0, const char dispData[] = [x]);``ここで``x``はWSP(0),-,0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,zと切り替える．
- LEDを消す
- 人に確認してもらい，応答を待つ


#### テスト結果


|機種名|[OSL12306-16-IRA(秋月電子)][OSL12306-16-IRA]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]||
|[Arduino Mega 2560][Mega2560]||
|[Arduino M0 pro][M0Pro]||
|[Arduino UNO R4 WiFi][UnoR4WiFi]||
|[Arduino UNO R4 Minima][UnoR4Minima]||
|[Arduino Nano 33 IoT][Nano33IoT]||
|[Arduino Giga R1 Wifi][GigaR1WiFi]||
|[Arduino MKR WiFi 1010][MKRWiFi1010]||
|[Ardino MKR Zero][MKRZero]||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|




### テストシナリオ3 : ピリオドと文字の同時表示のテスト

#### テスト対象API
```
nSegLedFunctionReturnValue display(uint64_t points, const char dispData[]);
```

#### 動作

- LEDを消す
- スタート合図を待つ
- 1秒間隔で表示する文字を変化させていく ``nSegLedFunctionReturnValue display(uint64_t flag, const char dispData[] = [x]);``ここで``x``はWSP(0),-,0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,zと切り替える．flagは0と1を切り替える．
- LEDを消す
- 人に確認してもらい，応答を待つ

#### テスト結果


|機種名|[OSL12306-16-IRA(秋月電子)][OSL12306-16-IRA]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]||
|[Arduino Mega 2560][Mega2560]||
|[Arduino M0 pro][M0Pro]||
|[Arduino UNO R4 WiFi][UnoR4WiFi]||
|[Arduino UNO R4 Minima][UnoR4Minima]||
|[Arduino Nano 33 IoT][Nano33IoT]||
|[Arduino Giga R1 Wifi][GigaR1WiFi]||
|[Arduino MKR WiFi 1010][MKRWiFi1010]||
|[Ardino MKR Zero][MKRZero]||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|



## [Grove - 4-Digit Display][Grove4DigitLED]以外のLEDで2桁以上のもの

### テストシナリオ1 : ピリオドだけのテスト

#### テスト対象API
```
nSegLedFunctionReturnValue display(uint64_t points, const char dispData[]);
```

#### 動作
- LEDを消す
- スタート合図を待つ
- 1秒間隔でピリオドだけを次のように設定する．(5回程度の繰り返し)
  - ON, OFF, OFF -> OFF, ON, OFF -> OFF, OFF, ON
  - OFF, ON, ON -> ON, OFF, ON -> ON, ON, OFF
- 人に確認してもらい，応答を待つ


#### テスト結果


|機種名|[OSL20541-IR(秋月電子)][OSL20541IR]|[OSL30561-IRA(秋月電子)][OSL30561IRA]|[OSL12306-16-IRA(秋月電子)][OSL12306-16-IRA]|[3-Wire LED Module DFR0090][DFR0090]|
|---|---|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|未1|未1|||
|[Arduino Mega 2560][Mega2560]|◯|◯|||
|[Arduino M0 pro][M0Pro]|未1|未1|||
|[Arduino UNO R4 Minima][UnoR4Minima]|未1|未1|||
|[Arduino Nano 33 IoT][Nano33IoT]|未1|未1|||
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|||
|[Ardino MKR Zero][MKRZero]|未1|未1|||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|||||

- 1 : ピン数が不足するため，動作確認していない

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


### テストシナリオ2 : 文字だけのテスト

#### テスト対象API
```
nSegLedFunctionReturnValue display(uint64_t points, const char dispData[]);
```

#### 動作
- LEDを消す
- スタート合図を待つ
- 1秒間隔で表示する文字を変化させていく ``nSegLedFunctionReturnValue display(uint64_t 0, const char dispData[] = [x]);``ここで``x``はWSP(0),-,0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,zと切り替える．(全ての桁が同じ表示で良い)
- LEDを消す
- 人に確認してもらい，応答を待つ


#### テスト結果

|機種名|[OSL20541-IR(秋月電子)][OSL20541IR]|[OSL30561-IRA(秋月電子)][OSL30561IRA]|[OSL12306-16-IRA(秋月電子)][OSL12306-16-IRA]|[3-Wire LED Module DFR0090][DFR0090]|
|---|---|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|未1|未1|||
|[Arduino Mega 2560][Mega2560]|◯|◯|||
|[Arduino M0 pro][M0Pro]|未1|未1|||
|[Arduino UNO R4 Minima][UnoR4Minima]|未1|未1|||
|[Arduino Nano 33 IoT][Nano33IoT]|未1|未1|||
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|||
|[Ardino MKR Zero][MKRZero]|未1|未1|||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|||||

- 1 : ピン数が不足するため，動作確認していない


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


### テストシナリオ3 : ピリオドと文字の同時表示のテスト

#### テスト対象API
```
nSegLedFunctionReturnValue display(uint64_t points, const char dispData[]);
```

#### 動作

- LEDを消す
- スタート合図を待つ
- 1秒間隔で表示する文字を変化させていく ``nSegLedFunctionReturnValue display(uint64_t flag, const char dispData[] = [x]);``ここで``x``はWSP(0),-,0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,zと切り替える．flagは0と2進数全桁1を切り替える．(全ての桁が同じ表示で良い)
- LEDを消す
- 人に確認してもらい，応答を待つ


#### テスト結果


|機種名|[OSL20541-IR(秋月電子)][OSL20541IR]|[OSL30561-IRA(秋月電子)][OSL30561IRA]|[OSL12306-16-IRA(秋月電子)][OSL12306-16-IRA]|[3-Wire LED Module DFR0090][DFR0090]|
|---|---|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|未1|未1|||
|[Arduino Mega 2560][Mega2560]|◯|◯|||
|[Arduino M0 pro][M0Pro]|未1|未1|||
|[Arduino UNO R4 Minima][UnoR4Minima]|未1|未1|||
|[Arduino Nano 33 IoT][Nano33IoT]|未1|未1|||
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|||
|[Ardino MKR Zero][MKRZero]|未1|未1|||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|||||

- 1 : ピン数が不足するため，動作確認していない

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|



### コンパイルテスト

|Arduino機種|コンパイル結果|
|---|---|
|[Arduino Nano ESP32][NanoESP32]||
|[Arduino Mega 2560][Mega2560]||
|[Arduino M0 pro][M0Pro]||
|[Arduino UNO R4 WiFi][UnoR4WiFi]||
|[Arduino UNO R4 Minima][UnoR4Minima]||
|[Arduino Nano 33 IoT][Nano33IoT]||
|[Arduino Giga R1 Wifi][GigaR1WiFi]||
|[Arduino MKR WiFi 1010][MKRWiFi1010]||
|[Ardino MKR Zero][MKRZero]||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||

|内容|意味|
|---|---|
|◯|コンパイル成功|
|△|条件付き|
|✕|コンパイルできない|
|-|原理的に互換性がない|
|未|未検証|


## テスト環境


|ソフトウェア/Arduinoファミリ|モジュール名|開発元|バージョン|
|---|---|---|---|
|Arduino IDE|－|Arduino|2.3.2|
|AVR|Arduino AVR Boards|Arduino|1.8.6|
|ESP32|Arduino ESP32 Boards|Arduino|2.0.18|
|Giga|Arduino Mbed OS Giga Boards|Arduino|4.3.1|
|Nano|Arduino Mbed OS Nano Boards|Arduino|4.3.1|
|M0|Arduino SAMD Boards (32bits ARM Cortex-M0+)|Arduino|1.8.14|
|UnoR4|Arduino Uno R4 Boards|Arduino|1.4.1|

### コンパイルテスト

|Arduino機種|コンパイル結果|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|◯|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 WiFi][UnoR4WiFi]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Arduino MKR WiFi 1010][MKRWiFi1010]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|◯|

|内容|意味|
|---|---|
|◯|コンパイル成功|
|△|条件付き|
|✕|コンパイルできない|
|-|原理的に互換性がない|
|未|未検証|

<!-- 


#### テスト結果


|機種名|[OSL12306-16-IRA(秋月電子)][OSL12306-16-IRA]|[OSL20541-IR(秋月電子)][OSL20541IR]|[OSL30561-IRA(秋月電子)][OSL30561IRA]|[Grove - 4-Digit Display][Grove4DigitLED]|
|---|---|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|||||
|[Arduino Mega 2560][Mega2560]|||||
|[Arduino M0 pro][M0Pro]|||||
|[Arduino UNO R4 WiFi][UnoR4WiFi]|||||
|[Arduino UNO R4 Minima][UnoR4Minima]|||||
|[Arduino Nano 33 IoT][Nano33IoT]|||||
|[Arduino Giga R1 Wifi][GigaR1WiFi]|||||
|[Arduino MKR WiFi 1010][MKRWiFi1010]|||||
|[Ardino MKR Zero][MKRZero]|||||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|||||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|

 -->




<!-- NセグメントLED -->

|セグメント数|桁数|種別番号|名称/型番|コントローラ|電圧(V)|
|---|---|---|---|---|---|
|16|1|2|[OSL12306-16-IRA(秋月電子)][OSL12306-16-IRA]|なし|3.6～5.0(逆電圧:10)|
|14|2|2|[OSL20541-IR(秋月電子)][OSL20541IR]|なし|2.1(逆電圧:5)|
|7|3|2|[OSL30561-IRA(秋月電子)][OSL30561IRA]|なし|2.1(逆電圧:5)|
|7|4|1|[Grove - 4-Digit Display][Grove4DigitLED]|TM1637|3.3～5.5|
|7|8|2|[3-Wire LED Module DFR0090][DFR0090]|74HC595||

|種別番号|コンマ/コロン/ピリオド等|
|---|---|
|1|時計タイプ(真ん中にセミコロン)|
|2|各桁にピリオド|

<!-- 16セグLED -->
[OSL12306-16-IRA]:https://akizukidenshi.com/catalog/g/g114656/
<!-- 2桁 14セグLED + 2*コンマ -->
[OSL20541IR]:https://akizukidenshi.com/catalog/g/g116389/
<!-- 3桁 7セグLED + 3*コンマ -->
[OSL30561IRA]:https://akizukidenshi.com/catalog/g/g117364/
<!-- 4桁 7セグLED + 1*コロン -->
[Grove4DigitLED]:https://wiki.seeedstudio.com/Grove-4-Digit_Display/
<!-- S3-Wire LED Module DFR0090 : SPI(3線式) LED Module 8 Digital (8桁赤色7セグLEDモジュール) -->
[DFR0090]:https://akizukidenshi.com/catalog/g/g106681/

<!-- Arduino 本体 -->

|機種名|コア|MCU|動作電圧|
|---|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|Xtensa LX6|ESP32-S3|3.3V|
|[Arduino Mega 2560][Mega2560]|AVR|ATmega2560|5V|
|[Arduino M0 pro][M0Pro]|ARM Cortex-M0+|ATSAMD21G18|3.3V|
|[Arduino UNO R4 WiFi][UnoR4WiFi]|ARM Cortex-M4|RA4M1|5V|
|[Arduino UNO R4 Minima][UnoR4Minima]|ARM Cortex-M4|RA4M1|5V|
|[Arduino Nano 33 IoT][Nano33IoT]|ARM Cortex-M0+|SAMD21|3.3V|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|ARM Cortex-M7|STM32H747XI|3.3V|
|[Arduino MKR WiFi 1010][MKRWiFi1010]|ARM Cortex-M0+|SAMD21|3.3V|
|[Ardino MKR Zero][MKRZero]|ARM Cortex-M0+|SAMD21|3.3V|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|ARM Cortex-M0+|Raspberry Pi RP2040|3.3V|

<!-- Arduino Nano ESP32 -->
[NanoESP32]:https://docs.arduino.cc/hardware/nano-esp32/
<!--Arduino Mega 2560-->
[Mega2560]:https://docs.arduino.cc/hardware/mega-2560/
<!--Arduino M0 pro-->
[M0Pro]:https://docs.arduino.cc/retired/boards/arduino-m0-pro/
<!--Arduino UNO R4 WiFi-->
[UnoR4WiFi]:https://docs.arduino.cc/hardware/uno-r4-wifi/
<!--Arduino UNO R4 Minima-->
[UnoR4Minima]:https://docs.arduino.cc/hardware/uno-r4-minima/
<!--Arduino Nano 33 IoT-->
[Nano33IoT]:https://docs.arduino.cc/hardware/nano-33-iot/
<!--Arduino Giga R1 Wifi-->
[GigaR1WiFi]:https://docs.arduino.cc/hardware/giga-r1-wifi/
<!--Arduino MKR WiFi 1010-->
[MKRWiFi1010]:https://docs.arduino.cc/hardware/mkr-wifi-1010/
<!--Ardino MKR Zero-->
[MKRZero]:https://docs.arduino.cc/hardware/mkr-zero/
<!--Arduino Nano RP2040 Connect-->
[NanoRP2040Connect]:https://docs.arduino.cc/hardware/nano-rp2040-connect/




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
