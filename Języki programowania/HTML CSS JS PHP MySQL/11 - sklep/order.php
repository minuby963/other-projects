<?php
require('header.php');
?>


<h1>Podaj dane</h1>
<form action='orderSummary.php' method='post'>
	Imię i nazwisko: <input type='text' name='customer'></br>
	E-mail: <input type='text' name='email'></br>
	Adres: <textarea name='address'>
	
	</textarea></br>
	<input type='submit' value='zamawiam!'>
</form>

<?php
require('footer.php');
?>



