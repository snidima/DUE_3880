/**************РАСПИНОВКА ВЫВОДОВ**************/

//Светодиоды
#define LED_RED        34
#define LED_ORANGE     36
#define LED_BLUE       38
#define LED_GREEN      40

//Кнопки
#define BTN_1          5
#define BTN_2          6
#define BTN_3          7
#define BTN_4          8

//Реле
#define RELE_DRIVER    44
#define RELE_EPSON     46

//Концевики
#define LIMITER_START  37
#define LIMITER_FINISH 39

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






/**************НАСТРЙОКИ ПРИВОДА**************/

//Количество рисок на энкодере Epson
#define EPSON_ENCODER_DPI    2160
//Диаметр вала протяжки бумаги Epson, мм
#define EPSON_SHAFT_DIAMETER 8
//Количество шагов в одном обороте ШД
#define MOTOR_STEPS_DPI      1600
//Диаметр муфты для ШД, мм
#define MOTOR_SHAFT_DIAMETER 55
//Скорость движения ШД, микросекунд на один шаг
#define MOTOR_SPEED          350





/**************ДРУГИЕ НАСТРОЙКИ**************/

//Время срабатывания кнопки включения Epson, количество итераций
#define EPSON_BTN_POWER_TIME 200000

