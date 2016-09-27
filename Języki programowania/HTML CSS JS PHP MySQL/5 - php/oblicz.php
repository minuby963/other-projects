<!DOCTYPE HTML>
<html lang="pl">
	<head>
		<meta charset="utf-8" />
		<title>wynik</title>
	</head>
	<body>
<?php
	$liczba1 = $_POST["liczba1"];
	$liczba2 = $_POST["liczba2"];
			
	echo "$liczba1".","."$liczba2<br /><br />";
	$wynik = $liczba1*$liczba2*10;
	echo "wynik="."$wynik";
			
			
echo<<<END
			
	<h2>WYNIK</h2>
	<table border="1" cellpadding="10" cellspacing="0">
		<tr>
			<td>liczba1</td><td>$liczba1</td>
		</tr>
			<tr>
			<td>liczba2</td><td>$liczba2</td>
		</tr>
			<tr>
			<td>WYNIK</td><td>$wynik</td>
		</tr>
	</table>	
END;
	echo '<br /><a href="index.php">Strona główna</a>';
			
?>
		
	</body>
</html>