#include "motorctrl.h"

motorCtrl::motorCtrl()
{

}
void motorCtrl::all_motor_init()
{
    int i = 0;
    set_mode_control();
    for(i = 1; i < 13; i++)
    {
        sleep(10000);
        disable_model_set(i);
        set_motor_mode(i,0x03);
        enable_model_set(i);
        motor_0(i);
    }
    rcsLog->info("moto_driver_Init!!!");
}
u8 motorCtrl::get_motor_position(u8 slaveID)
{
    CAN_DataFrame send[1];
    int nodeID = 0x0C;
    nodeID <<= 7;
    nodeID |= slaveID;

    send[0].uID = nodeID;      // ID
    send[0].nSendType = 0;  	// 0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
    send[0].bRemoteFlag = 0;  	// 0-数据帧；1-远程帧
    send[0].bExternFlag = 0;  	// 0-标准帧；1-扩展帧
    send[0].nDataLen = 6;     	// DLC
    send[0].arryData[0] = 0x40;
    send[0].arryData[1] = 0x63;
    send[0].arryData[2] = 0x60;
    send[0].arryData[3] = 0x00;
    send[0].arryData[4] = 0x00;
    send[0].arryData[5] = 0x00;

    CAN_ChannelSend(dwDeviceHandle, 0, send, 1);//设备句柄、通道数、预发送的数据帧数组首指针、预发送的数据帧数组的长度
    return 0;
}
u8 motorCtrl::motor_stop(u8 slaveID)
{
    CAN_DataFrame send[1];
    int nodeID = 0x0C;
    nodeID <<= 7;
    nodeID |= slaveID;
    int flag;
    send[0].uID = nodeID;       // ID
    send[0].nSendType = 0;  // 0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
    send[0].bRemoteFlag = 0;  // 0-数据帧；1-远程帧
    send[0].bExternFlag = 0;  // 0-标准帧；1-扩展帧
    send[0].nDataLen = 6;     // DLC
    send[0].arryData[0] = 0x2B;
    send[0].arryData[1] = 0x02;
    send[0].arryData[2] = 0x20;
    send[0].arryData[3] = 0x00;
    send[0].arryData[4] = 0x01;
    send[0].arryData[5] = 0x00;

    flag=CAN_ChannelSend(dwDeviceHandle, 0, send, 1);//设备句柄、通道数、预发送的数据帧数组首指针、预发送的数据帧数组的长度
    if(flag==0)rcsLog->info("Get 0! ");
    return 0;
}
u8 motorCtrl::set_motor_speed(u8 slaveID, float speed)
{
    CAN_DataFrame send[1];
    int nodeID = 0x0C;
    nodeID <<= 7;
    nodeID |= slaveID;
    short speed;
    speed =data_speed*(-2412.45);//

    send[0].uID = nodeID;         	// ID
    send[0].nSendType = 0;  		// 0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
    send[0].bRemoteFlag = 0;  		// 0-数据帧；1-远程帧
    send[0].bExternFlag = 0;  		// 0-标准帧；1-扩展帧
    send[0].nDataLen = 6;     		// DLC
    send[0].arryData[0] = 0x2B;
    send[0].arryData[1] = 0xFF;
    send[0].arryData[2] = 0x60;
    send[0].arryData[3] = 0x00;
    send[0].arryData[4] = speed;
    send[0].arryData[5] =  (speed >> 8);
    CAN_ChannelSend(dwDeviceHandle, 0, send, 1);//设备句柄、通道数、预发送的数据帧数组首指针、预发送的数据帧数组的长度
    //printf("slaveID = %d,  send speed = %f\n",slaveID,data_speed);
    //delay_us(1000);
    return 0;
}
u8 motorCtrl::set_motor_acc(u8 slaveID, float acc)
{
    CAN_DataFrame send[1];
    int nodeID = 0x0C;
    nodeID <<= 7;
    nodeID |= slaveID;
    short Motec_acc;
    Motec_acc=acc;

    send[0].uID = nodeID;       // ID
    send[0].nSendType = 0;  	// 0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
    send[0].bRemoteFlag = 0;  	// 0-数据帧；1-远程帧
    send[0].bExternFlag = 0;  	// 0-标准帧；1-扩展帧
    send[0].nDataLen = 6;     	// DLC
    send[0].arryData[0] = 0x2B;
    send[0].arryData[1] = 0x82;
    send[0].arryData[2] = 0x60;
    send[0].arryData[3] = 0x00;
    send[0].arryData[4] = Motec_acc;
    send[0].arryData[5] = (Motec_acc>>8);

    CAN_ChannelSend(dwDeviceHandle, 0, send, 1);//设备句柄、通道数、预发送的数据帧数组首指针、预发送的数据帧数组的长度
    // usleep(1000);
    return 0;
}
u8 motorCtrl::set_motor_dec(u8 slaveID, float dec)
{
    CAN_DataFrame send[1];
    int nodeID = 0x0C;
    nodeID <<= 7;
    nodeID |= slaveID;
    short Motec_decc;
    Motec_decc=decc;

    send[0].uID = nodeID;      // ID
    send[0].nSendType = 0;  	// 0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
    send[0].bRemoteFlag = 0;  	// 0-数据帧；1-远程帧
    send[0].bExternFlag = 0;  	// 0-标准帧；1-扩展帧
    send[0].nDataLen = 6;     	// DLC
    send[0].arryData[0] = 0x2B;
    send[0].arryData[1] = 0x83;
    send[0].arryData[2] = 0x60;
    send[0].arryData[3] = 0x00;
    send[0].arryData[4] = Motec_decc;
    send[0].arryData[5] = (Motec_decc>>8);

    CAN_ChannelSend(dwDeviceHandle, 0, send, 1);//设备句柄、通道数、预发送的数据帧数组首指针、预发送的数据帧数组的长度
    // usleep(1000);
    return 0;
}
u8 motorCtrl::set_motor_speed_posMode(u8 slaveID, float maxSpeed)
{
    CAN_DataFrame send[1];
    int nodeID = 0x0C;
    nodeID <<= 7;
    nodeID |= slaveID;
    short maxspeed;
    maxspeed=Maxspeed*2412.45;

    send[0].uID = nodeID;      // ID
    send[0].nSendType = 0;  	// 0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
    send[0].bRemoteFlag = 0;  	// 0-数据帧；1-远程帧
    send[0].bExternFlag = 0;  	// 0-标准帧；1-扩展帧
    send[0].nDataLen = 6;     	// DLC
    send[0].arryData[0] = 0x2B;
    send[0].arryData[1] = 0x7F;
    send[0].arryData[2] = 0x60;
    send[0].arryData[3] = 0x00;
    send[0].arryData[4] = (u8)maxspeed;
    send[0].arryData[5] = (u8)(maxspeed>>8);

    CAN_ChannelSend(dwDeviceHandle, 0, send, 1);//设备句柄、通道数、预发送的数据帧数组首指针、预发送的数据帧数组的长度
    // usleep(1000);
    return 0;
}
u8 motorCtrl::set_motor_mode(u8 slaveID,u8 mode_x)
{

}
u8 motorCtrl::set_motor_position(u8 slaveID, int pos)
{

}
void motorCtrl::motor_disable(void)
{
    disable_model_set(1);		//所有驱动轮使能失效
    disable_model_set(2);
    disable_model_set(3);
    disable_model_set(4);
}
void motorCtrl::motor_enable(void)
{
    enable_model_set(1);		//所有驱动轮使能失效
    enable_model_set(2);
    enable_model_set(3);
    enable_model_set(4);
}
u8 motorCtrl::set_rot_wheel_speed(u8 slaveID, float data_speed)
{
    CAN_DataFrame send[1];
    int nodeID = 0x0C;
    nodeID <<= 7;
    nodeID |= slaveID;
    short speed;
    speed =data_speed*(42.5);//

    send[0].uID = nodeID;         	// ID
    send[0].nSendType = 0;  		// 0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
    send[0].bRemoteFlag = 0;  		// 0-数据帧；1-远程帧
    send[0].bExternFlag = 0;  		// 0-标准帧；1-扩展帧
    send[0].nDataLen = 6;     		// DLC
    send[0].arryData[0] = 0x2B;
    send[0].arryData[1] = 0xFF;
    send[0].arryData[2] = 0x60;
    send[0].arryData[3] = 0x00;
    send[0].arryData[4] = speed;
    send[0].arryData[5] =  (speed >> 8);

    CAN_ChannelSend(dwDeviceHandle, 0, send, 1);//设备句柄、通道数、预发送的数据帧数组首指针、预发送的数据帧数组的长度
    //delay_us(1000);
    return 0;
}

void motorCtrl::stop_drv_motor(void)
{
    motor_stop(1);//整车驱动器停止
    motor_stop(2);
    motor_stop(3);
    motor_stop(4);
}
