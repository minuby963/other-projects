<?php
require('header.php');
?>


<?php
	if($session -> getUser() -> isAnonymous()){
		$result = user::checkPasswords($_POST['login'], $_POST['password']);

		if($result instanceof user){
			//logged in
			$session->updateSession($result);
			//echo "Zalogowano: ".$session->getUser()->getLogin();
		}
		//else{
		header('Location: admin.php');
		//}
	}

?>

<?php
require('footer.php');
?>



