

<?php
require('header.php');
?>



<?php
function showProduct($id){
	global $pdo;
	
	$stmt = $pdo->prepare("SELECT * FROM products WHERE id = :id");
	$stmt->bindValue(':id', $id, PDO::PARAM_INT);
	$stmt->execute();

	while($row = $stmt -> fetch(PDO::FETCH_ASSOC)){
		$name = $row['name'];

		echo "<h2>".$name."</h2>";
		echo "<h3>".$row['net_price']."</h3>";

		$index = $row['product_index'];
		$category_id = $row['category_id'];
		foreach (getProductImages($index) as $image) {
			echo "<a data-lightbox='category' href='photos/$image' data-title='$name'>";
			echo "<img src='photos/thumbs/$image' >";
			echo "</a>";
			//echo "<a href='photos/$image' data-lightbox='a'><img src='photos/thumbs/$image'></a>";
			//echo "<a href='photos/$image' data-lightbox='image-1' data-title='My caption'>";
			//echo "Image #1";
			//echo "</a>";
			echo "</br>";
		}
		$id = $row['id'];
		echo "<a href='addToCart.php?id=$id'>Dodaj do koszyka</a></br></br>";
		echo $row['description'];
		//var_dump($row);

	
	}
}


if(isset($_GET['product_id'])){
	echo "<script src='dist/js/lightbox-plus-jquery.js'></script>";
	echo "<div class='product'>";
		showProduct($_GET['product_id']);
	echo "</div>";
}
?>


<?php
	require('footer.php');
?>