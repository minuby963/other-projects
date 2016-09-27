<?php
	session_start();
?>
<!DOCTYPE HTML>
<html lang="pl">
<head>
		<meta charset="utf-8"/>
		<title>menu</title>
		<meta name="description" content="description"/>
		<meta name="keywords" content="keywords"/>
		<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
</head>
<body>
<?php
	if(isset($_SESSION['zalogowany']) && ($_SESSION['zalogowany']==true))
	{
		header('Location: gra.php');
		exit();
	}
?>
	<form action="zaloguj.php" method="post">
		<br /><br />
		login: 
		<input type="text" name="login"><br />
		hasło:
		<input type="password" name="haslo"><br />
		<input type="submit" value="zaloguj się" />
	</form>

<?php
	if(isset($_SESSION['blad']))
	{
		echo $_SESSION['blad'];
	}

?>
</body>
<html>