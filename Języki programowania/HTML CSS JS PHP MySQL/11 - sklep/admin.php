<?php
require('header.php');
?>


<?php
if($session->getUser()->isanonymous()){
	require('login.php');
}
else{
	if($session->getUser()->isAdministrator()){
		echo "Jesteś Adminem!";
		echo "<br /><a href='addProducts.php'>Dodaj produkt</a>";
	}
}

?>

<?php
require('footer.php');
?>



