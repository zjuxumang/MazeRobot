#include "pxt.h"
#include "i2c_hw_interface.h"
using namespace pxt;

#define 	DETECT 							0x01	//三个参数，目标(x,y)和是否记录并简化路径
#define 	SEND_PATH						0x02	//发送记录的路径
#define		RUSH							0x03	//若记录并简化路径则可按照简化后的路径RUSH
#define 	DISTANCE_MOVE   				0x04	//前进一段距离
#define 	TURN   							0x05	//turn('S/L/R/B') 注：会记录坐标变化
#define 	SET_POSITION   					0x06	//设定当前坐标与朝向
#define 	STRING_MOVE   					0x07	//接收一个字符串，按照字符串前进
#define 	PARALLEL_CORRECTION   	        0x08	
#define 	FRONT_CORRECTION   			    0x09	
#define 	SET_TURN_RULE   				0x0A	//设置LR，LR=0左迷宫，LR=1右迷宫
#define 	SET_MOTOR						0x0B	//设置电机序号
#define 	SEND_SENSOR_VALUE   		    0x0C	//发送传感器数值0~5->右后/右前/正前/左前/左后
#define 	SENSOR_RESULT  					0x0D	//发送传感器结果（是否有墙）

#define 	SET_STRAIGHT_SPEED  		    0x0E
#define 	SET_TURN_SPEED  				0x0F
#define 	SET_DIST_PER_CELL  			    0x10
#define 	SET_LR_TARGET_DIST  		    0x11
#define		SET_WALL_EXIST_DIST 		    0x12
#define		SET_F_CORRECT_DIST			    0x13
#define		SET_F_TARGET_DIST				0x14
#define		SET_F_MARGIN					0x15
#define		SET_PARALLEL_MARGIN			    0x16
#define		SET_PARALLEL_CORRECT_TIMES	    0x17
#define		SET_TURN_COMPENSATION		    0x18
namespace MazeRobot {
    CubeI2C* i2c=new CubeI2C(&uBit.i2c,0x70);
    uint8_t Left_wheel=255;
    uint8_t Right_wheel=255;
    uint8_t data[16]={0};
    //%
    void wait_for_finish(){
        uint8_t is_finish=0;
        while(1){
            if(i2c->I2CRead(0x00,&is_finish)!=0)
                continue;
            else
                if(is_finish)
                    break;
            wait_ms(500);
        }
    }

    //%
    void Init(int ML,int MR) {
        uBit.io.P16.setDigitalValue(0);
        wait_us(100);
        uBit.io.P16.setDigitalValue(1);
        wait_ms(100);
        i2c->I2CWrite2Bytes(SET_MOTOR,0);
        wait_ms(10);
        i2c->I2CWrite2Bytes(ML+1,MR+1);
        wait_ms(10);
    }

    //%
    void Go_Path() {
        i2c->I2CWrite2Bytes(RUSH,0);
        wait_ms(500);
        wait_for_finish();
    }

    //%
    void Go_Distance(int n) {
        i2c->I2CWrite2Bytes(DISTANCE_MOVE,(uint8_t)n);
        wait_ms(500);
        wait_for_finish();
    }

    //%
    void Turn(int dir) {
        i2c->I2CWrite2Bytes(TURN,(uint8_t)dir);
        wait_ms(500);
        wait_for_finish();
    }

    //% 
    void Set_Pos(int x,int y,int dir) {
        i2c->I2CWrite2Bytes(SET_POSITION,0);
        uint8_t cmd[3];
        cmd[0]=x;
        cmd[1]=y;
        cmd[2]=dir;
        wait_ms(10);
        i2c->I2CWriteBuffer(cmd,3);
        wait_ms(10);
    }

    //%
    void Paraller_Correct() {
        i2c->I2CWrite2Bytes(PARALLEL_CORRECTION,0);
        wait_ms(500);
        wait_for_finish();
    }
    //%
    void FB_Correct() {
        i2c->I2CWrite2Bytes(FRONT_CORRECTION,0);
        wait_ms(500);
        wait_for_finish();
    }

    //%
    void Set_Regular(int regular) {
        i2c->I2CWrite2Bytes(SET_TURN_RULE,regular);
        wait_ms(10);
    }

    //%
    void Set_Param(int param_id, int value) {
        i2c->I2CWrite2Bytes(param_id+0x0e,0);
        wait_ms(10);
        i2c->I2CWrite2Bytes((uint8_t)(value&0x00ff),(uint8_t)(value>>8));
        wait_ms(10);
    }
    
    //%
    void Move_to(int x,int y) {
        i2c->I2CWrite2Bytes(DETECT,1);
        wait_ms(10);
        i2c->I2CWrite2Bytes(x,y);
        wait_ms(1000);
        wait_for_finish();
    }
    
    //%
    void Get_Sensor_Data(){
        i2c->I2CWrite2Bytes(SEND_SENSOR_VALUE,1);
    }

}