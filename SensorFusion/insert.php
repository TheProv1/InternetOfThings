<?php
date_default_timezone_set("Asia/Kolkata");
$host = "localhost";
$user = "iot_user";
$pass = "iot@1122";
$db = "iot_exam";

$con = mysqli_connect($host,$user,$pass,$db);
if($con){
 if(isset($_GET['h']) && isset($_GET['tc']) && isset($_GET['tf']) && isset($_GET['g']) && isset($_GET['f']) && isset($_GET['i']))
 {
 // echo "Connection Success";
 $hum = $_GET['h'];
 $tempc = $_GET['tc'];
 $tempf = $_GET['tf'];
 $date = date("d-m-Y");    // 06-01-2022
 $time = date("H:i:s");
 $gas = $_GET['g'];
 $flame = $_GET['f'];
 $ir = $_GET['i'];

 $sql = "insert into sensor_data(Date, Time, Hum, TempC, TempF, Flame, IR, Gas) values('$date','$time','$hum','$tempc', '$tempf', '$flame', '$ir', '$gas')";
 if(mysqli_query($con,$sql)){
  echo "Data Inserted";
 }
 else{
  echo "Failed to Insert Data";
 }
 }
 else{
  echo "No data";
 }
}
else{
 echo "Connection Failed";
}
?>