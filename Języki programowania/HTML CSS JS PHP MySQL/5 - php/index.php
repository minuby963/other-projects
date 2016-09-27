<!DOCTYPE HTML>
<html lang="pl">
	<head>
		<meta charset="utf-8" />
		<title>php</title>
	</head>
	<body>
		<?php
			$imie = "napis";
		
			echo "Hello World!";
			echo "$imie, tekst"; 
			echo '<img src="obraz.jpg" />'.$imie;	
		?>
		<br /><br />
		
		<form action="oblicz.php" method="post">
			obliczanie (liczba1*liczba2*10):<br /><br />
			<input type="text" name="liczba1" />
			<br /><br />
			<input type="text" name="liczba2" />
			<br /><br />
			<input type="submit" value="policz" />
		</form>
		
	</body>
</html>