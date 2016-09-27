


<?php
require('header.php');

function showCategory($category_id=null){
	global $pdo;

	if($category_id){
		$stmt = $pdo->prepare("SELECT * FROM products WHERE category_id = :cid");
		$stmt -> bindValue(':cid',$category_id,PDO::PARAM_INT);
		$stmt -> execute();
	}
	else{
		$stmt = $pdo->prepare("SELECT * FROM products");
		$stmt -> execute();
	}
	while($row = $stmt -> fetch(PDO::FETCH_ASSOC)){
			$name = $row['name'];
			$index = $row['product_index'];
			$category_id = $row['category_id'];

			$id = $row["id"];



			
			$images = getProductImages($index);//-----IN FUNCTIONS-----//
			if(!empty($images)){
				$image = $images[0];
			}
			else{
				$image = 'no-photo.jpg';
			}
			
			echo "<div class='products'>";
				//-----IMAGE-----//
				echo "<a data-lightbox='category' href='photos/$image' data-title='$name'>";
					echo "<img src='photos/thumbs/$image' >";
				echo "</a>";
				//echo "</br>";
			
				//-----NAME AND PRICE-----//
				echo "<div class='nameAndPrice'>";
					echo "<a href='product.php?product_id=$id'>";
						echo "<h2>".$name."</h2>";
					echo "</a>";

					echo "<h3>".$row['net_price']." zł</h3>";
				echo "</div>";
			echo "</div>";

			//echo $row['description'];
			//var_dump($row);

		}
}


if(isset($_GET['cat_id'])){
	$category_id = $_GET['cat_id'];
}
else{
	$category_id=null;
}

echo "<script src='dist/js/lightbox-plus-jquery.js'></script>";
echo "<div class='container'>";
	showCategory($category_id);
echo "</div>";

require('footer.php');

?>

</body>
<html>