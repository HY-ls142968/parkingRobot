#ifndef MOTORCTRL_H
#define MOTORCTRL_H
#include "../macrodef.h"
#include "../stdfx.h"
#include "../communicationBus/canbus.h"

extern u8 Enquire_ID;

//slaveID:需要配置的从站ID
u8 set_mode_control(void);
u8 clear_moto_code(u8 slaveID);
/*夹杆电机控制模式切换, 0为速度模式，1为位置模式*/
void change_qian_mode(u8 mode);
u8 set_steering_wheel_speed(u8 slaveID, float data_speed);
void change_hou_mode(u8 mode);
void clear_car_code(int cmd);
void car_mileage_read(void);
u8 enable_model_set(u8 slaveID);
u8 disable_model_set(u8 slaveID);

u8 motor_start(u8 slaveID);

u8 set_motor_to_move(u8 slaveID);



void Motec_Disable(void);
void Motec_Enable(void);
void Stop_AGV(void);
void Speed_AGV(float speed);
void Shift_AGV(float speed);
void FrontalWheel_GoAhead(u8 mode,int arg);
void RearWheel_GoAhead(u8 mode,int arg);
void FrontalWheel_GoBack(u8 mode,int arg);
void RearWheel_GoBack(u8 mode,int arg);
extern void car_spin(u8 LR_flag, int angle);
void car_GoAhead(u8 mode,int arg);
void car_GoBack(u8 mode,int arg);
void car_stop(void);
u8 wheel_lift(u8 select, int degree);

u8 AGV_SPEED_Enquire(u8 slaveID) ;

u8 Set_motor_decc_stop(u8 slaveID, float decc);//急停减速度
u8 Set_motor_rateCurrent(u8 slaveID, float current);
u8 Set_motor_maxCurrent(u8 slaveID, float current);
u8 Set_motor_I2Ttime(u8 slaveID, float time);
u8 error_code(u8 slaveID);
u8 current_read(u8 slaveID);
u8 max_current_read(u8 slaveID);
u8 rate_current_read(u8 slaveID);
u8 I2T_time_read(u8 slaveID);


//所有电机初始化
void motorCtlInit(void);
void test_motor();
float CAN_AGVspeed(u8 slaveID);

void moto_driver_init(void);
void motor_0(u8 id); //将 速度设置为0
void read_moto_speed(void);
void read_mote_current(void);

class motorCtrl
{
public:
    motorCtrl();
    void all_motor_init();
    u8 get_motor_position(u8 slaveID);
    u8 motor_stop(u8 slaveID);
    u8 set_motor_speed(u8 slaveID, float speed);
    u8 set_motor_acc(u8 slaveID, float acc);
    u8 set_motor_dec(u8 slaveID, float dec);
    u8 set_motor_speed_posMode(u8 slaveID, float maxSpeed);
    u8 set_motor_mode(u8 slaveID,u8 mode_x);
    u8 set_motor_position(u8 slaveID, int pos);
    void motor_disable(void);
    void motor_enable(void);
    u8 set_rot_wheel_speed(u8 slaveID, float data_speed);
    void stop_drv_motor(void);
};

#endif // MOTORCTRL_H
