#シリアル通信用コード片

#シリアル通信開始。※デバッグ的な感じでarduinoのシリアルウィンドウを出してるとエラーになるので注意
$port = New-Object IO.Ports.SerialPort("COM3")
$port.PortName= "COM3" #//ポート名
$port.BaudRate = 9600 #//ボーレート
$port.DataBits = 8 #//データビット
$port.StopBits = 1 #//ストップビット
$port.Parity = Parity.Even #//パリティ
$port.Handshake = Handshake.None; #//ハンドシェイク
$port.ReadTimeout = 30000
$port.WriteTimeout = 30000
$port.Open()


#buff用にchar型(4096)固定長の配列を作る方法
$buff = new-object System.char[] 4096

#読み取り方法色々
$port.Read($buff,0,4096) #$buff の 0番目から 最大4096文字まで読み込み
$port.ReadLine() #１行読み取り。これが細かいことやらないなら一番楽そう
$port.ReadExisting() #全部読み取り
[char]$port.ReadChar() #一文字読み取り