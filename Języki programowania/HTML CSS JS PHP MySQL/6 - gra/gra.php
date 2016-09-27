<?php
	session_start();
	if(!isset($_SESSION['zalogowany']))
	{
		header('Location: index.php');
		exit();
	}
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

	
	echo $_SESSION['user']."&nbsp; &nbsp; &nbsp;";
	echo '<a href="logout.php">wyloguj się</a><br />';
	echo $_SESSION['drewno']."<br />";
	echo $_SESSION['kamien']."<br />";
	echo $_SESSION['zboze']."<br />";
	echo $_SESSION['email']."<br />";
	echo $_SESSION['dnipremium']."<br />";
	
?>


</body>
</html>