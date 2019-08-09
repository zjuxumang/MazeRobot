#include "pxt.h"
#include "i2c_hw_interface.h"
using namespace pxt;
#define DETECT                  0x01
#define RUSH                    0x02
#define DIST_PER_CELL           0x03
#define LR_TARGET_DIST          0x04
#define MAX_LINEAR_SPEED        0x05
#define WALL_DETECT_DIST        0x06
#define F_WALL_CORRECT_DIST     0x07
#define F_WALL_TARGET_DIST      0x08
#define F_ERR_MARGIN            0x09
#define PARALLEL_ERR_MARGIN     0x0A
#define PARALLEL_CORRECT_TIMES  0x0B
#define X0_POS                  0x0C
#define Y0_POS                  0x0D
#define ORIGIN_FACE_DIR         0x0E
#define Goal_X                  0x0F
#define Goal_Y                  0x10
#define MAX_ANGULER_SPEED       0x11
#define TURN_COMPENSATION       0x12
#define IS_FINISH               0x13
namespace MazeRobot {
    CubeI2C* i2c=new CubeI2C(&uBit.i2c,0x70);
    uint8_t Left_wheel=255;
    uint8_t Right_wheel=255;
    uint8_t data[16]={0};
    //%
    void Init() {
        uBit.io.P16.setDigitalValue(0);
        wait_ms(10);
        uBit.io.P16.setDigitalValue(1);
        wait_ms(10);
    }

    //%
    void Set_Param(int param_id, int value) {
        i2c->I2CWrite16((uint8_t)param_id,value);
        wait_ms(5);
    }

    //%
    void Set_Goal(int x, int y) {
        Set_Param(Goal_X, x);
        Set_Param(Goal_Y, y);
    }

    //%
    int Is_Finish() {
        int ret=0;
        uint8_t state=0;
        ret=i2c->I2CRead(IS_FINISH,&state);
        if(ret||state)
            return 0;
        else
            return 1;
    }
    
    //%
    void Detect() {
        i2c->I2CWrite(DETECT,1);
    }

    //%
    void Rush() {
        i2c->I2CWrite(RUSH,1);
    }


}