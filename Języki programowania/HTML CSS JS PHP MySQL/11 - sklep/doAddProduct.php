<?php
require('header.php');
?>


<?php
if($session->getUser()->isanonymous()){
	require('login.php');
}
else{
	if($session->getUser()->isAdministrator()){

		$index = $_POST['index'];
		$name = $_POST['name'];
		$net_price = $_POST['net_price'];
		$description = $_POST['description'];
		$category_id = $_POST['category'];


		//save to DB


		$stmt = $pdo->prepare('INSERT INTO products (id, product_index, name, net_price, description, category_id) VALUES (null, :product_index, :name, :net_price, :description, :category_id)');
		$stmt->bindValue(':product_index', $index, PDO::PARAM_INT);
		$stmt->bindValue(':name', $name, PDO::PARAM_STR);
		$stmt->bindValue(':net_price', $net_price, PDO::PARAM_STR);
		$stmt->bindValue(':description', $description, PDO::PARAM_STR);
		$stmt->bindValue(':category_id', $category_id, PDO::PARAM_INT);
		$stmt->execute();

		header('Location: admin.php');

	}
}

?>

<?php
require('footer.php');
?>



