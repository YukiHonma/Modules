/**
 * @file Sakura_modules.h
 * @brief GR-SAKURA でFETモジュールを使用するための主機能の通信拡張
 * @author Yuki HONMA @ ProjectR
 * @date 2019/10/17
 */


#ifndef SAKURA_MODULES_H
#define SAKURA_MODULES_H

#include <Arduino.h>
#include "Fets.h"


/**
 * @brief FETモジュール操作機能の GR-SAKURA 実装用クラス
 *
 *
 * Fets クラスを継承した拡張クラス @n
 * Fets クラスのパブリックメンバをそのまま呼び出せる
 *
 * @note    GR-SAKURA のシリアル通信 HardwareSerial を使用して send() , recieve() メソッドをオーバーライドしている
 *
 */
class S_Fets : public Fets
{
public:

    /**
     * コンストラクタ
     *
     *
     * 引数はシリアル通信のポインタと基底クラスのコンストラクタ Fets::Fets() に渡す情報
     * 
     * @param _comm         モジュールとの通信に使用するハードウェアシリアルのポインタ
     * @param _id           モジュールのID 基底クラスにそのまま渡す @n
     * @param outputPort    使用する出力ポートの番号 基底クラスにそのまま渡す @n
     * @param inputPort     使用する入力ポートの番号 基底クラスにそのまま渡す @n
     *
     * @remarks             _id , outputPort , inputPort について詳細は基底クラス Fets::Fets() に記述してある
     *
     */
    S_Fets(HardwareSerial *_comm, char _id = DEF_ID, Fets::portNum outputPort = Fets::None, Fets::portNum inputPort = Fets::None);

    /**
     * シリアル通信を開始する
     *
     * Serial_.begin() と同義
     * 
     * @param baudrate      ボーレート
     *
     * @note        シリアルの実体でbeginしてもよい
     * @attention   マルチスレーブ接続のため複数のモジュールで同一のシリアル通信バスを使用する場合，シリアルの実体でbeginしたほうがよい
     */
    void begin(int baudrate = 115200);

protected:

    /**
     * シリアル通信での送信メソッド @n
     * 外部呼び出しはされない
     *
     * @param data  送信するデータ(1byte)
     */
    void send(char data); //override

    /**
     * シリアル通信での受信メソッド @n
     * 外部呼び出しはされない
     *
     * @return @p -1 新規データなし
     * @return @p 0x00 ~ @p 0xFF 受信したデータ
     */
    int recieve(); //override

private:

    HardwareSerial *comm;
};


#endif