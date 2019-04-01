<?php

#data recieved from ESP8266
$var1 = $_GET['data1'];
$var2 = $_GET['data2'];

$dataFile = 'test_data.txt'; # file that data gets stored in
date_default_timezone_set('America/Los_Angeles');

$coinbasePublicAPI = 'https://api.coinmarketcap.com/v1/ticker/';
$coinData = file_get_contents($coinbasePublicAPI);
$coinData = json_decode($coinData, true);
$coin_type = 4; #coin type 4 is LTC

$date = date('m/d/Y h:i:s a', time());

$fileContent = $date.", ".$var1.", ".$var2.", ".$coinData[$coin_type]['symbol'].": ".$coinData[$coin_type]['price_usd'];

#echo $fileContent;

$fileStatus = file_put_contents($dataFile, $fileContent, FILE_APPEND);

if($fileStatus){
        echo "SUCCESS: Data written to file";
}
else{
        echo "FAIL: Data not written to file";
}

?>