<!DOCTYPE html>
<html>
<head>
<meta http-equiv="refresh" content="5">
<title>Page Title</title>
</head>
<body>
<center>
<table border = "1" width="100%" cellspacing='0'>

<tr>
<th>ID</th>
<th>Date</th>
<th>Time</th>
<th>Humidity</th>
<th>TemperatureC</th>
<th>TemperatureF</th>
<th>Flame</th>
<th>IR</th>
<th>Gas</th>
</tr>

<?php
$host = "localhost";
$user = "iot_user";
$pass = "iot@1122";
$db = "iot_exam";
$con = mysqli_connect($host,$user,$pass,$db);
$sql = "select * from sensor_data order by id desc";
$result = mysqli_query($con,$sql);
while($row = mysqli_fetch_array($result)){
 echo "<tr>";
 echo "<td>".$row['ID']."</td>";
 echo "<td>".$row['Date']."</td>";
 echo "<td>".$row['Time']."</td>";
 echo "<td>".$row['Hum']."</td>";
 echo "<td>".$row['TempC']."</td>";
 echo "<td>".$row['TempF']."</td>";
 echo "<td>".$row['Flame']."</td>";
 echo "<td>".$row['IR']."</td>";
 echo "<td>".$row['Gas']."</td>";
 echo "</tr>";
}
?>
</table>
</center>
</body>
</html>
