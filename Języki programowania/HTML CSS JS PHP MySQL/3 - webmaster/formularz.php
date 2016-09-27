<!DOCTYPE HTML>
<html lang="pl">
	<head>
		<meta charset="utf-8"/>
		<title>Portfolio</title>
		<meta name="description" content="description"/>
		<meta name="keywords" content="keywords"/>
		<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
		<link rel="stylesheet" href="style.css" type="text/css" />
		<link href='https://fonts.googleapis.com/css?family=Lato:400,700,900&subset=latin,latin-ext' rel='stylesheet' type='text/css'>
		<link href='https://fonts.googleapis.com/css?family=Josefin+Sans:400,700,600&subset=latin,latin-ext' rel='stylesheet' type='text/css'>
		<link rel="stylesheet" href="css/fontello.css" type="text/css" />
		
		<script type="text/javascript" src="czas.js"></script>
		
	</head>
	<body onload="odswiez_czas();">
	
	
	
			<a href="programista-webowy-portfolio">
				<div class="logo">
					<div id="name">DANIEL STEFANIK</div>
					
					<div id="clock"></div>

					<div style="clear: both;"/>
				</div>
			</a>
			<div style="clear: both; margin: 0; padding: 0;"/>
			<div class="menu">
			
				<a href="programista-stron-internetowych.html">
					<div id="rect1">
						<i class="icon-user-1"></i> 
						O mnie
					</div>
				</a>
				
				<a href="http://youtube.com" target="_blank">
					<div  id="rect2"><i class="icon-youtube-squared"></i> </div>
				</a>
				
				<a href="oferta-html-php-css-javascript">
					<div  id="rect3">
						<i class="icon-globe"></i> 
						Oferuję
					</div>
				</a>
				
				<a href="http://facebook.com" target="_blank">
					<div  id="rect4"><i class="icon-facebook-official"></i> </div>
				</a>
				
				<a href="cv-curriculum-vitae-programista-informatyk">
					<div  id="rect5">
						<i class="icon-check"></i> 
						CV
					</div>
				</a>
				
				<a href="https://plus.google.com/u/0/" target="_blank">
					<div  id="rect6"><i class="icon-gplus"></i> </div>
				</a>
				
				<a href="programista-kontakt">
					<div  id="rect7">
						<i class="icon-mail-1"></i> 
						<div style="height: 7px;"></div>
						Kontakt
					</div>
				</a>
				<div style="clear: both;"></div>
			</div>	
			<div id="content">
			</div>
			<div id="footer">
				&copy; Daniel Stefanik - Portfolo 2016. Wszelkie prawa zastrzeżone.
			</div>

			
			
			

		<script src="jquery-1.12.0.js"></script>
		<script>
			$(document).ready(function() {
				var NavY = $('.menu').offset().top;
				 
				var stickyNav = function(){
					var ScrollY = $(window).scrollTop();
						  
					if (ScrollY > NavY) { 
						$('.menu').addClass('sticky');
					} else {
						$('.menu').removeClass('sticky'); 
					}
				};
					 
				stickyNav();
					 
				$(window).scroll(function() {
					stickyNav();
				});
			});
		</script>
	</body>
</html>