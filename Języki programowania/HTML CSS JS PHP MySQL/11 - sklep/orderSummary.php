<?php
require('header.php');
?>

<?php
//Save cart to DB 
$customer = $_POST['customer'];/////////////////////////////////////////////////validacja zmiennych+pobieranie email
$address = $_POST['address'];
$email = $_POST['email'];

$stmt = $pdo->prepare("INSERT INTO orders (id, customer, address, email) VALUES (null, :customer, :address, :email)");
$stmt->bindValue(':customer', $customer, PDO::PARAM_STR);
$stmt->bindValue(':address', $address, PDO::PARAM_STR);
$stmt->bindValue(':email', $email, PDO::PARAM_STR);
$stmt->execute();

$orderId = $pdo->lastInsertId();

$orderedProducts = $cart->getProducts();

foreach($orderedProducts as $product){
	$pid = $product['pid'];
	$qty = $product['quantity'];
	$stmt = $pdo->prepare("INSERT INTO ordersproducts (id, order_id, product_id, quantity) VALUES (null, :orderId, :pid, :qty)");
	$stmt->bindValue(':orderId', $orderId, PDO::PARAM_INT);
	$stmt->bindValue(':pid', $pid, PDO::PARAM_INT);
	$stmt->bindValue(':qty', $qty, PDO::PARAM_INT);
	$stmt->execute();
}
$cart->clear();



$headers = 'From: shop@example.com' . "\r\n" .
    'Reply-To: webmaster@example.com' . "\r\n" .
    'X-Mailer: Owner/';
//Send e-mail
mail($email, "Zamówienie numer $orderId", "Potwierdzamy złożenie zamówienia", $headers)

?>
<h1>Twoje zamówienie zostało zrealizowane!</h1>

<?php
require('footer.php');
?>