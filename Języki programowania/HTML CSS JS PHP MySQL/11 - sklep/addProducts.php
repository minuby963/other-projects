<?php
require('header.php');
?>


<?php
if($session->getUser()->isanonymous()){
	require('login.php');
}
else{
	if($session->getUser()->isAdministrator()){
		echo "<form action='doAddProduct.php' method='post'>";
		echo "Index: <input type='text' name='index'><br />";
		echo "Nazwa: <input type='text' name='name'><br />";
		echo "Cena Netto <input type='text' name='net_price'><br />";
		echo "Opis: <textarea name='description'></textarea><br />";

		$stmt = $pdo->prepare("SELECT * FROM categories");
		$stmt->execute();

		$rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
		echo "<select name='category'>";
		foreach($rows as $category){
			
			$id = $category['id'];
			$name = $category['name'];
			echo"Kategoria: <option value='$id'>$name</option>";
		}
		echo "</select>";
		echo "<input type='submit' value='Dodaj'>";

	}
}

?>

<?php
require('footer.php');
?>



