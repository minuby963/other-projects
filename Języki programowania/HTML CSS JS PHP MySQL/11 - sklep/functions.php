
<?php

define('SESSION_COOKIE', 'cookieshop');
define('SESSION_ID_LENGHT', 40);
define('SESSION_COOKIE_EXPIRE', 3600);


function getProductImages($index){
	$images = array();

	//H001-x
	for($i=1; $i<10; $i++){
		
		$file_name = $index."-".$i.".jpg";
		$file_path = "photos/$file_name";
		if(file_exists($file_path)){
			//echo $file_path;
			$images[] = $file_name;
		}
	}
	return $images;
}


function showMenu(){
	global $pdo, $session;

	$stmt = $pdo->prepare("SELECT * FROM categories");
	$stmt -> execute();

	echo"<a href='index.php'>Strona Główna</a>";
	echo "</br>";
	
	while($row = $stmt -> fetch(PDO::FETCH_ASSOC)){
		$name =  $row['name'];
		$id = $row['id'];
		echo "<a href='index.php?cat_id=$id'>$name</a>";
		echo "<br />";
	}
	echo "<br />";
	echo "<a href='showCart.php'>koszyk</a>";
	echo "<br />";
	echo "<a href='admin.php'>Panel admina</a><br />";//ZMIANA NAZWY I NIE UMIESZCZANIE NA GŁÓWNEJ STRONIE TEGOŻ LINKU//
	if(!$session->getUser()->isAnonymous()){
		echo "<a href='logout.php'>Wyloguj</a><br />";
	}

	


}

function random_session_id(){
	$utime = time();
	$id = random_salt(40 - strlen($utime)).$utime;
	return $id;
}

function random_salt($len){
	return random_text($len);
}

function random_text($len){
	$base = 'QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890';
	$max = strlen($base) - 1;
	$rstring = '';
	mt_srand((double)microtime()*1000000);
	while(strlen($rstring) < $len){
		$rstring.=$base[mt_rand(0,$max)];
	}
	return $rstring;
}

?>