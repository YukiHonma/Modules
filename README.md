# Master using Modules library API


## 概要
モジュールを使用するライブラリ
 1. FETモジュール
  - FETモジュール 主機能の抽象クラス Fets
  - FETモジュール GR-SAKURA用の実装クラス S_Fets
 2. 足回りモジュール
  - 足回りモジュール 主機能の抽象クラス UnderBody
  - 足回りモジュール GR-SAKURA用の実装クラス S_UnderBody

 リポジトリ : https://github.com/YukiHonma/Modules.git
  
  
## ファイル構成
それぞれの詳細については各ファイル，またはDoxygen生成ドキュメントを参照
 - README.md
 - Modules.ino
 - Fets.h
 - Fets.cpp
 - UnderBody.h
 - UnderBody.cpp
 - Sakura_modules.h
 - Sakura_modules.cpp  
  
  
## 利用例
 各クラスの説明に使用例を掲載している．  
 複数のモジュールを使用する例を Modules.ino ファイルに記載する．

  
## マスターとの通信/複数モジュール
 マスター対モジュールでの通信においてマルチスレーブ化が可能である．  
 ただし，Uartシリアル通信を用いる場合，モジュールからマスターへの通信ができるのは1モジュールのみである．  
 モジュール側のDIPスイッチと内部ファイルのIDを設定する必要がある．  

 また種類の違う複数のモジュールでもマルチスレーブ化ができるようにする．
 注意事項は上と同じ  


## 他モジュールライブラリ
 Fets.h にFETモジュール操作の抽象クラスを作り， Sakura_modules.h にGR-SAKURA実装用の拡張クラスを作っている．  
 今後モジュールを開発していくに当たり，抽象クラスは別ファイル，GR-SAKURA実装用の拡張クラスは Sakura_modules.h に入れようと考えている．
