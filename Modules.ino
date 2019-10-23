/**
 * @file Example_FETmod.ino
 * @brief FETモジュールをGR-SAKURA(Master)から使用する実装例
 * @author Yuki HONMA @ ProjectR
 * @date 2019/10/20
 */


#include <arduino.h>

#include "Sakura_modules.h"

// クラス実体：モジュールでの例を有効化 = 1 ，ポートでの例 = 0
#define INSTANCE_MODULE 1


// モジュール実体の例
#if INSTANCE_MODULE == 0


// モジュールとしてインスタンス化
// インスタンス化するのは派生クラスの方
S_Fets Module_S(&Serial1);


void setup(){

    Serial.begin(230400);

    // シリアル開始． Serial1.begin(115200); でも可能
    Module_S.begin(115200);
}

void loop(){
    delay(10);

    // Digital出力
    // 派生クラスは基底クラスのメンバを継承してるのでそのまま使う
    Module_S.write(1, Fets::Out1);

    // PWM出力
    Module_S.write(0.4, Fets::Out2);

    // センサ応答設定
    Module_S.sensorResponce(0, 0, Fets::Out3, Fets::In1);

    // センサ応答設定
    Module_S.sensorResponce(0, 1, Fets::Out4, Fets::In1);

    // 三角波出力
    Module_S.writeWave(Fets::Triangular, 2000, Fets::Out5);

    // センサ情報読み取り
    if(Module_S.getInputState(Fets::In3)){

        // Digital出力
        Module_S.write(1, Fets::Out7);

        // センサトリガー設定
        Module_S.sensorTrigger(0, 1, Fets::Out6, Fets::In2);
    }
    else{

        // Digital出力
        Module_S.write(0, Fets::Out6);

        // センサトリガー設定
        Module_S.sensorTrigger(0, 0, Fets::Out7, Fets::In2);
    }
}


// ポート実体の例
#else

#define FET_MOD_ID 0x90

// ポートごとに実体化
S_Fets Sorenoid1(&Serial1, FET_MOD_ID, Fets::Out1, Fets::In1);
S_Fets Sorenoid2(&Serial1, FET_MOD_ID, Fets::Out2, Fets::In1);
S_Fets Sorenoid3(&Serial1, FET_MOD_ID, Fets::Out3, Fets::In2);
S_Fets Sorenoid4(&Serial1, FET_MOD_ID, Fets::Out4, Fets::In3);
S_Fets Lamp(&Serial1, FET_MOD_ID, Fets::Out5);
S_Fets RedLamp(&Serial1, FET_MOD_ID, Fets::Out6);
S_Fets BlueLamp(&Serial1, FET_MOD_ID, Fets::Out7);

void setup(){
    Serial.begin(230400);

    // 通信開始
    Serial1.begin(115200);
}

void loop(){

    Serial.println(Sorenoid1.sensorResponce(0, 0));
    Sorenoid2.sensorResponce(0, 1);

    // 情報読み取りはどの実体でもよいが，別々の実体で何回も呼び出さないほうが良い
    if(Sorenoid3.getInputState(Fets::In1)){
        Sorenoid3.sensorTrigger(0, 1);
        Sorenoid4.sensorTrigger(0, 1);
    }
    else{
        Sorenoid3.write(0);
        Sorenoid4.write(0);
    }

    Lamp.writeWave(Fets::InvSawtooth, 5000);
    RedLamp.writeWave(Fets::Square, 500);
    BlueLamp.write(1);

    delay(10);
}

#endif