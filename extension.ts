//% color="#359eff" weight=20 icon="\uf1b2"
namespace MazeRobot {
    export enum Param{
        //% block="每格距离(默认175)"
        DIST_PER_CELL           =0x03,
        //% block="直线位置参数(默认25)"
        LR_TARGET_DIST          =0x04,
        //% block="直线速度(默认90)"
        MAX_LINEAR_SPEED        =0x05,
        //% block="墙面判断距离(默认80)"
        WALL_DETECT_DIST        =0x06,
        //% block="触发前后校正距离(默认140)"
        F_WALL_CORRECT_DIST     =0x07,
        //% block="前后校正目标距离(默认25)"
        F_WALL_TARGET_DIST      =0x08,
        //% block="前后校正容差(默认1)"
        F_ERR_MARGIN            =0x09,
        //% block="平行校正容差(默认2)"
        PARALLEL_ERR_MARGIN     =0x0A,
        //% block="平行校正次数(默认10)"
        PARALLEL_CORRECT_TIMES  =0x0B,
        //% block="初始方向(默认0朝上，90朝右，180朝下，270朝左)"
        ORIGIN_FACE_DIR         =0x0E,
        //% block="转弯速度(默认70)"
        MAX_ANGULER_SPEED       =0x11,
        //% block="转向校正(默认-50)"
        TURN_COMPENSATION       =0x12,
    }
    
    //% shim=MazeRobot::Init
    //% block="初始化机器人" 
    export function Init() {
        return
    }
    
    //% shim=MazeRobot::Set_Goal
    //% block="设置目的地坐标x=%x |y=%y" 
    //% x.defl=7 y.defl=7
    export function Set_Goal(x:number,y:number) {
        return
    }

    //% shim=MazeRobot::Set_Param
    //% block="设置控制参数 %param | %value" 
    //% value.defl=175
    export function Set_Param(param:Param,value:number) {
        return
    }
    
    //% shim=MazeRobot::Detect
    //% block="启动迷宫探索" 
    export function Detect() {
        return
    }

    //% shim=MazeRobot::Is_Finish
    //% block="完成探索" 
    export function Is_Finish() :boolean{
        return true
    }

    //% shim=MazeRobot::Rush
    //% block="冲刺" 
    export function Rush() {
        return
    }
    
}
