
<!DOCTYPE HTML>
<html lang="pl">
<head>
		<meta charset="utf-8"/>
		<title>menu</title>
		<meta name="description" content="description"/>
		<meta name="keywords" content="keywords"/>
		<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
		<link rel="stylesheet" href="style.css" type="text/css" />
		<link rel="stylesheet" href="dist/css/lightbox.min.css" type="text/css" />
</head>



<?php

echo "<script src='dist/js/lightbox-plus-jquery.js'></script>";

require('functions.php');

require('sessions.php');
require('request.php');
require('user.php');

require('cart.php');


$pdo = new PDO('mysql:host=localhost;port=3306;dbname=sklep','root','');
$pdo -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$pdo -> exec("SET NAMES 'utf8'");


$request = new userRequest();
$session = new session();
$cart = new cart();

//$stmt = $pdo->prepare("SELECT * FROM products");
//$stmt -> execute();


?>

<div class="content">
	<div class="menu">
		<?php showMenu(); ?>
	</div>
</div>

</body>
