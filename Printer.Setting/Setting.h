/**************РАСПИНОВКА ВЫВОДОВ**************/

//Светодиоды
#define LED_RED        34
#define LED_ORANGE     36
#define LED_BLUE       38
#define LED_GREEN      40
#define LED_RGB_RED    32
#define LED_RGB_GREEN  30
#define LED_RGB_BLUE   28

//Кнопки
#define BTN_1          5
#define BTN_2          9
#define BTN_3          7
#define BTN_4          8
#define BTN_5          6

//Реле
#define RELE_DRIVER    44
#define RELE_EPSON     46

//Концевики
#define LIMITER_START  39
#define LIMITER_FINISH 37

//Датчики Epson
#define SENSOR_PD      31
#define SENSOR_PF      29

//Энкодер Epson
#define ENCODER_A      43
#define ENCODER_B      45

//Кнопка включения Epson
#define BTN_EPSON      41

//Драйвер ШД
#define MOTOR_STEP     23
#define MOTOR_DIR      25
#define MOTOR_ENB      27

//Ultrasonic
#define TRIG           33
#define ECHO           35





/**************НАСТРЙОКИ ПРИВОДА**************/

//Количество рисок на энкодере Epson
#define EPSON_ENCODER_DPI    2160
//Диаметр вала протяжки бумаги Epson, мм
#define EPSON_SHAFT_DIAMETER 8
//Количество шагов в одном обороте ШД
#define MOTOR_STEPS_DPI      6400
//Диаметр муфты для ШД, мм
#define MOTOR_SHAFT_DIAMETER 55
//Скорость движения ШД, микросекунд на один шаг
#define MOTOR_SPEED          270
//Главная нулевая точка
#define MAIN_ZERO            270





/**************ДРУГИЕ НАСТРОЙКИ**************/

//Время срабатывания кнопки включения Epson, количество итераций
#define EPSON_BTN_POWER_TIME 200000
//Время инициализации Epson, сек
#define EPSON_READY_TIME     52

//количество столов
#define TRAYS_COUNT 2
