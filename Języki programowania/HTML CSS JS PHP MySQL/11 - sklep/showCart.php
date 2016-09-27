<?php
require('header.php');
?>

<?php

	$inCart = $cart->getProducts();
	//var_dump($inCart);
	if(!empty($inCart)){
		$price = 0;
		foreach($inCart as $product){
			$productCartId = $product['id'];
			$net_price = $product['net_price'];
			$quantity = $product['quantity'];
			$index = $product['product_index'];
			$name = $product['name'];

			$id = $product['pid'];
			$price = $price + $quantity * $net_price;
			echo "<div class='productInCart'>";
			echo "$name $net_price $index ".$quantity * $net_price;//." <a href='remFromCart.php?id=$productCartId'>usuń</a>";
			echo "<a href='addToCart.php?id=$id'>plus</a>";
			echo "<a href='remFromCart.php?id=$id'>minus</a>";


			echo "</div>";

		}
		echo "Cena Twoich zakupów: $price";
		echo "<a href='order.php'>Złóż zamówienie</a>";
	}
	else{
		echo "Koszyk jest pusty!";
	}
	
?>


<?php
require('footer.php');
?>



