# Master using Modules library API
TUT ProjectR

## 概要
FETモジュールをSlaveに置く，Masterに使うライブラリ
 - 主機能の抽象クラス Fets
 - GR-SAKURA用の実装クラス S_Fets

 リポジトリ : https://github.com/YukiHonma/Master_Module-Sorenoid.git  
  
  
## ファイル構成
それぞれの詳細については各ファイル，またはDoxygen生成ドキュメントを参照
 - README.md
 - Modules.ino
 - Fets.h
 - Fets.cpp
 - Sakura_modules.h
 - Sakura_modules.cpp  
  
  
## 利用例
 実行ファイル Modules.ino にGR-SAKURAでの実装例を示している．  
 ソースファイル自体にコメントを入れている．  
 2種類の実装を行い，マクロでどちらを実行するか変更できる．

 GR-SAKURAを使用するならば S_Fets でクラスを実体化する．  
 機能は Fets の公開メソッドを使用する． S_Fets は Fets を継承しているため， Fets のメンバを使用できる．
 S_Fets 独自のメンバでユーザが使用しうるのは S_Fets::begin() のみである．

 念の為書いておくが Fets クラスは抽象クラスであり，いかなるマイコンにおいてもC++対応ならば使用できることを念頭に機能を揃えている．単体では動作しない．  
 S_Fets クラスでGR-SAKURA専用としてハードウェア依存となる通信部分にHardwareSerial関連を実装して拡張している．  
  
  
## マスターとの通信/複数モジュール・他モジュール
 マスター対モジュールでの通信においてマルチスレーブ化が可能である．  
 ただし，Uartシリアル通信を用いる場合，モジュールからマスターへの通信ができるのは1モジュールのみである．  
 モジュール側のDIPスイッチと内部ファイルのIDをを設定をする必要がある．  

 またFETモジュール以外の他出力モジュールでもマルチスレーブ化ができるようにする予定．
 注意事項は上と同じ  


## 他モジュールライブラリ
 Fets.h にFETモジュール操作の抽象クラスを作り， Sakura_modules.h にGR-SAKURA実装用の拡張クラスを作っている．  
 今後モジュールを開発していくに当たり，抽象クラスは別ファイル，GR-SAKURA実装用の拡張クラスは Sakura_modules.h に入れようと考えている．