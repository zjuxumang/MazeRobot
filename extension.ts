//% color="#359eff" weight=20 icon="\uf1b2"
namespace MazeRobot {
    export enum Param{
        //% block="直行速度(默认90)"
        MAX_LINEAR_SPEED        =0x01,
        //% block="转向速度(默认70)"
        MAX_ANGULER_SPEED       =0x02,
        //% block="一格距离(默认175)"
        DIST_PER_CELL           =0x03,
        //% block="贴墙前进时与墙面距离(默认25)"
        WALL_KEEP_DIST          =0x04,
        //% block="探墙阈值(默认60)"
        WALL_DETECT_DIST        =0x05,
        //% block="前后校准阈值(默认140)"
        F_WALL_CORRECT_THRESHOLD=0x06,
        //% block="前后校准目标值(默认25)"
        F_WALL_TARGET_DIST      =0x07,
        //% block="前后校准容差(默认1)"
        F_ERR_MARGIN            =0x08,
        //% block="平行校正容差(默认2)"
        PARALLEL_ERR_MARGIN     =0x09,
        //% block="平行校正次数(默认10)"
        PARALLEL_CORRECT_TIMES  =0x0A,
        //% block="转向补偿(默认0)"
        TURN_COMPENSATION       =0x0B,
    }
    export enum Motor_ID{
        M1,
        M2,
        M3,
        M4
    }
    
    //% shim=MazeRobot::Init
    //% block="初始化机器人 左马达%ML|右马达%MR" 
    export function Init(ML:Motor_ID,MR:Motor_ID) {
        return
    }

    export enum ENABLE{
        //% block="是"
        YES,
        //% block="否"
        NO
    }
    
    //% block="按设定规则运行到X=%x|Y=%y"
    //% shim=MazeRobot::Move_to
    export function Move_to(x:number,y:number){
        return
    }
    
    //% block="按照记录的路径前进"
    //% shim=MazeRobot::Go_Path
    export function Go_Path(){
        return
    }
    
    //% block="贴墙前进%n格长度"
    //% shim=MazeRobot::Go_Distance
    export function Go_Distance(n:number){
        return
    }

    export enum TURNS{
        //% block="右转90°"
        RIGHT_90=1,
        //% block="左转90°"
        LEFT_90=2,
        //% block="掉头180°"
        TURN_180=3,
        //% block="直行"
        GO_STRAIGHT=0
    }

    //% block="原地%turn"
    //% shim=MazeRobot::Turn
    export function Turn(turn:TURNS){

    }

    export enum DIR{
        //% block="上"
        UP,
        //% block="下"
        DOWN=2,
        //% block="左"
        LEFT=3,
        //% block="右"
        RIGHT=1
    }

    //% block="设定当前位置为X=%x|Y=%y|面朝方向%dir"
    //% shim=MazeRobot::Set_Pos
    export function Set_Pos(x:number,y:number,dir:DIR){
        return
    }
    
    //% block="按照字符串前进%path"
    export function Go_Path_Custom(path:string){
        let cmd=pins.createBuffer(2);
        cmd[0]=7;
        cmd[1]=path.length;
        pins.i2cWriteBuffer(0x70,cmd,false);
        let buf=pins.createBuffer(path.length);
        for(let i=0;i<path.length;i++){
            buf[i]=path.charCodeAt(i);
            // console.log(buf[i].toString());
        }
        basic.pause(10);
        pins.i2cWriteBuffer(0x70,buf,false);
        basic.pause(100);
        while(1){
            pins.i2cWriteNumber(0x70,0,NumberFormat.UInt16LE,false);
            basic.pause(10);
            if(pins.i2cReadNumber(0x70,NumberFormat.UInt8LE,false)==1)
                break;
            basic.pause(500);
        }
        return
    }
    
    //% block="平行校准"
    //% shim=MazeRobot::Paraller_Correct
    export function Paraller_Correct(){
        return
    }
    
    //% block="前后校准"
    //% shim=MazeRobot::FB_Correct
    export function FB_Correct(){
        return
    }

    export enum Regular{
        //% block="靠左墙"
        FOLLOW_LEFT,
        //% block="靠右墙"
        FOLLOW_RIGHT,
        //% block="自定义"
        CUSTOM
    }

    //% block="设定选方向规则为%regular"
    //% shim=MazeRobot::Set_Regular
    export function Set_Regular(regular:Regular){
        return
    }

    //% block="发送传感器数据"
    //% shim=MazeRobot::Get_Sensor_Data
    export function Get_Sensor_Data(){
        return
    }

    export enum Sensor_ID{
        //% block="左前"
        LEFT_FRONT,
        //% block="左后"
        LEFT_REAR,
        //% block="右前"
        RIGHT_FRONT,
        //% block="右后"
        RIGHT_REAR,
        //% block="正前"
        MID_FRONT,
    }
    
    //% shim=MazeRobot::Set_Param
    //% block="设置控制参数 %param | %value" 
    //% value.defl=175
    export function Set_Param(param:Param,value:number) {
        return
    }   
    
}
